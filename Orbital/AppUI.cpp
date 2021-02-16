#include "AppUI.h"
#include "commondefine.h"

AppUI::AppUI(QObject *parent) :
	QObject(parent),
	editablePlotProperties_2D({
		{ PLOTPROPERTY_TITLE, &PlotEditorDialog::EditPlot_Title2D },
		{ PLOTPROPERTY_LABELX, &PlotEditorDialog::EditPlot_XLabel2D },
		{ PLOTPROPERTY_LABELY, &PlotEditorDialog::EditPlot_YLabel2D },
		{ PLOTPROPERTY_LINESTYLE, &PlotEditorDialog::EditPlot_LineStyle },
		{ PLOTPROPERTY_SCATSTYLE, &PlotEditorDialog::EditPlot_ScatterStyle },
		{ PLOTPROPERTY_SCATSIZE, &PlotEditorDialog::EditPlot_ScatterSize },
		{ PLOTPROPERTY_COLOR, &PlotEditorDialog::EditPlot_Color }}),
	editablePlotProperties_CM({
		{ PLOTPROPERTY_TITLE, &PlotEditorDialog::EditPlot_TitleCM },
		{ PLOTPROPERTY_LABELX, &PlotEditorDialog::EditPlot_XLabelCM },
		{ PLOTPROPERTY_LABELY, &PlotEditorDialog::EditPlot_YLabelCM },
		{ PLOTPROPERTY_LABELZ, &PlotEditorDialog::EditPlot_ZLabel },
		{ PLOTPROPERTY_COLORMIN, &PlotEditorDialog::EditPlot_ColorMin },
		{ PLOTPROPERTY_COLORMID, &PlotEditorDialog::EditPlot_ColorMid },
		{ PLOTPROPERTY_COLORMAX, &PlotEditorDialog::EditPlot_ColorMax }})
{
	this->mainWindow = new AppMainWindow();
	this->plotEditorDialog = new PlotEditorDialog(this->mainWindow);
	this->errorLogDialog = new ErrorLogDialog(this->mainWindow);
	this->customControlEditorDialog = new CustomControlEditorDialog(this->mainWindow);
	this->visaSetupDialog = new VisaSetupDialog(this->mainWindow);
	this->moduleInfoDialog = new ModuleInfoDialog(this->mainWindow);
	this->settingsDialog = new SettingsDialog(this->mainWindow);
	this->dataInfoDialog = new DataInfoDialog(this->mainWindow);
	this->saveDialog = new SaveDialog(this->mainWindow);
	this->autoSaveDialog = new AutoSaveDialog(this->mainWindow);

	QObject::connect(this->mainWindow, &AppMainWindow::Signal_LoadModule, [=](const QString& f) { emit Signal_LoadModule(f); });
	QObject::connect(this->mainWindow, &AppMainWindow::Signal_RunModule, [=] { emit Signal_RunModule(); });
	QObject::connect(this->mainWindow, &AppMainWindow::Signal_StopModule, [=] { emit Signal_StopModule(); });
	QObject::connect(this->mainWindow, &AppMainWindow::Signal_CustomControl, [=](unsigned int n) { emit Signal_CustomControl(n); });
	QObject::connect(this->mainWindow, &AppMainWindow::Signal_CreateNewScript, [=](const QString& f) { emit Signal_CreateNewScript(f); });
	QObject::connect(this->mainWindow, &AppMainWindow::Signal_ParamsImport, [=](const QString& f) { emit Signal_ParamsImport(f); });
	QObject::connect(this->mainWindow, &AppMainWindow::Signal_ParamsExport, [=](const QString& f) { emit Signal_ParamsExport(f); });
	QObject::connect(this->mainWindow, &AppMainWindow::Signal_ExampleScript, [=](unsigned int n) { emit Signal_ExampleScript(n); });
	QObject::connect(this->mainWindow, &AppMainWindow::Signal_ReferenceManual, [=] { emit Signal_ReferenceManual(); });

	QObject::connect(this->mainWindow->Action_PlotEditor(), &QAction::triggered, this->plotEditorDialog, &PlotEditorDialog::open);
	QObject::connect(this->mainWindow->Action_ErrorLog(), &QAction::triggered, this->errorLogDialog, &ErrorLogDialog::open);
	QObject::connect(this->mainWindow->Action_CustomControlEditor(), &QAction::triggered, this->customControlEditorDialog, &CustomControlEditorDialog::open);
	QObject::connect(this->mainWindow->Action_VisaSetup(), &QAction::triggered, this->visaSetupDialog, &VisaSetupDialog::open);
	QObject::connect(this->mainWindow->Action_ModuleInfo(), &QAction::triggered, this->moduleInfoDialog, &ModuleInfoDialog::open);
	QObject::connect(this->mainWindow->Action_Settings(), &QAction::triggered, this->settingsDialog, &SettingsDialog::open);
	QObject::connect(this->mainWindow->Action_DataInfo(), &QAction::triggered, this->dataInfoDialog, &DataInfoDialog::open);
	QObject::connect(this->mainWindow, &AppMainWindow::Signal_Save, this->saveDialog, &SaveDialog::open);

	QObject::connect(this->customControlEditorDialog, &CustomControlEditorDialog::Signal_CustomControlsUpdated, [=] { this->mainWindow->SetCustomControls(this->customControlEditorDialog->CustomControlNames()); });
	QObject::connect(this->plotEditorDialog, &PlotEditorDialog::Signal_UpdatePlotArrangement, this, &AppUI::Slot_UpdatePlotArrangement);
	QObject::connect(this->plotEditorDialog, &PlotEditorDialog::Signal_UpdatePlotProperties, [=](const QVector<size_t>& p) { emit Signal_PlotEditor_UpdateProperties(p); });
	QObject::connect(this->dataInfoDialog, &DataInfoDialog::Signal_UpdateDataInfo, [=](const QString& d, const QVector<std::pair<bool, QString>>& ds) { emit Signal_UpdateDataInfo(d, ds); });
	QObject::connect(this->settingsDialog, &SettingsDialog::Signal_UpdatePythonPath, [=] { emit Signal_UpdatePythonPath(); });
	QObject::connect(this->saveDialog, &SaveDialog::Signal_Save, [=](const QString& f, const QVector<bool>& d, bool t) { emit Signal_Save(f, d, t); });

	this->mainWindow->EnableControl_Load(true);
	this->mainWindow->EnableControl_Run(false);
	this->mainWindow->EnableControl_Stop(false);
	this->mainWindow->EnableControl_Custom(0, false);
}

AppUI::~AppUI()
{
	delete this->mainWindow;
}

void AppUI::Setup(DataManager *dataManager, AppConfig *config, AppSettings *settings)
{
	this->dataInfoDialog->Setup(dataManager);
	this->saveDialog->Setup(dataManager);
	this->customControlEditorDialog->Setup(config);
	this->settingsDialog->Setup(settings);
	this->autoSaveDialog->Setup(settings);
	this->mainWindow->SetCustomControls(this->customControlEditorDialog->CustomControlNames());
}

void AppUI::AddExampleScript(unsigned int scriptID, const QString& script)
{
	this->mainWindow->AddExampleScript(scriptID, script);
}

void AppUI::UpdateConfig()
{
	this->customControlEditorDialog->UpdateConfig();
}

void AppUI::Show_MainWindow()
{
	return this->mainWindow->show();
}

void AppUI::SetScriptStatus(const QString& scriptStatus, bool append)
{
	this->mainWindow->SetScriptStatus(scriptStatus, append);
}

void AppUI::ClearScriptStatus()
{
	this->mainWindow->ClearScriptStatus();
}

void AppUI::SetErrorStatus(const QString& errorStatus)
{
	this->mainWindow->SetErrorStatus(errorStatus);
	this->errorLogDialog->Append(errorStatus);
}

void AppUI::ClearErrorLog()
{
	this->mainWindow->ClearErrorStatus();
	this->errorLogDialog->Clear();
}

void AppUI::SetScriptParameterKeys(const QStringList& k)
{
	this->mainWindow->SetScriptParameterKeys(k);
}

QVector<std::pair<QString, QString>> AppUI::GetScriptParameterVals() const
{
	return this->mainWindow->GetScriptParameterVals();
}

void AppUI::SetScriptParameterVals(const QVector<std::pair<QString, QString>>& p)
{
	this->mainWindow->SetScriptParameterVals(p);
}

void AppUI::ClearScriptParameters()
{
	this->mainWindow->ClearScriptParameters();
}

void AppUI::SetVisaOptions(const QStringList& visaOptions)
{
	this->visaSetupDialog->GenerateVisaEntries(visaOptions);
}

void AppUI::GetVisaOptions(QStringList& visaOptions)
{
	visaOptions = this->visaSetupDialog->VisaAssignments();
}

void AppUI::ClearModuleInfo()
{
	this->moduleInfoDialog->Clear();
}

void AppUI::SetModuleInfoCurrentModule(const QString& currentModule)
{
	this->moduleInfoDialog->UpdateModuleFile(currentModule);
}

void AppUI::SetModuleInfoScriptParameters(const QString& scriptParameters)
{
	this->moduleInfoDialog->UpdateScriptParameters(scriptParameters);
}

QString AppUI::GetUser() const
{
	return this->mainWindow->GetUser();
}

QString AppUI::GetNotes() const
{
	return this->mainWindow->GetNotes();
}

void AppUI::SetDataFileInfo(const QString& info)
{
	this->dataInfoDialog->SetDataFileInfo(info);
}

QString AppUI::GetDataFileInfo() const
{
	return this->dataInfoDialog->GetDataFileInfo();
}

void AppUI::SetDataSetInfo(int n, const QString& info)
{
	this->dataInfoDialog->SetDataSetInfo(n, info);
}

QString AppUI::GetDataSetInfo(int n) const
{
	return this->dataInfoDialog->GetDataSetInfo(n);
}

void AppUI::SetDataSetBuffering(int n, bool buffer)
{
	this->dataInfoDialog->SetDataSetBuffering(n, buffer);
}

void AppUI::SetCustomControl(size_t n, const QString& label)
{
	this->mainWindow->SetCustomControl(n, label);
	this->customControlEditorDialog->SetName(n, label);
}

void AppUI::EnableControl_Load(bool enable)
{
	this->mainWindow->EnableControl_Load(enable);
}

void AppUI::EnableControl_Run(bool enable)
{
	this->mainWindow->EnableControl_Run(enable);
}

void AppUI::EnableControl_Stop(bool enable)
{
	this->mainWindow->EnableControl_Stop(enable);
}

void AppUI::EnableControl_Custom(size_t n, bool enable)
{
	this->mainWindow->EnableControl_Custom(n, enable);
}

void AppUI::EnableAutoSave(bool enable)
{
	this->mainWindow->EnableAutoSave(enable);
}

void AppUI::OpenAutoSaveDialog()
{
	this->autoSaveDialog->exec();
}

void AppUI::CloseSaveDialog(bool saveError)
{
	this->saveDialog->Close(saveError);
}

AppUI::UI_ERR_CODE AppUI::EditPlotProperty(size_t plotIdx, PlotType type, const QString& prop, const QString& val)
{
	PlotEditorDialog::PlotEditError(PlotEditorDialog::*editFn)(size_t, const QString&) = nullptr;
	switch (type) {
	case PlotType::TWODIMSN:
		editFn = this->editablePlotProperties_2D.value(prop, nullptr); break;
	case PlotType::COLORMAP:
		editFn = this->editablePlotProperties_CM.value(prop, nullptr); break;
	}
	if (editFn == nullptr)
		return UI_ERR_CODE::PLOT_EDITOR_NO_SUCH_PROPERTY;

	switch ((this->plotEditorDialog->*editFn)(plotIdx, val)) {
	case PlotEditorDialog::PlotEditError::NONE:
		return UI_ERR_CODE::NONE;
	case PlotEditorDialog::PlotEditError::INDEX_OUT_OF_RANGE:
		return UI_ERR_CODE::PLOT_EDITOR_INDEX_OUT_OF_RANGE;
	case PlotEditorDialog::PlotEditError::NO_SUCH_VALUE:
		return UI_ERR_CODE::PLOT_EDITOR_NO_SUCH_VALUE;
	default:
		break;
	}

	return UI_ERR_CODE::UNDEFINED_ERROR;
}

AppUI::UI_ERR_CODE AppUI::SetupColormap(size_t plotIdx, double xMin, double xMax, double yMin, double yMax, int xSize, int ySize, bool zRange, double zMin, double zMax)
{
	switch (this->plotEditorDialog->EditPlot_SetupCM(plotIdx, xMin, xMax, yMin, yMax, xSize, ySize, zRange, zMin, zMax)) {
	case PlotEditorDialog::PlotEditError::NONE:
		return UI_ERR_CODE::NONE;
	case PlotEditorDialog::PlotEditError::INDEX_OUT_OF_RANGE:
		return UI_ERR_CODE::PLOT_EDITOR_INDEX_OUT_OF_RANGE;
	default:
		break;
	}

	return UI_ERR_CODE::UNDEFINED_ERROR;
}

AppUI::UI_ERR_CODE AppUI::ShowColormap(size_t plotIdx, bool show)
{
	switch (this->plotEditorDialog->EditPlot_ShowCM(plotIdx, show)) {
	case PlotEditorDialog::PlotEditError::NONE:
		return UI_ERR_CODE::NONE;
	case PlotEditorDialog::PlotEditError::INDEX_OUT_OF_RANGE:
		return UI_ERR_CODE::PLOT_EDITOR_INDEX_OUT_OF_RANGE;
	default:
		break;
	}

	return UI_ERR_CODE::UNDEFINED_ERROR;
}

AppUI::UI_ERR_CODE AppUI::SetPlotArrangement(const QVector<GridPoint>& plotArrangement)
{
	switch (this->plotEditorDialog->SetPlotArrangement(plotArrangement)) {
	case PlotEditorDialog::PlotEditError::NONE:
		this->dataInfoDialog->SetDataSets(plotArrangement.size() + 1);
		return UI_ERR_CODE::NONE;
	case PlotEditorDialog::PlotEditError::PLOTARRANGE_INVALID_SIZE:
		return UI_ERR_CODE::PLOTARRANGE_INVALID_SIZE;
	case PlotEditorDialog::PlotEditError::PLOTARRANGE_INVALID_VALUE:
		return UI_ERR_CODE::PLOTARRANGE_INVALID_VALUE;
	default:
		break;
	}

	return UI_ERR_CODE::UNDEFINED_ERROR;
}

AppUI::UI_ERR_CODE AppUI::GetPlotProperties(size_t plotIdx, PlotProperties& plotProperties) const
{
	switch (this->plotEditorDialog->GetPlotProperties(plotIdx, plotProperties)) {
	case PlotEditorDialog::PlotEditError::NONE:
		return UI_ERR_CODE::NONE;
	case PlotEditorDialog::PlotEditError::INDEX_OUT_OF_RANGE:
		return UI_ERR_CODE::PLOT_EDITOR_INDEX_OUT_OF_RANGE;
	default:
		break;
	}

	return UI_ERR_CODE::UNDEFINED_ERROR;
}

void AppUI::GetPlotMinSize(int& w, int& h) const
{
	this->plotEditorDialog->GetPlotMinSize(w, h);
}

void AppUI::Slot_UpdatePlotArrangement(const QVector<GridPoint>& pa)
{
	this->dataInfoDialog->SetDataSets(pa.size() + 1);
	emit Signal_PlotEditor_UpdateArrangement(pa);
}