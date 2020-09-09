#pragma once

#include "QPyEngineCommon.h"
#include <string>
#include <QString>

void ErrorReport(QString&);
int AppendSystemPath(const char *);
int PyList_Contains(PyObject *, PyObject *);
int PyString_ToStdString(PyObject *, std::string&);