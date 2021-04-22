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