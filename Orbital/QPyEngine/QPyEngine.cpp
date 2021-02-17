#include <cstdlib>
#include <cstring>
#include <regex>
#include "QPyEngine.h"
#include "QPyEngineUtils.h"
#include <QFileInfo>

QPYENGINE_NAMESPACE_BEGIN

static QPyEngineCore* core = Q_NULLPTR;
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
	QPYENGINE_MODULENAME,
	NULL,
	-1,
	NULL,
	NULL, NULL, NULL, NULL
};
#define QPyMethodTable pyModule.m_methods
PyMODINIT_FUNC PyInit()
{
	return PyModule_Create(&pyModule);
}

/*
** Initializes the Python engine (requires Python 3.7+).
*/
void
Init(QObject* parent)
{
	std::cmatch cm;
	int pyVersion_maj;
	int pyVersion_min;

	/* Ensure the interpreter is NOT initialized and the minimum required version is being used (required by certain API functions). */
	if (Py_IsInitialized())
		throw std::runtime_error("ERROR::PYENGINE: Python already initialized");
	if (!std::regex_match(Py_GetVersion(), cm, std::regex("^(\\d+)\\.(\\d+).*$")))
		throw std::runtime_error("ERROR::PYENGINE: Error parsing Python version");
	pyVersion_maj = atoi(cm[1].str().c_str());
	pyVersion_min = atoi(cm[2].str().c_str());
	if (pyVersion_maj < QPYENGINE_PY_MAJOR_VER || (pyVersion_maj == QPYENGINE_PY_MAJOR_VER && pyVersion_min < QPYENGINE_PY_MINOR_VER))
		throw std::runtime_error("ERROR::PYENGINE: Python version 3.7+ required");

	/* Append NULL PyMethodDef to end of module methods. */
	RegisterMethod(NullMethod);

	/* Add module to the table of build-in modules. */
	if (PyImport_AppendInittab(QPYENGINE_MODULENAME, PyInit) == -1)
		throw std::runtime_error("ERROR::PYENGINE: PyImport_AppendInittab failed");

	/* Initialize the interpreter. */
	Py_InitializeEx(1);
	if (PyEval_ThreadsInitialized() == 0)
		throw std::runtime_error("ERROR::PYENGINE: PyEval_ThreadsInitialized failed");

	core = new QPyEngineCore(parent);
}

/*
** Deinitialize the Python engine.
*/
void
DeInit() noexcept
{
	delete core;
	Py_FinalizeEx();
	free(QPyMethodTable);
	methodCount = 0;
}

/*
** Registers a method with the Python engine (must be done before initialization).
*/
void
RegisterMethod(const PyMethodDef& pyMethod)
{
	PyMethodDef* mTable;

	if (Py_IsInitialized())
		throw std::runtime_error("ERROR::PYENGINE: Python already initialized");
	if ((mTable = (PyMethodDef*)realloc(QPyMethodTable, (methodCount + 1) * sizeof(PyMethodDef))) == NULL)
		throw std::runtime_error("ERROR::SYSTEM: Memory allocation failure");

	memcpy(&mTable[methodCount++], &pyMethod, sizeof(PyMethodDef));
	QPyMethodTable = mTable;
}

/*
** Registers multiple methods with the Python engine (must be done before initialization).
*/
void
RegisterMethods(const PyMethodDef* pyMethods, size_t n)
{
	PyMethodDef* mTable;

	if (Py_IsInitialized())
		throw std::runtime_error("ERROR::PYENGINE: Python already initialized");
	if (pyMethods == NULL || n == 0)
		return;
	if ((mTable = (PyMethodDef *)realloc(QPyMethodTable, (methodCount + n) * sizeof(PyMethodDef))) == NULL)
		throw std::runtime_error("ERROR::SYSTEM: Memory allocation failure");

	memcpy(&mTable[methodCount], pyMethods, n * sizeof(PyMethodDef));
	methodCount += n;
	QPyMethodTable = mTable;
}

/*
** Appends to the Python system path variable.
*/
void
AppendPythonPath(const std::string& path)
{
	if (!Py_IsInitialized())
		throw std::runtime_error("ERROR::PYENGINE: Python not initialized");

	core->Lock();
	AppendSystemPath(path.c_str());
	core->Unlock();
}

Module::Module(const char* moduleFile) : QObject(QPyEngine::core), core(QPyEngine::core), module(NULL)
{
	QFileInfo file(moduleFile);

	if (!Py_IsInitialized())
		throw std::runtime_error("PYENGINE ERROR: Python has not been initialized");

	this->core->Lock();
	AppendSystemPath(file.absolutePath().toStdString().c_str());
	this->name = PyUnicode_DecodeFSDefault(file.baseName().toStdString().c_str());
	this->core->Unlock();

	QObject::connect(this, &Module::Signal_FnEnd, this->core, &QPyEngineCore::Slot_FnEnd);
}

Module::~Module()
{
	this->core->Lock();
	Py_DECREF(this->name);
	if (this->module != NULL)
		Py_DECREF(this->module);
	this->core->Unlock();
}

/*
** Loads (imports) the module into the interpreter. This must be done prior to attempting to call
**   a function from the module or reloading the module.
** - If successful, returns 1.
** - If an error occurs, returns 0 and sets errStr to a description of the error.
*/
int
Module::Load(QString& errStr)
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

/*
** Reloads the module into the interpreter, allowing run-time changes to the module. A succesful 'Load' must
**   be called prior to calling this function.
** - If successful, returns 1.
** - If an error occurs, returns 0 and sets errStr to a description of the error.
*/
int
Module::Reload(QString& errStr)
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

/*
** Calls a function within the loaded module. A single argument is passed to the function (can be NULL). On return
**   of the function, any returned values are passed in to the callback function 'retFn' within the first argument.
**   If an error occurs within the function (executed by the interpreter), a description of the error is passed
*/
int Module::CallFn(const char* fnName, PyObject* args, QPyEngine_RetFn retFn, QString& errStr)
{
	PyObject* moduleFn = NULL;

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

	/* From this point on, the module function call is executed from a child thread. Any subsequent errors will be reported by the
		 callback function. */
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

/*
** Child thread module function call. Each call to a module function executes within a newly created child thread.
**   The finalization routine is invoked by signalling 'Signal_FnEnd' with the returned object and the error status.
*/
void Module::Call(PyObject* func, PyObject* args, QPyEngine_RetFn retFn, PyInterpreterState* interpState)
{
	PyObject* ret = NULL;
	QString errStr;
	PyThreadState* threadState;

	/* This thread currently has no thread state (the interpreter still has the main thread state loaded), so a new one
		 is created. This thread then acquires the GIL and sets the interpreter's thread state to the new one. */
	threadState = PyThreadState_New(interpState);
	PyEval_RestoreThread(threadState);

	if ((ret = PyObject_CallFunctionObjArgs(func, args, NULL)) == NULL) {
		ErrorReport(errStr);
	}
	Py_DECREF(func);
	Py_XDECREF(args);

	/* Reset the thread state object, release the GIL, and destroy the thread state object. After this point, no
		 further Python API function calls are to be executed within this thread. The results of the module function
		 will be processed within the main thread. */
	PyThreadState_Clear(threadState);
	PyEval_SaveThread();
	PyThreadState_Delete(threadState);

	this->core->PushThreadQueue(std::this_thread::get_id());

	emit Signal_FnEnd(ret, errStr, retFn);
}

QPYENGINE_NAMESPACE_END