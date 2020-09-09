#include <cstdlib>
#include <cstring>
#include <regex>
#include "PyEngine.h"
#include "QPyEngineUtils.h"
#include <QFileInfo>

#define PyVersion_MAJ 3
#define PyVersion_MIN 7

QPYENGINE_NAMESPACE_BEGIN

static QPyEngineCore * core = Q_NULLPTR;
static size_t methodCount = 0;
PyMethodDef NullMethod =
{
	NULL,
	NULL,
	0,
	NULL
};
PyModuleDef pyModule =
{
	PyModuleDef_HEAD_INIT,
	MODULENAME,
	NULL,
	-1,
	NULL,
	NULL, NULL, NULL, NULL
};
#define pyMethodTable pyModule.m_methods
PyMODINIT_FUNC PyInit()
{
	return PyModule_Create(&pyModule);
}

// Initializes the Python engine (requires Python 3.7+)
void Init(QObject * parent)
{
	std::cmatch cm;
	int pyVersion_maj;
	int pyVersion_min;

	if (Py_IsInitialized())
		throw std::runtime_error("PYENGINE ERROR: Python already initialized");
	if (!std::regex_match(Py_GetVersion(), cm, std::regex("^(\\d+)\\.(\\d+).*$")))
		throw std::runtime_error("PYENGINE ERROR: Error parsing Python version");
	pyVersion_maj = atoi(cm[1].str().c_str());
	pyVersion_min = atoi(cm[2].str().c_str());
	if (pyVersion_maj < PyVersion_MAJ || (pyVersion_maj == PyVersion_MAJ && pyVersion_min < PyVersion_MIN))
		throw std::runtime_error("PYENGINE ERROR: Python version 3.7+ required");
	RegisterMethod(NullMethod);
	if (PyImport_AppendInittab(MODULENAME, PyInit) == -1)
		throw std::runtime_error("PYENGINE ERROR: PyImport_AppendInittab failed");
	Py_InitializeEx(1);
	if (PyEval_ThreadsInitialized() == 0)
		throw std::runtime_error("PYENGINE ERROR: PyEval_ThreadsInitialized failed");

	core = new QPyEngineCore(parent);
}

void DeInit()
{
	if (!Py_IsInitialized())
		throw std::runtime_error("PYENGINE ERROR: Python not initialized");
	delete core;
	Py_FinalizeEx();
	free(pyMethodTable);
	methodCount = 0;
}

// Register a method with the Python engine (must be done before initialization)
void RegisterMethod(const PyMethodDef& pyMethod)
{
	PyMethodDef * mTable;

	if (Py_IsInitialized())
		throw std::runtime_error("PYENGINE ERROR: Python already initialized");
	if ((mTable = (PyMethodDef *)realloc(pyMethodTable, (methodCount + 1) * sizeof(PyMethodDef))) == NULL)
		throw std::runtime_error("SYSTEM ERROR: Memory allocation failure");

	memcpy(&mTable[methodCount++], &pyMethod, sizeof(PyMethodDef));
	pyMethodTable = mTable;
}

// Register multiple methods with the Python engine (must be done before initialization)
void RegisterMethods(const PyMethodDef * pyMethods, size_t n)
{
	PyMethodDef * mTable;

	if (Py_IsInitialized())
		throw std::runtime_error("PYENGINE ERROR: Python already initialized");
	if (pyMethods == NULL || n == 0)
		return;
	if ((mTable = (PyMethodDef *)realloc(pyMethodTable, (methodCount + n) * sizeof(PyMethodDef))) == NULL)
		throw std::runtime_error("SYSTEM ERROR: Memory allocation failure");

	memcpy(&mTable[methodCount], pyMethods, n * sizeof(PyMethodDef));
	methodCount += n;
	pyMethodTable = mTable;
}

// Appends to the Python system path variable
void AppendPythonPath(const std::string& path)
{
	if (!Py_IsInitialized())
		throw std::runtime_error("PYENGINE ERROR: Python not initialized");

	core->Lock();
	AppendSystemPath(path.c_str());
	core->Unlock();
}

Module::Module(const char * moduleFile) : QObject(PyEngine::core), core(PyEngine::core), module(NULL)
{
	QFileInfo file(moduleFile);

	if (!Py_IsInitialized())
		throw std::runtime_error("PYENGINE ERROR: Python has not been initialized");

	this->core->Lock();
	AppendSystemPath(file.absolutePath().toStdString().c_str());
	this->name = PyUnicode_DecodeFSDefault(file.baseName().toStdString().c_str());
	this->core->Unlock();

	QObject::connect(this, &Module::Signal_FuncEnd, this->core, &QPyEngineCore::Slot_FuncEnd);
}

Module::~Module()
{
	this->core->Lock();
	Py_DECREF(this->name);
	if (this->module != NULL)
		Py_DECREF(this->module);
	this->core->Unlock();
}

int Module::Load(QString& errStr)
{
	int retVal = 1;

	this->core->Lock();
	if (this->module != NULL)
		Py_DECREF(this->module);
	if ((this->module = PyImport_Import(this->name)) == NULL) {
		ErrorReport(errStr);
		retVal = 0;
	}
	this->core->Unlock();
	return retVal;
}

int Module::Reload(QString& errStr)
{
	int retVal = 1;

	if (this->module == NULL) {
		errStr = QString("No module loaded");
		return 0;
	}

	this->core->Lock();
	Py_DECREF(this->module);
	if ((this->module = PyImport_ReloadModule(this->module)) == NULL) {
		ErrorReport(errStr);
		retVal = 0;
	}
	this->core->Unlock();
	return retVal;
}

int Module::CallFunc(const char * fnName, PyObject * args, QPyEngine_RetFn retFn, QString& errStr)
{
	PyObject * moduleFn = NULL;

	if (this->module == NULL) {
		errStr = QString("No module loaded");
		return 0;
	}

	this->core->Lock();
	if ((moduleFn = PyObject_GetAttrString(this->module, fnName)) == NULL || !PyCallable_Check(moduleFn)) {
		Py_XDECREF(moduleFn);
		ErrorReport(errStr);
		PyErr_Clear();
		this->core->Unlock();
		return 0;
	}
	this->core->Unlock();

	this->core->threads.push_back(new std::thread(&Module::Call, this, moduleFn, args, retFn, this->core->mainThreadState->interp));
	return 1;
}

void Module::CoreLock()
{
	this->core->Lock();
}

void Module::CoreUnlock()
{
	this->core->Unlock();
}

void Module::Call(PyObject * func, PyObject * args, QPyEngine_RetFn retFn, PyInterpreterState * interpState)
{
	PyObject * ret = NULL;
	QString errStr;
	PyThreadState * threadState;

	threadState = PyThreadState_New(interpState);
	PyEval_RestoreThread(threadState);

	if ((ret = PyObject_CallFunctionObjArgs(func, args, NULL)) == NULL) {
		ErrorReport(errStr);
	}
	Py_DECREF(func);
	Py_XDECREF(args);

	PyThreadState_Clear(threadState);
	PyEval_SaveThread();
	PyThreadState_Delete(threadState);

	this->core->PushThreadQueue(std::this_thread::get_id());

	emit Signal_FuncEnd(ret, errStr, retFn);
}

QPYENGINE_NAMESPACE_END