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

#include "QPyEngineInterface.h"
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

QPyEngineInterface* QPyEngineInterface::hInstance = nullptr;

PyMethodDef pyMethodTable[] =
{
	{
		RECFN_MSG,
		RecFn_Msg,
		METH_VARARGS,
		"msg(msg, append=False)"
		"\nSends a message to the UI."
	},
	{
		RECFN_INIT,
		RecFn_Init,
		METH_VARARGS,
		"init([n_plots, plot_arrangement], parameters, visa_resources=Null)"
		"\nInitializes the client with the desired script parameters."
	},
	{
		RECFN_DATA,
		RecFn_Data,
		METH_VARARGS,
		"sendData(data_set, n_data, data0, data1, ...)"
		"\nPasses a single data point to the client for plotting/saving."
	},
	{
		RECFN_XDATA,
		RecFn_XData,
		METH_VARARGS,
		"sendXData(data_set, x_data, y_data, save=False)"
		"\nPasses multiple data points to the client."
	},
	{
		RECFN_DATAINFO,
		RecFn_DataInfo,
		METH_VARARGS,
		"setDataInfo(data_set, info)"
		"\nSets the header information for a specific data set."
	},
	{
		RECFN_DATAFILEINFO,
		RecFn_DataFileInfo,
		METH_VARARGS,
		"setDataFileInfo(info)"
		"\nSets the header information for the data file."
	},
	{
		RECFN_PLOT2DPROP,
		RecFn_Plot2DProp,
		METH_VARARGS,
		"set2DPlotProperty(plot_id, plot_property, new_value)"
		"\nSets the given 2-D plot property."
	},
	{
		RECFN_PLOTCMPROP,
		RecFn_PlotCMProp,
		METH_VARARGS,
		"setColormapProperty(plot_id, colormap_property, new_value)"
		"\nSets the given colormap property."
	},
	{
		RECFN_SAVE,
		RecFn_Save,
		METH_VARARGS,
		"saveData(data_set, data_header)"
		"\nPerforms an immediate save (file write) of the given data set."
	},
	{
		RECFN_CLEAR,
		RecFn_Clear,
		METH_VARARGS,
		"clearData(data_set)"
		"\nClears the data buffer of a specified data set (does not clear plot - see sendData)."
	},
	{
		RECFN_CMDATA,
		RecFn_CMData,
		METH_VARARGS,
		"sendCMData(plot_id, x, y, val)"
		"\nPasses colormap data for plotting."
	},
	{
		RECFN_CMDATAROW,
		RecFn_CMDataRow,
		METH_VARARGS,
		"sendCMDataRow(plot_id, row, z_vals)"
		"\nPasses a row of colormap data for plotting."
	},
	{
		RECFN_CMSETUP,
		RecFn_CMSetup,
		METH_VARARGS,
		"setupCM(plot_id, xMin, xMax, yMin, yMax, xSize, ySize, show=True)"
		"\nInitializes a colormap."
	},
	{
		RECFN_CMSHOW,
		RecFn_CMShow,
		METH_VARARGS,
		"showColormap(plot_id, show=True)"
		"\nShows or hides a specified colormap."
	},
	{
		RECFN_CFNAME,
		RecFn_CFName,
		METH_VARARGS,
		"renameCustom(customFn, new_name)"
		"\nRenames the custom function button on the UI."
	},
	{
		RECFN_ASFILE,
		RecFn_ASFile,
		METH_VARARGS,
		"setAutoSave()"
		"\nEnables the auto-save flag for this script."
	},
	{
		RECFN_PLOTSETUP,
		RecFn_PlotSetup,
		METH_VARARGS,
		"setPlotArrangement(plot_arrangement)"
		"\nSets the plot arrangement."
	}
};

QPyEngineInterface::QPyEngineInterface(QObject* parent)
	: QObject(parent), pyModule(Q_NULLPTR)
{
	QPyEngine::RegisterMethods(pyMethodTable, (sizeof(pyMethodTable) / sizeof(PyMethodDef)));
	QPyEngine::Init(this);
	QPyEngineInterface::hInstance = this;
}

QPyEngineInterface::~QPyEngineInterface()
{
	if (this->pyModule)
		delete this->pyModule;
	QPyEngine::DeInit();
}

int QPyEngineInterface::Load(const QString& moduleFile)
{
	QString errStr;

	if (this->pyModule != Q_NULLPTR)
		delete this->pyModule;
	this->pyModule = new QPyEngine::Module(moduleFile.toStdString().c_str());
	if (this->pyModule->Load(errStr) == 0 ||
		this->pyModule->Reload(errStr) == 0)
	{
		emit Signal_Error(errStr);
		delete this->pyModule;
		this->pyModule = Q_NULLPTR;
		return 1;
	}
	return 0;
}

int QPyEngineInterface::Reload()
{
	QString errStr;

	if (this->pyModule == Q_NULLPTR) {
		emit Signal_Error("No module loaded.");
		return 1;
	}
	if (this->pyModule->Reload(errStr) == 0) {
		emit Signal_Error(errStr);
		return 1;
	}
	return 0;
}

int QPyEngineInterface::Init()
{
	return Call(FN_INIT, NULL, &QPyEngineInterface::RetFn_Init);
}

int QPyEngineInterface::Run(std::vector<std::pair<std::string, std::string>>& args)
{
	PyObject* pyArgs;

	this->pyModule->CoreLock();
	pyArgs = PyDict_New();
	for (const auto& i : args) {
		PyObject* item = PyUnicode_FromString(i.second.c_str());
		PyDict_SetItemString(pyArgs, i.first.c_str(), item);
		Py_DECREF(item);
	}
	this->pyModule->CoreUnlock();

	return Call(FN_RUN, pyArgs, &QPyEngineInterface::RetFn_Run);
}

int QPyEngineInterface::Stop()
{
	return Call(FN_STOP, NULL, &QPyEngineInterface::RetFn_Stop);
}

#define QPY_CALL_CUSTOM(fn) Call(FN_CUSTOM##fn, NULL, &QPyEngineInterface::RetFn_Custom##fn)
int QPyEngineInterface::Custom(size_t n)
{
	switch (n) {
	case 0: return QPY_CALL_CUSTOM(1);
	case 1: return QPY_CALL_CUSTOM(2);
	case 2: return QPY_CALL_CUSTOM(3);
	case 3: return QPY_CALL_CUSTOM(4);
	case 4: return QPY_CALL_CUSTOM(5);
	case 5: return QPY_CALL_CUSTOM(6);
	case 6: return QPY_CALL_CUSTOM(7);
	case 7: return QPY_CALL_CUSTOM(8);
	default: break;
	}
	return 1;
}
#undef QPY_CALL_CUSTOM

void QPyEngineInterface::AppendPythonPath(const std::string& path)
{
	QPyEngine::AppendPythonPath(path);
}

int QPyEngineInterface::Call(const char* funcName, PyObject* args, QPyEngine_RetFn retFn)
{
	QString errStr;

	if (this->pyModule == Q_NULLPTR) {
		emit Signal_Error(QString("No module loaded"));
		return 1;
	}
	if (this->pyModule->CallFn(funcName, args, retFn, errStr) == 0) {
		emit Signal_Error(errStr);
		return 1;
	}
	return 0;
}

/*
** Module function callback functions. Each callback function simply signals
** to the interface when the function call has ended and a description of the
** error if one had occurred. Return values are ignored.
*/
#define QPYENGINE_RETFN(fn) \
void QPyEngineInterface::RetFn_##fn(PyObject * ret, QString& errStr) \
{                                                                    \
	int s = 0;                                                       \
	if (ret == NULL) {                                               \
		s = 1;                                                       \
		emit QPyEngineInterface::hInstance->Signal_Error(errStr);    \
	}                                                                \
	else {                                                           \
		QPyEngineInterface::hInstance->pyModule->CoreLock();         \
		Py_DECREF(ret);                                              \
		QPyEngineInterface::hInstance->pyModule->CoreUnlock();       \
	}                                                                \
	emit QPyEngineInterface::hInstance->Signal_RetFn_##fn(s);        \
}

QPYENGINE_RETFN(Init)
QPYENGINE_RETFN(Run)
QPYENGINE_RETFN(Stop)
QPYENGINE_RETFN(Custom1)
QPYENGINE_RETFN(Custom2)
QPYENGINE_RETFN(Custom3)
QPYENGINE_RETFN(Custom4)
QPYENGINE_RETFN(Custom5)
QPYENGINE_RETFN(Custom6)
QPYENGINE_RETFN(Custom7)
QPYENGINE_RETFN(Custom8)

/*
** Not used.
*/
void PyErr_SetStringEx(PyObject* exception, const char* format, ...)
{
	va_list args, args_copy;
	char* buffer = NULL;
	int buf_sz = 0;

	va_start(args, format);
	va_copy(args_copy, args);
	if ((buf_sz = vsnprintf(NULL, 0, format, args_copy)) < 0) {
		PyErr_SetString(exception, format);
	}
	else {
		if ((buffer = (char*)malloc(buf_sz + 1)) == NULL) {
			PyErr_SetString(exception, format);
		}
		else {
			buffer[buf_sz] = 0;
			vsprintf(buffer, format, args);
			PyErr_SetString(exception, buffer);
			free(buffer);
		}
	}
	va_end(args_copy);
	va_end(args);
}

/****************************
** PYTHON OUTPUT FUNCTIONS **
****************************/

/*
** 'msg' method
*/
PyObject* RecFn_Msg(PyObject* self, PyObject* args)
{
	const char* msg;
	PyObject* pyBool = NULL;
	bool append = false;

	if (!PyArg_ParseTuple(args, "s|O", &msg, &pyBool)) {
		return NULL;
	}
	if (pyBool != NULL) {
		int pyBoolVal = PyObject_IsTrue(pyBool);
		if (pyBoolVal < 0) {
			PyErr_SetString(PyExc_RuntimeError, "Could not parse bool value [msg]");
			return NULL;
		}
		if (pyBoolVal == 1)
			append = true;
	}

	emit QPyEngineInterface::hInstance->Signal_Msg(QString(msg), append);
	Py_RETURN_NONE;
}

/*
** 'init' method
*/
PyObject* RecFn_Init(PyObject* self, PyObject* args)
{
	unsigned int nGraphs = 0;
	PyObject* plotArrng = NULL;
	PyObject* paramList = NULL;
	PyObject* visaTuple = NULL;
	QStringList params;
	QStringList visaResources;

	/* Function overloading implementation. NULL value for 'plotArrng' indicates no overload. */
	if (!PyArg_ParseTuple(args, "IO|O", &nGraphs, &paramList, &visaTuple)) {
		PyErr_Clear();
		if (!PyArg_ParseTuple(args, "OO|O", &plotArrng, &paramList, &visaTuple)) {
			return NULL;
		}
	}

	/* Parse input parameters. */
	if (!PyList_Check(paramList)) {
		PyErr_SetString(PyExc_RuntimeError, "Parameters not received as list [init]");
		return NULL;
	}
	if (paramList != NULL) {
		Py_ssize_t sz = PyList_Size(paramList);
		for (Py_ssize_t i = 0; i < sz; ++i) {
			std::string paramItem;
			PyString_ToStdString(PyList_GetItem(paramList, i), paramItem);
			params.push_back(QString::fromStdString(paramItem));
		}
	}

	/* Parse visa resources. */
	if (visaTuple != NULL) {
		if (!PyTuple_Check(visaTuple)) {
			PyErr_SetString(PyExc_RuntimeError, "Visa resources not received as tuple [init]");
			return NULL;
		}
		Py_ssize_t sz = PyTuple_Size(visaTuple);
		for (Py_ssize_t i = 0; i < sz; ++i) {
			std::string visaItem;
			PyString_ToStdString(PyTuple_GetItem(visaTuple, i), visaItem);
			visaResources.push_back(QString::fromStdString(visaItem));
		}
	}

	/* Parse plot arrangement. */
	if (plotArrng != NULL) {
		if (!PyList_Check(plotArrng)) {
			PyErr_SetString(PyExc_RuntimeError, "Could not parse first argument [init]");
			return NULL;
		}

		QVector<GridPoint> plotArrangement;
		Py_ssize_t n_plots = PyList_Size(plotArrng);
		for (Py_ssize_t i = 0; i < n_plots; ++i) {
			int gp[4];
			PyObject* listItem = PyList_GetItem(plotArrng, i);

			if (!PyList_Check(listItem)) {
				PyErr_SetString(PyExc_RuntimeError, "Invalid object in plot arrangement list [init]");
				return NULL;
			}
			if (PyList_Size(listItem) != 4) {
				PyErr_SetString(PyExc_RuntimeError, "Invalid plot arrangement [init]");
				return NULL;
			}
			for (Py_ssize_t j = 0; j < 4; ++j) {
				PyObject* p = PyList_GetItem(listItem, j);
				if (!PyLong_CheckExact(p)) {
					PyErr_SetString(PyExc_RuntimeError, "Invalid object in plot arrangement list [init]");
					return NULL;
				}
				gp[j] = (int)PyLong_AsLong(p);
			}
			plotArrangement.push_back(GridPoint(gp[0], gp[1], gp[2], gp[3]));
		}
		emit QPyEngineInterface::hInstance->Signal_ScriptInitializeEx(plotArrangement, params, visaResources);
	}
	else {
		emit QPyEngineInterface::hInstance->Signal_ScriptInitialize(nGraphs, params, visaResources);
	}
	Py_RETURN_NONE;
}

/*
** 'sendData' method
** This is one of the only methods where processing speed is the only factor.
*/
PyObject* RecFn_Data(PyObject* self, PyObject* args)
{
	unsigned int nGraph = 0, argc = 2;
	double* d = new double[32]();

	if (!PyArg_ParseTuple(args, "II|dddddddddddddddddddddddddddddddd", &nGraph, &argc,
		&d[0], &d[1], &d[2], &d[3], &d[4], &d[5], &d[6], &d[7], &d[8], &d[9], &d[10], &d[11], &d[12], &d[13], &d[14], &d[15],
		&d[16], &d[17], &d[18], &d[19], &d[20], &d[21], &d[22], &d[23], &d[24], &d[25], &d[26], &d[27], &d[28], &d[29], &d[30], &d[31])) {
		free(d);
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_Data(nGraph, argc, d);
	Py_RETURN_NONE;
}

/*
** 'sendXData' method
** Similar to 'sendData', processing speed should be a main concern within this function.
*/
PyObject* RecFn_XData(PyObject* self, PyObject* args)
{
	unsigned int nGraph = 0;
	PyObject* dataX = NULL;
	PyObject* dataY = NULL;
	PyObject* pyBool = NULL;
	Py_ssize_t dataX_sz, dataY_sz, data_sz;
	QVector<double>* dx;
	QVector<double>* dy;
	bool save = true;

	if (!PyArg_ParseTuple(args, "IOO|O", &nGraph, &dataX, &dataY, &pyBool)) {
		return NULL;
	}

	if (!PyList_Check(dataX) || !PyList_Check(dataY)) {
		PyErr_SetString(PyExc_RuntimeError, "Data not received as list [sendXData]");
		return NULL;
	}
	if (pyBool != NULL) {
		int pyBoolVal = PyObject_IsTrue(pyBool);
		if (pyBoolVal < 0) {
			PyErr_SetString(PyExc_RuntimeError, "Could not parse bool value [sendXData]");
			return NULL;
		}
		if (pyBoolVal != 1)
			save = false;
	}

	dataX_sz = PyList_Size(dataX);
	dataY_sz = PyList_Size(dataY);
	dx = new QVector<double>(dataX_sz);
	dy = new QVector<double>(dataY_sz);

	if (dataX_sz != dataY_sz)
		emit QPyEngineInterface::hInstance->Signal_Error(QString("WARNING: Received lists of different sizes [%1]\n").arg(RECFN_XDATA));

	data_sz = (dataX_sz < dataY_sz ? dataX_sz : dataY_sz);
	for (Py_ssize_t i = 0; i < data_sz; ++i) {
		PyObject *listItemX = PyList_GetItem(dataX, i);
		PyObject *listItemY = PyList_GetItem(dataY, i);
		double x = 0, y = 0;

		if (PyFloat_Check(listItemX)) {
			x = PyFloat_AS_DOUBLE(listItemX);
		}
		else if (PyLong_Check(listItemX)) {
			x = (double)PyLong_AsLong(listItemX);
		}
		else {
			PyErr_SetString(PyExc_RuntimeError, "List object not recognized as a float [sendXData]");
			free(dx);
			free(dy);
			return NULL;
		}
		(*dx)[i] = x;

		if (PyFloat_Check(listItemY)) {
			y = PyFloat_AS_DOUBLE(listItemY);
		}
		else if (PyLong_Check(listItemY)) {
			y = (double)PyLong_AsLong(listItemY);
		}
		else {
			PyErr_SetString(PyExc_RuntimeError, "List object not recognized as a float [sendXData]");
			free(dx);
			free(dy);
			return NULL;
		}
		(*dy)[i] = y;
	}

	emit QPyEngineInterface::hInstance->Signal_XData(nGraph, dx, dy, save);
	Py_RETURN_NONE;
}

/*
** 'setDataInfo' method
*/
PyObject* RecFn_DataInfo(PyObject* self, PyObject* args)
{
	unsigned int id = 0;
	const char* info = NULL;

	if (!PyArg_ParseTuple(args, "Is", &id, &info)) {
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_DataInfo(id, QString(info));
	Py_RETURN_NONE;
}

/*
** 'setDataFileInfo' method
*/
PyObject* RecFn_DataFileInfo(PyObject* self, PyObject* args)
{
	const char* info = NULL;

	if (!PyArg_ParseTuple(args, "s", &info)) {
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_DataFileInfo(QString(info));
	Py_RETURN_NONE;
}

/*
** 'set2DPlotProperty' method
*/
PyObject* RecFn_Plot2DProp(PyObject* self, PyObject* args)
{
	unsigned int pIdx = 0;
	const char* c_p = NULL;
	const char* c_v = NULL;

	if (!PyArg_ParseTuple(args, "Iss", &pIdx, &c_p, &c_v)) {
		return NULL;
	}

	QString p = c_p == NULL ? QString("") : QString(c_p);
	QString v = c_v == NULL ? QString("") : QString(c_v);

	emit QPyEngineInterface::hInstance->Signal_PlotProperty2D(pIdx, p, v);
	Py_RETURN_NONE;
}

/*
** 'setColormapProperty' method
*/
PyObject* RecFn_PlotCMProp(PyObject* self, PyObject* args)
{
	unsigned int pIdx = 0;
	const char* c_p = NULL;
	const char* c_v = NULL;

	if (!PyArg_ParseTuple(args, "Iss", &pIdx, &c_p, &c_v)) {
		return NULL;
	}

	QString p = c_p == NULL ? QString("") : QString(c_p);
	QString v = c_v == NULL ? QString("") : QString(c_v);

	emit QPyEngineInterface::hInstance->Signal_PlotPropertyCM(pIdx, p, v);
	Py_RETURN_NONE;
}

/*
** 'saveData' method
*/
PyObject* RecFn_Save(PyObject* self, PyObject* args)
{
	unsigned int dataID = 0;
	const char* dataHeader = NULL;

	if (!PyArg_ParseTuple(args, "I|s", &dataID, &dataHeader)) {
		return NULL;
	}

	QString dataHeaderStr = dataHeader == NULL ? "" : QString(dataHeader);

	emit QPyEngineInterface::hInstance->Signal_SaveData(dataID, dataHeaderStr);
	Py_RETURN_NONE;
}

/*
** 'clearData' method
*/
PyObject* RecFn_Clear(PyObject* self, PyObject* args)
{
	unsigned int dataID = 0;

	if (!PyArg_ParseTuple(args, "I", &dataID)) {
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_ClearData(dataID);
	Py_RETURN_NONE;
}

/*
** 'sendCMData' method
*/
PyObject* RecFn_CMData(PyObject* self, PyObject* args)
{
	unsigned int graphID = 0, xIdx = 0, yIdx = 0;
	double z = 0;

	if (!PyArg_ParseTuple(args, "IIId", &graphID, &xIdx, &yIdx, &z)) {
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_CMData(graphID, xIdx, yIdx, z);
	Py_RETURN_NONE;
}

/*
** 'sendCMDataRow' method
*/
PyObject* RecFn_CMDataRow(PyObject* self, PyObject* args)
{
	unsigned int graphID = 0, row = 0;
	PyObject* zList = NULL;
	QVector<double>* z;
	Py_ssize_t z_sz;

	if (!PyArg_ParseTuple(args, "IIO", &graphID, &row, &zList)) {
		return NULL;
	}
	if (!PyList_Check(zList)) {
		PyErr_SetString(PyExc_RuntimeError, "Data not received as list [sendCMDataRow]");
		return NULL;
	}

	z_sz = PyList_Size(zList);
	z = new QVector<double>(z_sz);
	for (Py_ssize_t i = 0; i < z_sz; ++i) {
		PyObject *listItem = PyList_GetItem(zList, i);
		double zVal = 0;

		if (PyFloat_Check(listItem)) {
			zVal = PyFloat_AS_DOUBLE(listItem);
		}
		else if (PyLong_Check(listItem)) {
			zVal = (double)PyLong_AsLong(listItem);
		}
		else {
			PyErr_SetString(PyExc_RuntimeError, "List object not recognized as a numeric [sendCMDataRow]");
			free(z);
			return NULL;
		}
		(*z)[i] = zVal;
	}

	emit QPyEngineInterface::hInstance->Signal_CMDataRow(graphID, row, z);
	Py_RETURN_NONE;
}

/*
** 'setupColormap' method
*/
PyObject* RecFn_CMSetup(PyObject* self, PyObject* args)
{
	unsigned int graphID = 0, xSize = 0, ySize = 0;
	double xMin = 0, xMax = 0, yMin = 0, yMax = 0, zMin = 0, zMax = 0;
	PyObject* pyBool = NULL;
	bool show = true;
	bool zRange = true;

	/* Function overload implementation. */
	if (!PyArg_ParseTuple(args, "IddddIIdd|O", &graphID, &xMin, &xMax, &yMin, &yMax, &xSize, &ySize, &zMin, &zMax, &pyBool)) {
		PyErr_Clear();
		zRange = false;
		if (!PyArg_ParseTuple(args, "IddddII|O", &graphID, &xMin, &xMax, &yMin, &yMax, &xSize, &ySize, &pyBool)) {
			return NULL;
		}
	}

	if (pyBool != NULL) {
		int pyBoolVal = PyObject_IsTrue(pyBool);
		if (pyBoolVal < 0) {
			PyErr_SetString(PyExc_RuntimeError, "Could not parse bool value [setupColormap]");
			return NULL;
		}
		if (pyBoolVal == 0)
			show = false;
	}

	emit QPyEngineInterface::hInstance->Signal_CMSetup(graphID, xMin, xMax, yMin, yMax, xSize, ySize, zRange, zMin, zMax, show);
	Py_RETURN_NONE;
}

/*
** 'showColormap' method
*/
PyObject* RecFn_CMShow(PyObject* self, PyObject* args)
{
	unsigned int graphID = 0;
	PyObject* pyBool = NULL;
	bool show = true;

	if (!PyArg_ParseTuple(args, "I|O", &graphID, &pyBool)) {
		return NULL;
	}

	if (pyBool != NULL) {
		int pyBoolVal = PyObject_IsTrue(pyBool);
		if (pyBoolVal < 0) {
			PyErr_SetString(PyExc_RuntimeError, "Could not parse bool value [showColormap]");
			return NULL;
		}
		if (pyBoolVal == 0)
			show = false;
	}

	emit QPyEngineInterface::hInstance->Signal_CMShow(graphID, show);
	Py_RETURN_NONE;
}

/*
** 'renameCustom' method
*/
PyObject* RecFn_CFName(PyObject* self, PyObject* args)
{
	unsigned int fnNumber = 0;
	const char* fnName = NULL;

	if (!PyArg_ParseTuple(args, "Is", &fnNumber, &fnName)) {
		return NULL;
	}

	QString newName = fnName == NULL ? QString("") : QString(fnName);

	emit QPyEngineInterface::hInstance->Signal_CustomFnName(fnNumber, newName);
	Py_RETURN_NONE;
}

/*
** 'setAutoSave' method
*/
PyObject* RecFn_ASFile(PyObject* self, PyObject* args)
{
	PyObject* pyBool = NULL;
	const char* fileName = NULL;
	bool autosaveEnable = false;

	if (!PyArg_ParseTuple(args, "O|s", &pyBool, &fileName)) {
		return NULL;
	}

	if (pyBool != NULL) {
		int pyBoolVal = PyObject_IsTrue(pyBool);
		if (pyBoolVal < 0) {
			PyErr_SetString(PyExc_RuntimeError, "Could not parse bool value [setAutoSave]");
			return NULL;
		}
		if (pyBoolVal == 1)
			autosaveEnable = true;
	}

	QString file = fileName == NULL ? QString("") : QString(fileName);

	emit QPyEngineInterface::hInstance->Signal_AutoSaveConfig(autosaveEnable, file);
	Py_RETURN_NONE;
}

/*
** 'setPlotArrangement' method
*/
PyObject* RecFn_PlotSetup(PyObject* self, PyObject* args)
{
	PyObject* plotArrng = NULL;

	if (!PyArg_ParseTuple(args, "O", &plotArrng)) {
		return NULL;
	}
	if (!PyList_Check(plotArrng)) {
		PyErr_SetString(PyExc_RuntimeError, "Could not parse first argument [setPlotArrangement]");
		return NULL;
	}

	QVector<GridPoint> plotArrangement;
	Py_ssize_t n_plots = PyList_Size(plotArrng);
	for (Py_ssize_t i = 0; i < n_plots; ++i) {
		int gp[4];
		PyObject * listItem = PyList_GetItem(plotArrng, i);

		if (!PyList_Check(listItem)) {
			PyErr_SetString(PyExc_RuntimeError, "Invalid object in plot arrangement list [setPlotArrangement]");
			return NULL;
		}
		if (PyList_Size(listItem) != 4) {
			PyErr_SetString(PyExc_RuntimeError, "Invalid plot arrangement [setPlotArrangement]");
			return NULL;
		}
		for (Py_ssize_t j = 0; j < 4; ++j) {
			PyObject* p = PyList_GetItem(listItem, j);
			if (!PyLong_CheckExact(p)) {
				PyErr_SetString(PyExc_RuntimeError, "Invalid object in plot arrangement list [setPlotArrangement]");
				return NULL;
			}
			gp[j] = (int)PyLong_AsLong(p);
		}
		plotArrangement.push_back(GridPoint(gp[0], gp[1], gp[2], gp[3]));
	}

	emit QPyEngineInterface::hInstance->Signal_PlotArrangement(plotArrangement);
	Py_RETURN_NONE;
}