#pragma once

#include <stdexcept>

#define QPYENGINE_PY_MAJOR_VER 3
#define QPYENGINE_PY_MINOR_VER 7

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#if PY_MAJOR_VERSION < QPYENGINE_PY_MAJOR_VER
#error "ERROR: Python Version (maj) not supported."
#elif PY_MAJOR_VERSION == QPYENGINE_PY_MAJOR_VER
#if PY_MINOR_VERSION < QPYENGINE_PY_MINOR_VER
#error "ERROR: Python Version (min) not supported."
#endif
#endif

#ifdef QPyEngine
#error "ERROR: QPyEngine already defined."
#else
#define QPyEngine QPyEngine
#define QPYENGINE_NAMESPACE_BEGIN namespace QPyEngine {
#define QPYENGINE_NAMESPACE_END }
#endif

#include <QObject>