#pragma once

#include <QtWidgets/QMainWindow>
#include <QStringList>
#include <array>
#include <utility>
#include "ui_AppMainWindow.h"
#include "commondefine.h"

class AppMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	AppMainWindow(QWidget *parent = Q_NULLPTR);
	~AppMainWindow() {}

	QGridLayout * PlotLayout() const { return this->plotLayout; }
	QAction *Action_PlotEditor() { return this->ui.actionPlot_Editor; }
	QAction *Action_ErrorLog() { return this->ui.actionError_Log; }
	QAction *Action_CustomControlEditor() { return this->ui.actionCustom_Controls; }
	QAction *Action_VisaSetup() { return this->ui.actionVisa_Setup; }
	QAction *Action_ModuleInfo() { return this->ui.actionCurrent_Module; }
	QAction *Action_Settings() { return this->ui.actionSettings; }
	QAction *Action_DataInfo() { return this->ui.actionData_Info; }
	void AddExampleScript(unsigned int scriptID, const QString& script);
	void SetCustomControl(size_t, const QString&);
	void SetCustomControls(const QStringList& customControls);
	void SetScriptStatus(const QString& scriptStatus, bool append);
	void ClearScriptStatus();
	void SetErrorStatus(const QString& errorStatus);
	void ClearErrorStatus();
	void SetScriptParameterKeys(const QStringList&);
	QVector<std::pair<QString, QString>> GetScriptParameterVals() const;
	void SetScriptParameterVals(const QVector<std::pair<QString, QString>>&);
	void ClearScriptParameters();
	void EnableControl_Load(bool);
	void EnableControl_Run(bool);
	void EnableControl_Stop(bool);
	void EnableControl_Custom(size_t, bool);
	void EnableAutoSave(bool);
	QString GetUser() const;
	QString GetNotes() const;

Q_SIGNALS:
	void Signal_LoadModule(const QString& filename);
	void Signal_RunModule();
	void Signal_StopModule();
	void Signal_CustomControl(unsigned int cc);
	void Signal_Save();
	void Signal_CreateNewScript(const QString& filename);
	void Signal_ParamsImport(const QString& filename);
	void Signal_ParamsExport(const QString& filename);
	void Signal_ExampleScript(unsigned int id);

public Q_SLOTS:
	void on_pushButton_load_clicked();
	void on_pushButton_run_clicked();
	void on_pushButton_stop_clicked();
	void on_pushButton_customControl_clicked(unsigned int cc);
	void on_pushButton_save_clicked();
	void on_pushButton_importParams_clicked();
	void on_pushButton_exportParams_clicked();
	void Slot_CreateNewScript();

private:
	void PlotPanelSetup();
	void CustomControlPanelSetup();

	Ui::AppMainWindowClass ui;
	QGridLayout *plotLayout;
	std::array<QPushButton*, N_CUSTOMCONTROLS> customControls;
	QVector<QAction*> exampleScripts;
};
