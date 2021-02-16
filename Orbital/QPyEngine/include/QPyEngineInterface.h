#pragma once

#include <atomic>
#include "QPyEngine.h"
#include <QStringList>
#include <QVector>
#include "GridPoint.h"

#define RECFN_MSG          "msg"                 // sendMsg(msg, append=False)
#define RECFN_INIT         "init"                // sendInit(n_plots/plot_arrangement, parameters, visa_resources=Null)
#define RECFN_DATA         "sendData"            // sendData(data_set, n_data, data0, data1, ...)
#define RECFN_XDATA        "sendXData"           // sendXData(data_set, x_data, y_data, save=True)
#define RECFN_DATAINFO     "setDataInfo"         // setDataInfo(data_set, info)
#define RECFN_DATAFILEINFO "setDataFileInfo"     // setDataFileInfo(info)
#define RECFN_PLOT2DPROP   "set2DPlotProperty"   // set2DPlotProperty(plot_id, plot_property, new_value)
#define RECFN_PLOTCMPROP   "setColormapProperty" // setColormapProperty(plot_id, colormap_property, new_value)
#define RECFN_SAVE         "saveData"            // saveData(data_set, data_header)
#define RECFN_CLEAR        "clearData"           // clearData(data_set)
#define RECFN_CMDATA       "sendCMData"          // sendCMData(plot_id, x, y, val)
#define RECFN_CMDATAROW    "sendCMDataRow"       // sendCMDataRow(plot_id, row, z_vals)
#define RECFN_CMSETUP      "setupColormap"       // setupCM(plot_id, xMin, xMax, yMin, yMax, xSize, ySize, show=True)
#define RECFN_CMSHOW       "showColormap"        // showColormap(plot_id, show=True)
#define RECFN_CFNAME       "renameCustom"        // renameCustom(customFn, new_name)
#define RECFN_ASFILE       "setAutoSave"         // setAutoSave()
#define RECFN_PLOTSETUP    "setPlotArrangement"  // setPlotArrangement(plot_arrangement)
#define FN_INIT    "init"
#define FN_RUN     "run"
#define FN_STOP    "stop"
#define FN_CUSTOM1 "customFn1"
#define FN_CUSTOM2 "customFn2"
#define FN_CUSTOM3 "customFn3"
#define FN_CUSTOM4 "customFn4"
#define FN_CUSTOM5 "customFn5"
#define FN_CUSTOM6 "customFn6"
#define FN_CUSTOM7 "customFn7"
#define FN_CUSTOM8 "customFn8"

class QPyEngineInterface : public QObject
{
	Q_OBJECT

public:
	QPyEngineInterface(QObject* parent);
	~QPyEngineInterface();

	static QPyEngineInterface* hInstance;
	static void RetFn_Init(PyObject* ret, QString& errStr);
	static void RetFn_Run(PyObject* ret, QString& errStr);
	static void RetFn_Stop(PyObject* ret, QString& errStr);
	static void RetFn_Custom1(PyObject* ret, QString& errStr);
	static void RetFn_Custom2(PyObject* ret, QString& errStr);
	static void RetFn_Custom3(PyObject* ret, QString& errStr);
	static void RetFn_Custom4(PyObject* ret, QString& errStr);
	static void RetFn_Custom5(PyObject* ret, QString& errStr);
	static void RetFn_Custom6(PyObject* ret, QString& errStr);
	static void RetFn_Custom7(PyObject* ret, QString& errStr);
	static void RetFn_Custom8(PyObject* ret, QString& errStr);

	int Load(const QString& moduleFile);
	int Reload();
	int Init();
	int Run(std::vector<std::pair<std::string, std::string>>& args);
	int Stop();
	int Custom(size_t n);
	void AppendPythonPath(const std::string& path);

Q_SIGNALS:
	void Signal_Error(const QString&);

	void Signal_RetFn_Init(int);
	void Signal_RetFn_Run(int);
	void Signal_RetFn_Stop(int);
	void Signal_RetFn_Custom1(int);
	void Signal_RetFn_Custom2(int);
	void Signal_RetFn_Custom3(int);
	void Signal_RetFn_Custom4(int);
	void Signal_RetFn_Custom5(int);
	void Signal_RetFn_Custom6(int);
	void Signal_RetFn_Custom7(int);
	void Signal_RetFn_Custom8(int);

	void Signal_Msg(const QString&, bool);
	void Signal_ScriptInitialize(unsigned int, const QStringList&, const QStringList&);
	void Signal_ScriptInitializeEx(const QVector<GridPoint>&, const QStringList&, const QStringList&);
	void Signal_Data(unsigned int, unsigned int, double*);
	void Signal_XData(unsigned int, QVector<double>*, QVector<double>*, bool);
	void Signal_DataInfo(unsigned int, const QString&);
	void Signal_DataFileInfo(const QString&);
	void Signal_PlotProperty2D(unsigned int, const QString&, const QString&);
	void Signal_PlotPropertyCM(unsigned int, const QString&, const QString&);
	void Signal_SaveData(unsigned int, const QString&);
	void Signal_ClearData(unsigned int);
	void Signal_CMData(unsigned int, unsigned int, unsigned int, double);
	void Signal_CMDataRow(unsigned int, unsigned int, QVector<double>*);
	void Signal_CMSetup(unsigned int, double, double, double, double, unsigned int, unsigned int, bool, double, double, bool);
	void Signal_CMShow(unsigned int, bool);
	void Signal_CustomFnName(unsigned int, QString);
	void Signal_AutoSaveConfig(bool, QString);
	void Signal_PlotArrangement(const QVector<GridPoint>&);

private:
	int Call(const char* funcName, PyObject* args, QPyEngine_RetFn retFn);
	QPyEngine::Module* pyModule;
};

extern "C" {
	PyObject* RecFn_Msg(PyObject* self, PyObject* args);
	PyObject* RecFn_Init(PyObject* self, PyObject* args);
	PyObject* RecFn_Data(PyObject* self, PyObject* args);
	PyObject* RecFn_XData(PyObject* self, PyObject* args);
	PyObject* RecFn_DataInfo(PyObject* self, PyObject* args);
	PyObject* RecFn_DataFileInfo(PyObject* self, PyObject* args);
	PyObject* RecFn_Plot2DProp(PyObject* self, PyObject* args);
	PyObject* RecFn_PlotCMProp(PyObject* self, PyObject* args);
	PyObject* RecFn_Save(PyObject* self, PyObject* args);
	PyObject* RecFn_Clear(PyObject* self, PyObject* args);
	PyObject* RecFn_CMData(PyObject* self, PyObject* args);
	PyObject* RecFn_CMDataRow(PyObject* self, PyObject* args);
	PyObject* RecFn_CMSetup(PyObject* self, PyObject* args);
	PyObject* RecFn_CMShow(PyObject* self, PyObject* args);
	PyObject* RecFn_CFName(PyObject* self, PyObject* args);
	PyObject* RecFn_ASFile(PyObject* self, PyObject* args);
	PyObject* RecFn_PlotSetup(PyObject* self, PyObject* args);
}