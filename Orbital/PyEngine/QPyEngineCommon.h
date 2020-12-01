#pragma once

#include <stdexcept>

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#ifdef PyEngine
#error "ERROR: PyEngine already defined."
#else
#define PyEngine PyEngine
#define QPYENGINE_NAMESPACE_BEGIN namespace PyEngine {
#define QPYENGINE_NAMESPACE_END }
#endif

#include <QObject>