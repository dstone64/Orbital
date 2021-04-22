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

#pragma once

#include <list>
#include <mutex>
#include <queue>
#include <string>

#include "QPyEngineCommon.h"
#include <QString>

typedef void(*QPyEngine_RetFn)(PyObject*, QString&);
Q_DECLARE_METATYPE(QPyEngine_RetFn);

QPYENGINE_NAMESPACE_BEGIN

class QPyEngineCore : public QObject
{
	Q_OBJECT

public:
	QPyEngineCore(QObject* parent);
	~QPyEngineCore();
	QPyEngineCore(const QPyEngineCore&) = delete;
	QPyEngineCore& operator=(const QPyEngineCore&) = delete;

	void Lock();
	void Unlock();
	void PushThreadQueue(std::thread::id&);

	std::list<std::thread*> threads;
	PyThreadState* mainThreadState;

public Q_SLOTS:
	void Slot_FnEnd(PyObject* ret, QString errStr, QPyEngine_RetFn retFn);

private:
	std::mutex mtx;
	std::queue<std::thread::id> threadQueue;
};

QPYENGINE_NAMESPACE_END