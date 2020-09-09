#include "QPyEngineCore.h"

QPYENGINE_NAMESPACE_BEGIN

QPyEngineCore::QPyEngineCore(QObject * parent)
	: QObject(parent)
{
	PyGILState_STATE gilState;
	if (!Py_IsInitialized())
		throw std::runtime_error("QPYENGINECORE ERROR: Python not initialized");
	qRegisterMetaType<QPyEngine_RetFn>();
	gilState = PyGILState_Ensure();
	this->mainThreadState = PyThreadState_Get();
	PyGILState_Release(gilState);
}

QPyEngineCore::~QPyEngineCore()
{
}

void QPyEngineCore::Lock()
{
	if (PyGILState_Check() == 0) {
		PyEval_RestoreThread(this->mainThreadState);
	}
}

void QPyEngineCore::Unlock()
{
	if (PyGILState_Check() == 1) {
		this->mainThreadState = PyEval_SaveThread();
	}
}

void QPyEngineCore::PushThreadQueue(std::thread::id& id)
{
	this->mtx.lock();
	this->threadQueue.push(id);
	this->mtx.unlock();
}

void QPyEngineCore::Slot_FuncEnd(PyObject * ret, QString errStr, QPyEngine_RetFn retFn)
{
	this->mtx.lock();
	for (auto itr = this->threads.begin(); itr != this->threads.end(); ++itr) {
		if ((*itr)->get_id() == this->threadQueue.front()) {
			(*itr)->join();
			delete (*itr);
			this->threads.erase(itr);
			break;
		}
	}
	this->mtx.unlock();
	(*retFn)(ret, errStr);
}

QPYENGINE_NAMESPACE_END