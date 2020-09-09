#pragma once

#include "QPyEngineCore.h"
#include <queue>

#define MODULENAME "orbital"

QPYENGINE_NAMESPACE_BEGIN

void Init(QObject * parent = Q_NULLPTR);
void DeInit();
void RegisterMethod(const PyMethodDef& pyMethod);
void RegisterMethods(const PyMethodDef * pyMethods, size_t n);
void AppendPythonPath(const std::string&);

class Module : public QObject
{
	Q_OBJECT

public:
	Module(const char * moduleFile);
	~Module();
	Module(const Module&) = delete;
	Module& operator=(const Module&) = delete;

	// Returns 1 on success or 0 on failure
	int Load(QString& errStr);

	// Returns 1 on success or 0 on failure
	int Reload(QString& errStr);

	// Returns 1 on success or 0 on failure (no new thread on failure)
	int CallFunc(const char * fnName, PyObject * args, QPyEngine_RetFn retFn, QString& errStr);

	void CoreLock();
	void CoreUnlock();

Q_SIGNALS:
	void Signal_FuncEnd(PyObject * ret, QString errStr, QPyEngine_RetFn retFn);

private:
	void Call(PyObject * func, PyObject * args, QPyEngine_RetFn retFn, PyInterpreterState * interpState);

	QPyEngineCore * core;
	PyObject * name;
	PyObject * module;
};

QPYENGINE_NAMESPACE_END