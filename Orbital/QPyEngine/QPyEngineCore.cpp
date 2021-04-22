/******************************************************************************

	Copyright (C) 2020 by Dan Stone (danstone124@gmail.com)

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.If not, see < https://www.gnu.org/licenses/>.

******************************************************************************/

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
	std::scoped_lock lock(this->mtx);
	this->threadQueue.push(id);
}

/*
** The slot for a module function call's finalization. Signalled from a child thread and executed
**   here in the main thread. The implementation uses Qt's signal queueing to ensure that all
**   finalized function calls will be dealt with in the case that a call completes before
**   finalization can be executed.
*/
void QPyEngineCore::Slot_FnEnd(PyObject* ret, QString errStr, QPyEngine_RetFn retFn)
{
	std::unique_lock<std::mutex> lock(this->mtx);
	for (auto itr = this->threads.begin(); itr != this->threads.end(); ++itr) {
		if ((*itr)->get_id() == this->threadQueue.front()) {
			(*itr)->join();
			delete (*itr);
			this->threads.erase(itr);
			break;
		}
	}
	lock.unlock();
	(*retFn)(ret, errStr);
}

QPYENGINE_NAMESPACE_END