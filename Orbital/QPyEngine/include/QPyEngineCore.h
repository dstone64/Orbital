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