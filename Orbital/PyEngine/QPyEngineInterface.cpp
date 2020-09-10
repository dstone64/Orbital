#include "QPyEngineInterface.h"
#include "QPyEngineUtils.h"
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

QPyEngineInterface * QPyEngineInterface::hInstance = nullptr;

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
		"init(n_plots OR plot_arrangement, parameters, visa_resources=Null)"
		"\nInitializes the client for the loaded script."
	},
	{
		RECFN_DATA,
		RecFn_Data,
		METH_VARARGS,
		"sendData(data_set, n_data, data0, data1, ...)"
		"\nPass data to the client for saving and/or displaying."
	},
	{
		RECFN_XDATA,
		RecFn_XData,
		METH_VARARGS,
		"sendXData(data_set, x_data, y_data, save=False)"
		"\nPass a multiple data points to the client."
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
		"\nSets the given 2D plot property."
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
		"\nPerforms an auto-save on the given data set. The data will be written to disk with the given header."
	},
	{
		RECFN_CLEAR,
		RecFn_Clear,
		METH_VARARGS,
		"clearData(data_set)"
		"\nClears the data set."
	},
	{
		RECFN_CMDATA,
		RecFn_CMData,
		METH_VARARGS,
		"sendCMData(plot_id, x, y, val)"
		"\nPass colormap data to the UI for displaying."
	},
	{
		RECFN_CMSETUP,
		RecFn_CMSetup,
		METH_VARARGS,
		"setupCM(plot_id, xMin, xMax, yMin, yMax, xSize, ySize, show=True)"
		"\nInitializes the colormap."
	},
	{
		RECFN_CMSHOW,
		RecFn_CMShow,
		METH_VARARGS,
		"showColormap(plot_id, show=True)"
		"\nToggles between the colormap and 2D plot."
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

QPyEngineInterface::QPyEngineInterface(QObject *parent)
	: QObject(parent), pyModule(Q_NULLPTR)
{
	PyEngine::RegisterMethods(pyMethodTable, (sizeof(pyMethodTable) / sizeof(PyMethodDef)));
	PyEngine::Init(this);
	QPyEngineInterface::hInstance = this;
}

QPyEngineInterface::~QPyEngineInterface()
{
	if (this->pyModule)
		delete this->pyModule;
	PyEngine::DeInit();
}

int QPyEngineInterface::Load(const QString& moduleFile)
{
	QString errStr;

	if (this->pyModule != Q_NULLPTR)
		delete this->pyModule;
	this->pyModule = new PyEngine::Module(moduleFile.toStdString().c_str());
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
	PyObject * pyArgs;

	this->pyModule->CoreLock();
	//args = Py_BuildValue("(s)", argsStr.c_str());
	pyArgs = PyDict_New();
	for (const auto& i : args) {
		PyObject * item = PyUnicode_FromString(i.second.c_str());
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

#define CALL_CUSTOM(fn) Call(FN_CUSTOM##fn, NULL, &QPyEngineInterface::RetFn_Custom##fn)
int QPyEngineInterface::Custom(size_t n)
{
	switch (n) {
	case 0: return CALL_CUSTOM(1);
	case 1: return CALL_CUSTOM(2);
	case 2: return CALL_CUSTOM(3);
	case 3: return CALL_CUSTOM(4);
	case 4: return CALL_CUSTOM(5);
	case 5: return CALL_CUSTOM(6);
	case 6: return CALL_CUSTOM(7);
	case 7: return CALL_CUSTOM(8);
	default: break;
	}
	return 1;
}

void QPyEngineInterface::AppendPythonPath(const std::string& path)
{
	PyEngine::AppendPythonPath(path);
}

int QPyEngineInterface::Call(const char * funcName, PyObject * args, QPyEngine_RetFn retFn)
{
	QString errStr;

	if (this->pyModule == Q_NULLPTR) {
		emit Signal_Error(QString("No module loaded"));
		return 1;
	}
	if (this->pyModule->CallFunc(funcName, args, retFn, errStr) == 0) {
		emit Signal_Error(errStr);
		return 1;
	}
	return 0;
}

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

void PyErr_SetStringEx(PyObject * exception, const char * format, ...)
{
	va_list args, args_copy;
	char * buffer = NULL;
	int buf_sz = 0;

	va_start(args, format);
	va_copy(args_copy, args);
	if ((buf_sz = vsnprintf(NULL, 0, format, args_copy)) < 0) {
		PyErr_SetString(exception, format);
	}
	else {
		if ((buffer = (char *)malloc(buf_sz + 1)) == NULL) {
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

/*
** PYTHON OUTPUT FUNCTIONS
*/

PyObject * RecFn_Msg(PyObject * self, PyObject * args)
{
	const char * msg;
	PyObject * pyBool = NULL;
	bool append = false;

	if (!PyArg_ParseTuple(args, "s|O", &msg, &pyBool)) {
		return NULL;
	}
	if (pyBool != NULL) {
		int pyBoolVal = PyObject_IsTrue(pyBool);
		if (pyBoolVal < 0) {
			PyErr_SetString(PyExc_RuntimeError, "Could not parse bool value [sendMsg]");
			return NULL;
		}
		if (pyBoolVal == 1)
			append = true;
	}

	emit QPyEngineInterface::hInstance->Signal_Msg(QString(msg), append);
	Py_RETURN_NONE;
}

PyObject * RecFn_Init(PyObject * self, PyObject * args)
{
	unsigned int nGraphs = 0;
	PyObject * plotArrng = NULL;
	PyObject * paramList = NULL;
	PyObject * visaTuple = NULL;
	QStringList params;
	QStringList visaResources;

	if (!PyArg_ParseTuple(args, "IO|O", &nGraphs, &paramList, &visaTuple)) {
		PyErr_Clear();
		if (!PyArg_ParseTuple(args, "OO|O", &plotArrng, &paramList, &visaTuple)) {
			return NULL;
		}
	}

	if (!PyList_Check(paramList)) {
		PyErr_SetString(PyExc_RuntimeError, "Parameters not received as list [sendInit]");
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

	if (visaTuple != NULL) {
		if (!PyTuple_Check(visaTuple)) {
			PyErr_SetString(PyExc_RuntimeError, "Visa resources not received as tuple [sendInit]");
			return NULL;
		}
		Py_ssize_t sz = PyTuple_Size(visaTuple);
		for (Py_ssize_t i = 0; i < sz; ++i) {
			std::string visaItem;
			PyString_ToStdString(PyTuple_GetItem(visaTuple, i), visaItem);
			visaResources.push_back(QString::fromStdString(visaItem));
		}
	}

	if (plotArrng != NULL) {
		if (!PyList_Check(plotArrng)) {
			PyErr_SetString(PyExc_RuntimeError, "Could not parse first argument [sendInit]");
			return NULL;
		}

		QVector<GridPoint> plotArrangement;
		Py_ssize_t n_plots = PyList_Size(plotArrng);
		for (Py_ssize_t i = 0; i < n_plots; ++i) {
			int gp[4];
			PyObject * listItem = PyList_GetItem(plotArrng, i);

			if (!PyList_Check(listItem)) {
				PyErr_SetString(PyExc_RuntimeError, "Invalid object in plot arrangement list [sendInit]");
				return NULL;
			}
			if (PyList_Size(listItem) != 4) {
				PyErr_SetString(PyExc_RuntimeError, "Invalid plot arrangement [sendInit]");
				return NULL;
			}
			for (Py_ssize_t j = 0; j < 4; ++j) {
				PyObject *p = PyList_GetItem(listItem, j);
				if (!PyLong_CheckExact(p)) {
					PyErr_SetString(PyExc_RuntimeError, "Invalid object in plot arrangement list [sendInit]");
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

PyObject * RecFn_Data(PyObject * self, PyObject * args)
{
	unsigned int nGraph = 0, argc = 2;
	double *d = new double[32]();

	if (!PyArg_ParseTuple(args, "II|dddddddddddddddddddddddddddddddd", &nGraph, &argc,
		&d[0], &d[1], &d[2], &d[3], &d[4], &d[5], &d[6], &d[7], &d[8], &d[9], &d[10], &d[11], &d[12], &d[13], &d[14], &d[15],
		&d[16], &d[17], &d[18], &d[19], &d[20], &d[21], &d[22], &d[23], &d[24], &d[25], &d[26], &d[27], &d[28], &d[29], &d[30], &d[31])) {
		free(d);
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_Data(nGraph, argc, d);
	Py_RETURN_NONE;
}

PyObject * RecFn_XData(PyObject * self, PyObject * args)
{
	unsigned int nGraph = 0;
	PyObject *dataX = NULL, *dataY = NULL, *pyBool = NULL;
	Py_ssize_t dataX_sz, dataY_sz, data_sz;
	QVector<double> *dx;
	QVector<double> *dy;
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

PyObject * RecFn_DataInfo(PyObject * self, PyObject * args)
{
	unsigned int id = 0;
	const char *info = NULL;

	if (!PyArg_ParseTuple(args, "Is", &id, &info)) {
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_DataInfo(id, QString(info));
	Py_RETURN_NONE;
}

PyObject * RecFn_DataFileInfo(PyObject * self, PyObject * args)
{
	const char *info = NULL;

	if (!PyArg_ParseTuple(args, "s", &info)) {
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_DataFileInfo(QString(info));
	Py_RETURN_NONE;
}

PyObject * RecFn_Plot2DProp(PyObject * self, PyObject * args)
{
	unsigned int pIdx = 0;
	const char *c_p = NULL;
	const char *c_v = NULL;

	if (!PyArg_ParseTuple(args, "Iss", &pIdx, &c_p, &c_v)) {
		return NULL;
	}

	QString p = c_p == NULL ? QString("") : QString(c_p);
	QString v = c_v == NULL ? QString("") : QString(c_v);

	emit QPyEngineInterface::hInstance->Signal_PlotProperty2D(pIdx, p, v);
	Py_RETURN_NONE;
}

PyObject * RecFn_PlotCMProp(PyObject * self, PyObject * args)
{
	unsigned int pIdx = 0;
	const char *c_p = NULL;
	const char *c_v = NULL;

	if (!PyArg_ParseTuple(args, "Iss", &pIdx, &c_p, &c_v)) {
		return NULL;
	}

	QString p = c_p == NULL ? QString("") : QString(c_p);
	QString v = c_v == NULL ? QString("") : QString(c_v);

	emit QPyEngineInterface::hInstance->Signal_PlotPropertyCM(pIdx, p, v);
	Py_RETURN_NONE;
}

PyObject * RecFn_Save(PyObject * self, PyObject * args)
{
	unsigned int dataID = 0;
	const char *dataHeader = NULL;

	if (!PyArg_ParseTuple(args, "I|s", &dataID, &dataHeader)) {
		return NULL;
	}

	QString dataHeaderStr = dataHeader == NULL ? "" : QString(dataHeader);

	emit QPyEngineInterface::hInstance->Signal_SaveData(dataID, dataHeaderStr);
	Py_RETURN_NONE;
}

PyObject * RecFn_Clear(PyObject * self, PyObject * args)
{
	unsigned int dataID = 0;

	if (!PyArg_ParseTuple(args, "I", &dataID)) {
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_ClearData(dataID);
	Py_RETURN_NONE;
}

PyObject * RecFn_CMData(PyObject * self, PyObject * args)
{
	unsigned int graphID = 0, xIdx = 0, yIdx = 0;
	double z = 0;

	if (!PyArg_ParseTuple(args, "IIId", &graphID, &xIdx, &yIdx, &z)) {
		return NULL;
	}

	emit QPyEngineInterface::hInstance->Signal_CMData(graphID, xIdx, yIdx, z);
	Py_RETURN_NONE;
}

PyObject * RecFn_CMSetup(PyObject * self, PyObject * args)
{
	unsigned int graphID = 0, xSize = 0, ySize = 0;
	double xMin = 0, xMax = 0, yMin = 0, yMax = 0;
	PyObject *pyBool = NULL;
	bool show = true;

	if (!PyArg_ParseTuple(args, "IddddII|O", &graphID, &xMin, &xMax, &yMin, &yMax, &xSize, &ySize, &pyBool)) {
		return NULL;
	}

	if (pyBool != NULL) {
		int pyBoolVal = PyObject_IsTrue(pyBool);
		if (pyBoolVal < 0) {
			PyErr_SetString(PyExc_RuntimeError, "Could not parse bool value [setupCM]");
			return NULL;
		}
		if (pyBoolVal == 0)
			show = false;
	}

	emit QPyEngineInterface::hInstance->Signal_CMSetup(graphID, xMin, xMax, yMin, yMax, xSize, ySize, show);
	Py_RETURN_NONE;
}

PyObject * RecFn_CMShow(PyObject * self, PyObject * args)
{
	unsigned int graphID = 0;
	PyObject *pyBool = NULL;
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

PyObject * RecFn_CFName(PyObject * self, PyObject * args)
{
	unsigned int fnNumber = 0;
	const char *fnName = NULL;

	if (!PyArg_ParseTuple(args, "Is", &fnNumber, &fnName)) {
		return NULL;
	}

	QString newName = fnName == NULL ? QString("") : QString(fnName);

	emit QPyEngineInterface::hInstance->Signal_CustomFnName(fnNumber, newName);
	Py_RETURN_NONE;
}

PyObject * RecFn_ASFile(PyObject * self, PyObject * args)
{
	PyObject *pyBool = NULL;
	const char *fileName = NULL;
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

PyObject * RecFn_PlotSetup(PyObject * self, PyObject * args)
{
	PyObject * plotArrng = NULL;

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
			PyObject *p = PyList_GetItem(listItem, j);
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