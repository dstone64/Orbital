#include "QPyEngineCore.h"

QPYENGINE_NAMESPACE_BEGIN

QPyEngineCore::QPyEngineCore(QObject* parent)
	: QObject(parent)
{
	PyGILState_STATE gilState;
	if (!Py_IsInitialized())
		throw std::runtime_error("ERROR::QPYENGINECORE: Python not initialized");
	qRegisterMetaType<QPyEngine_RetFn>();
	gilState = PyGILState_Ensure();
	this->mainThreadState = PyThreadState_Get();
	PyGILState_Release(gilState);
}

QPyEngineCore::~QPyEngineCore()
{
}

/*
** Locks the GIL to the current thread.
*/
void QPyEngineCore::Lock()
{
	if (PyGILState_Check() == 0) {
		PyEval_RestoreThread(this->mainThreadState);
	}
}

/*
** Unlocks the GIL from the current thread.
*/
void QPyEngineCore::Unlock()
{
	if (PyGILState_Check() == 1) {
		this->mainThreadState = PyEval_SaveThread();
	}
}

/*
** Appends to the global thread queue. This queue is used by the engine core to manage each
**   active Python thread, specifically the clean-up of each thread.
*/
void QPyEngineCore::PushThreadQueue(std::thread::id& id)
{
	this->mtx.lock();
	this->threadQueue.push(id);
	this->mtx.unlock();
}

/*
** The slot for a module function call's finalization. This is signalled from a child thread and
**   is executed (here) in the main thread. The implementation uses Qt's signal queueing to ensure
**   that all finalized function calls will be dealt with in the case that a call completes before
**   finalization can be executed.
*/
void QPyEngineCore::Slot_FnEnd(PyObject* ret, QString errStr, QPyEngine_RetFn retFn)
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