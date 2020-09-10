#pragma once

#include <QObject>
#include <QString>
#include <QStringList>
#include <QHash>
#include "AppMainWindow.h"
#include "AutoSaveDialog.h"
#include "CustomControlEditorDialog.h"
#include "DataInfoDialog.h"
#include "ErrorLogDialog.h"
#include "ModuleInfoDialog.h"
#include "PlotEditorDialog.h"
#include "SaveDialog.h"
#include "SettingsDialog.h"
#include "VisaSetupDialog.h"

class AppUI : public QObject
{
	Q_OBJECT

public:
	enum class UI_ERR_CODE {
		NONE,
		UNDEFINED_ERROR,
		PLOT_EDITOR_INDEX_OUT_OF_RANGE,
		PLOT_EDITOR_NO_SUCH_VALUE,
		PLOT_EDITOR_NO_SUCH_PROPERTY,
		PLOTARRANGE_INVALID_SIZE,
		PLOTARRANGE_INVALID_VALUE
	};

	AppUI(QObject *parent = Q_NULLPTR);
	~AppUI();

	void Setup(DataManager *dataManager, AppConfig *config, AppSettings *settings);
	void AddExampleScript(unsigned int scriptID, const QString& script);
	void UpdateConfig();
	void Show_MainWindow();

	void SetScriptStatus(const QString& scriptStatus, bool append);
	void ClearScriptStatus();

	void SetErrorStatus(const QString& errorStatus);
	void ClearErrorLog();

	void SetScriptParameterKeys(const QStringList& k);
	QVector<std::pair<QString, QString>> GetScriptParameterVals() const;
	void SetScriptParameterVals(const QVector<std::pair<QString, QString>>& p);
	void ClearScriptParameters();

	void SetVisaOptions(const QStringList& visaOptions);
	void GetVisaOptions(QStringList& visaOptions);

	void ClearModuleInfo();
	void SetModuleInfoCurrentModule(const QString& currentModule);
	void SetModuleInfoScriptParameters(const QString& scriptParameters);

	QString GetUser() const;
	QString GetNotes() const;

	void SetDataFileInfo(const QString&);
	QString GetDataFileInfo() const;
	void SetDataSetInfo(int, const QString&);
	QString GetDataSetInfo(int) const;
	void SetDataSetBuffering(int, bool);

	void SetCustomControl(size_t, const QString&);

	void EnableControl_Load(bool);
	void EnableControl_Run(bool);
	void EnableControl_Stop(bool);
	void EnableControl_Custom(size_t, bool);
	void EnableAutoSave(bool);

	void OpenAutoSaveDialog();
	void CloseSaveDialog(bool);

	QGridLayout * PlotLayout() const { return this->mainWindow->PlotLayout(); }
	UI_ERR_CODE EditPlotProperty(size_t plotIdx, PlotType type, const QString& prop, const QString& val);
	UI_ERR_CODE SetupColormap(size_t plotIdx, double xMin, double xMax, double yMin, double yMax, int xSize, int ySize, bool zRange, double zMin, double zMax);
	UI_ERR_CODE ShowColormap(size_t plotIdx, bool show);
	UI_ERR_CODE SetPlotArrangement(const QVector<GridPoint>& plotArrangement);
	UI_ERR_CODE GetPlotProperties(size_t plotIdx, PlotProperties& plotProperties) const;
	void GetPlotMinSize(int& w, int& h) const;
	
Q_SIGNALS:
	void Signal_LoadModule(const QString& filename);
	void Signal_RunModule();
	void Signal_StopModule();
	void Signal_CustomControl(unsigned int cc);
	void Signal_CreateNewScript(const QString& filename);
	void Signal_ParamsImport(const QString& filename);
	void Signal_ParamsExport(const QString& filename);
	void Signal_PlotEditor_UpdateArrangement(const QVector<GridPoint>& plotArrangement);
	void Signal_PlotEditor_UpdateProperties(const QVector<size_t>& plotUpdateQueue);
	void Signal_UpdateDataInfo(const QString& dataInfo, const QVector<std::pair<bool, QString>>& dataSetInfo);
	void Signal_UpdatePythonPath();
	void Signal_Save(const QString&, const QVector<bool>&, bool timeStamp);
	void Signal_ExampleScript(unsigned int scriptID);

private:
	AppMainWindow * mainWindow;
	PlotEditorDialog * plotEditorDialog;
	ErrorLogDialog * errorLogDialog;
	CustomControlEditorDialog * customControlEditorDialog;
	VisaSetupDialog * visaSetupDialog;
	ModuleInfoDialog * moduleInfoDialog;
	SettingsDialog * settingsDialog;
	DataInfoDialog * dataInfoDialog;
	SaveDialog * saveDialog;
	AutoSaveDialog * autoSaveDialog;

	QHash<QString, PlotEditorDialog::PlotEditError(PlotEditorDialog::*)(size_t, const QString&)> editablePlotProperties_2D;
	QHash<QString, PlotEditorDialog::PlotEditError(PlotEditorDialog::*)(size_t, const QString&)> editablePlotProperties_CM;

private Q_SLOTS:
	void Slot_UpdatePlotArrangement(const QVector<GridPoint>& pa);
};