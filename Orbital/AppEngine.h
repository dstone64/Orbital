#pragma once

#include "QPyEngineInterface.h"
#include "AppUI.h"
#include "PlotManager.h"
#include "DataManager.h"
#include <string>
#include <unordered_set>
#include <vector>
#include <QObject>
#include <QtWidgets/QApplication>
#include <QString>
#include <QVector>

class AppEngine : public QObject
{
	Q_OBJECT

public:
    AppEngine(int argc, char *argv[]);
    ~AppEngine();

    int Exec();

public Q_SLOTS:
// PyEngine Slots
	void Slot_Error(const QString& errMsg);
	void Slot_Msg(const QString&, bool);
	void Slot_ScriptInitialize(unsigned int, const QStringList&, const QStringList&);
	void Slot_ScriptInitializeEx(const QVector<GridPoint>&, const QStringList&, const QStringList&);
	void Slot_Data(unsigned int, unsigned int, double[32]);
	void Slot_XData(unsigned int, QVector<double>*, QVector<double>*, bool);
	void Slot_DataInfo(unsigned int, const QString&);
	void Slot_DataFileInfo(const QString&);
	void Slot_PlotProperty2D(unsigned int, const QString&, const QString&);
	void Slot_PlotPropertyCM(unsigned int, const QString&, const QString&);
	void Slot_SaveData(unsigned int, const QString&);
	void Slot_ClearData(unsigned int);
	void Slot_CMData(unsigned int, unsigned int, unsigned int, double);
	void Slot_CMDataRow(unsigned int, unsigned int, QVector<double>*);
	void Slot_CMSetup(unsigned int, double, double, double, double, unsigned int, unsigned int, bool, double, double, bool);
	void Slot_CMShow(unsigned int, bool);
	void Slot_CustomFnName(unsigned int, const QString&);
	void Slot_AutoSaveConfig(bool, const QString&);
	void Slot_PlotArrangement(const QVector<GridPoint>&);

	void Slot_RetFn_Init(int);
	void Slot_RetFn_Run(int);
	void Slot_RetFn_Stop(int);
	void Slot_RetFn_Custom1(int);
	void Slot_RetFn_Custom2(int);
	void Slot_RetFn_Custom3(int);
	void Slot_RetFn_Custom4(int);
	void Slot_RetFn_Custom5(int);
	void Slot_RetFn_Custom6(int);
	void Slot_RetFn_Custom7(int);
	void Slot_RetFn_Custom8(int);

// UI Slots
	void Slot_LoadModule(const QString& filename);
	void Slot_RunModule();
	void Slot_StopModule();
	void Slot_CustomControl(size_t cc);
	void Slot_CreateNewScript(const QString& filename);
	void Slot_ExampleScript(unsigned int scriptID);
	void Slot_ReferenceManual();
	void Slot_ParamsImport(const QString& filename);
	void Slot_ParamsExport(const QString& filename);
	void Slot_PlotEditor_UpdateArrangement(const QVector<GridPoint>& plotArrangement);
	void Slot_PlotEditor_UpdateProperties(const QVector<size_t>& plotUpdateQueue);
	void Slot_UpdateDataInfo(const QString& dataInfo, const QVector<std::pair<bool, QString>>& dataSetInfo);
	void Slot_UpdatePythonPath();
	void Slot_Save(const QString& file, const QVector<bool>& dataToSave, bool timeStamp);

private:
	void ErrorOutput(const std::string& s);
	void ScriptInitialize_Params(const QStringList& scriptParameters);
	void ScriptParameters_Import(const std::string& filename);
	void ScriptParameters_Export(const std::string& filename);
	QString BuildScriptArguments(std::vector<std::pair<std::string, std::string>>& scriptArguments) const;
	void UpdatePythonPath();
	void SetupExampleScripts();
	void EditPlotProperty(PlotType pt, unsigned int pIdx, const QString& prop, const QString& val);
	void SetPlotArrangement(const QVector<GridPoint>& plotArrangement);
	bool Save(const std::string& file, const QVector<bool>& dataSets);
	bool AutoSave(const std::string& file, size_t dataIdx, const std::string& autoSaveHeader);
	void GenerateAutoSaveFile(bool writeHeader);
	void WriteToFile_Header(std::ofstream&);
	void WriteToFile_SaveData(std::ofstream&, const QVector<bool>& dataSetsToSave);
	void WriteToFile_AutoSave(std::ofstream&, size_t, const std::string&);
	std::string UserHeader() const;

    QApplication a;
	AppUI appUI;
	QPyEngineInterface pyEngine;
	PlotManager * plotManager;
	DataManager dataManager;
	AppConfig config;
	AppSettings settings;
	std::vector<QString> scriptParameterKeys;
	std::string userHeader;
	bool autoSaveFlag;
	std::string autoSaveFile;
	std::unordered_set<std::string> pythonPathVar;
	std::vector<QString> exampleScripts;
};