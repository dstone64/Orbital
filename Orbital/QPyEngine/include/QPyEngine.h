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

#include "QPyEngineCore.h"
#include "QPyEngineUtils.h"
#include <queue>

#define QPYENGINE_MODULENAME "orbital"

QPYENGINE_NAMESPACE_BEGIN

void Init(QObject* parent = Q_NULLPTR);
void DeInit() noexcept;
void RegisterMethod(const PyMethodDef& pyMethod);
void RegisterMethods(const PyMethodDef* pyMethods, size_t n);
void AppendPythonPath(const std::string&);

class Module : public QObject
{
	Q_OBJECT

public:
	Module(const char* moduleFile);
	~Module();
	Module(const Module&) = delete;
	Module& operator=(const Module&) = delete;

	int Load(QString& errStr);
	int Reload(QString& errStr);
	int CallFn(const char* fnName, PyObject* args, QPyEngine_RetFn retFn, QString& errStr);

	void CoreLock();
	void CoreUnlock();

Q_SIGNALS:
	void Signal_FnEnd(PyObject* ret, QString errStr, QPyEngine_RetFn retFn);

private:
	void Call(PyObject* func, PyObject* args, QPyEngine_RetFn retFn, PyInterpreterState* interpState);

	QPyEngineCore* core;
	PyObject* name;
	PyObject* module;
};

QPYENGINE_NAMESPACE_END