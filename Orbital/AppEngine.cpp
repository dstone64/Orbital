#include "AppEngine.h"
#include <ctime>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>
#include <QFileInfo>
#include <QRegularExpression>
#include "AppConfig.h"

#define QCONNECT_PY(SType) QObject::connect(&this->pyEngine, &QPyEngineInterface::Signal_##SType, this, &AppEngine::Slot_##SType)
#define QCONNECT_UI(SType) QObject::connect(&this->appUI, &AppUI::Signal_##SType, this, &AppEngine::Slot_##SType)

#define SCRIPTDEFAULT L"scripts\\ScriptSkeleton.py"
#define SCRIPTEXAMPLES "scripts\\examples"
#ifdef _DEBUG
#define CONFIGFILE L"..\\Orbital.ini"
#define REFMANUALFILE L"..\\Orbital_rm.pdf"
#else
#define CONFIGFILE L"Orbital.ini"
#define REFMANUALFILE L"Orbital_rm.pdf"
#endif

AppEngine::AppEngine(int argc, char *argv[])
try :
	QObject(Q_NULLPTR),
	a(argc, argv),
	appUI(this),
	pyEngine(this),
	config(CONFIGFILE),
	autoSaveFlag(false)
{
	this->plotManager = new PlotManager(this->appUI.PlotLayout());
	this->settings.Setup(&this->config);
	this->appUI.Setup(&this->dataManager, &this->config, &this->settings);
	UpdatePythonPath();
	SetupExampleScripts();

	QCONNECT_PY(Error);
	QCONNECT_PY(Msg);
	QCONNECT_PY(ScriptInitialize);
	QCONNECT_PY(ScriptInitializeEx);
	QCONNECT_PY(Data);
	QCONNECT_PY(XData);
	QCONNECT_PY(DataInfo);
	QCONNECT_PY(DataFileInfo);
	QCONNECT_PY(PlotProperty2D);
	QCONNECT_PY(PlotPropertyCM);
	QCONNECT_PY(SaveData);
	QCONNECT_PY(ClearData);
	QCONNECT_PY(CMData);
	QCONNECT_PY(CMSetup);
	QCONNECT_PY(CMShow);
	QCONNECT_PY(CustomFnName);
	QCONNECT_PY(AutoSaveConfig);
	QCONNECT_PY(PlotArrangement);

	QCONNECT_PY(RetFn_Init);
	QCONNECT_PY(RetFn_Run);
	QCONNECT_PY(RetFn_Stop);
	QCONNECT_PY(RetFn_Custom1);
	QCONNECT_PY(RetFn_Custom2);
	QCONNECT_PY(RetFn_Custom3);
	QCONNECT_PY(RetFn_Custom4);
	QCONNECT_PY(RetFn_Custom5);
	QCONNECT_PY(RetFn_Custom6);
	QCONNECT_PY(RetFn_Custom7);
	QCONNECT_PY(RetFn_Custom8);

	QCONNECT_UI(LoadModule);
	QCONNECT_UI(RunModule);
	QCONNECT_UI(StopModule);
	QCONNECT_UI(CustomControl);
	QCONNECT_UI(CreateNewScript);
	QCONNECT_UI(ExampleScript);
	QCONNECT_UI(ReferenceManual);
	QCONNECT_UI(PlotEditor_UpdateArrangement);
	QCONNECT_UI(PlotEditor_UpdateProperties);
	QCONNECT_UI(UpdateDataInfo);
	QCONNECT_UI(UpdatePythonPath);
	QCONNECT_UI(Save);

	qRegisterMetaType<QVector<GridPoint>>();
	qRegisterMetaType<QVector<std::pair<bool, QString>>>();
	qRegisterMetaType<QVector<bool>>();
}
catch (std::runtime_error e)
{
	std::cerr << e.what() << std::endl;
}

AppEngine::~AppEngine()
{
	appUI.UpdateConfig();
	settings.UpdateConfig(&this->config);
	config.update();
	delete this->plotManager;
}

int AppEngine::Exec()
{
	this->appUI.Show_MainWindow();
	return this->a.exec();
}

/*
** Displays error messages to the GUI.
*/
void AppEngine::ErrorOutput(const std::string &s)
{
#ifdef _DEBUG
	OutputDebugStringA(s.c_str());
#endif
	this->appUI.SetErrorStatus(QString::fromStdString(s));
}

/*
** Parses the script parameters received from the script's initialization function (sendInit). Each parameter is
**  received in a format to differentiate between the parameter key to be used within the script and the preferred
**  parameter key to be displayed in the GUI: "parameter [preferred (optional)]"
*/
void AppEngine::ScriptInitialize_Params(const QStringList& scriptParameters)
{
	QRegularExpression re("^'(.*)\\[(.*)\\]'$");
	QStringList scriptParameters_preferred;

	this->scriptParameterKeys.clear();
	for (auto itr = scriptParameters.begin(); itr != scriptParameters.end(); ++itr) {
		QRegularExpressionMatch m = re.match(*itr);
		QString key, preferred;
		if (m.hasMatch()) {
			key = m.captured(1).trimmed();
			preferred = m.captured(2);
		}
		else {
			key = QString(*itr).remove(QChar('\''));
			preferred = key;
		}
		this->scriptParameterKeys.push_back(key);
		scriptParameters_preferred.push_back(preferred);
	}

	this->appUI.SetScriptParameterKeys(scriptParameters_preferred);
}

/*
** Import script parameter values from a file.
*/
void AppEngine::ScriptParameters_Import(const std::string& filename)
{
	std::ifstream ifs(filename, std::ifstream::in);
	if (!ifs.is_open()) {
		ErrorOutput("FILE ERROR: Could not open parameter file.\n");
		return;
	}

	QVector<std::pair<QString, QString>> params;
	std::regex re("^(\\w+):(.*)$");
	std::smatch sm;
	for (std::string line; getline(ifs, line); !ifs.eof() && !ifs.fail()) {
		if (std::regex_match(line, sm, re)) {
			params.push_back(std::make_pair(
				QString::fromStdString(sm[1]),
				QString::fromStdString(sm[2])
			));
		}
	}

	ifs.close();
	this->appUI.SetScriptParameterVals(params);
}

/*
** Export script parameter values to a file.
*/
void AppEngine::ScriptParameters_Export(const std::string& filename)
{
	std::ofstream ofs(filename, std::ofstream::out);
	if (!ofs.is_open()) {
		ErrorOutput("FILE ERROR: Could not open parameter file.\n");
		return;
	}

	for (auto p : this->appUI.GetScriptParameterVals()) {
		ofs << p.first.toStdString() << ':' << p.second.toStdString() << '\n';
	}

	ofs.close();
}

QString AppEngine::BuildScriptArguments(std::vector<std::pair<std::string, std::string>>& scriptArgs) const
{
	QVector<std::pair<QString, QString>> scriptParameterVals = this->appUI.GetScriptParameterVals();
	QString scriptArgsStr("{");
	scriptArgs.clear();

	for (size_t i = 0; i < this->scriptParameterKeys.size(); ++i) {
		if (!scriptParameterVals.at(i).second.isEmpty()) {
			scriptArgsStr.append("'" + this->scriptParameterKeys.at(i) + "':'" + scriptParameterVals.at(i).second + "',");
			scriptArgs.push_back(std::make_pair(this->scriptParameterKeys.at(i).toStdString(), scriptParameterVals.at(i).second.toStdString()));
		}
	}

	if (scriptArgsStr.size() > 1)
		scriptArgsStr.remove(scriptArgsStr.size() - 1, 1);
	scriptArgsStr.append("}");

	return scriptArgsStr;
}

void AppEngine::UpdatePythonPath()
{
	for (auto i : this->settings.python.dependencies.split(QChar(';'), QString::SkipEmptyParts)) {
		std::string pathVar = i.toStdString();
		if (this->pythonPathVar.insert(pathVar).second) {
			this->pyEngine.AppendPythonPath(pathVar);
		}
	}
}

void AppEngine::SetupExampleScripts()
{
	try {
		for (const auto& entry : std::filesystem::directory_iterator(SCRIPTEXAMPLES)) {
			if (entry.path().extension().compare(".py") == 0) {
				this->appUI.AddExampleScript(this->exampleScripts.size(), QString::fromStdString(entry.path().filename().replace_extension().string()));
				this->exampleScripts.push_back(QString::fromStdString(entry.path().string()));
			}
		}
	}
	catch (std::filesystem::filesystem_error e) {
		std::cerr << e.what() << std::endl;
#ifdef _DEBUG
		OutputDebugStringA(e.what());
		OutputDebugString(L"\n");
#endif
	}
}

/*
** Updates both the GUI (Plot Editor) and the plot with a new property value.
*/
void AppEngine::EditPlotProperty(PlotType pt, unsigned int pIdx, const QString& prop, const QString& val)
{
	if (pIdx == 0)
		return;

	QString plotProperty = prop.toLower();

	switch (this->appUI.EditPlotProperty(pIdx - 1, pt, plotProperty, val)) {
	case AppUI::UI_ERR_CODE::PLOT_EDITOR_INDEX_OUT_OF_RANGE:
		ErrorOutput("ERROR::UI: Plot index out of range.\n");
		return;
	case AppUI::UI_ERR_CODE::PLOT_EDITOR_NO_SUCH_PROPERTY:
		ErrorOutput("ERROR::UI: Plot property not editable.\n");
		return;
	case AppUI::UI_ERR_CODE::PLOT_EDITOR_NO_SUCH_VALUE:
		ErrorOutput("ERROR::UI: Invalid value.\n");
		return;
	case AppUI::UI_ERR_CODE::NONE:
	default:
		break;
	}

	switch (this->plotManager->EditPlotProperty(pIdx - 1, pt, plotProperty, val)) {
	case PlotManager::PLOT_ERR_CODE::INDEX_OUT_OF_RANGE:
		ErrorOutput("ERROR::PLOT: Plot index out of range.\n");
		return;
	case PlotManager::PLOT_ERR_CODE::NO_SUCH_PROPERTY:
		ErrorOutput("ERROR::PLOT: Plot property not editable.\n");
		return;
	case PlotManager::PLOT_ERR_CODE::NO_SUCH_VALUE:
		ErrorOutput("ERROR::PLOT: Invalid value.\n");
		return;
	case PlotManager::PLOT_ERR_CODE::NONE:
	default:
		break;
	}
}

/*
** Updates the plot arrangement in both the Plot Editor and the main window. The given plot arrangement
**  is tested for validity by the UI handler (specifically by the QButtonGrid custom widget) as it must
**  conform to a valid QButtonGrid arrangement.
*/
void AppEngine::SetPlotArrangement(const QVector<GridPoint>& plotArrangement)
{
	if (this->appUI.SetPlotArrangement(plotArrangement) != AppUI::UI_ERR_CODE::NONE) {
		ErrorOutput("ERROR: Invalid plot arrangement.\n");
		return;
	}

	int minW, minH;
	this->appUI.GetPlotMinSize(minW, minH);
	this->plotManager->SetPlotArrangement(plotArrangement, minW, minH);
	this->dataManager.SetupDataSets(plotArrangement.size() + 1);
}

bool AppEngine::Save(const std::string& file, const QVector<bool>& dataSetsToSave)
{
	std::ofstream ofs(file, std::ofstream::out);
	if (!ofs.is_open())
		return false;

	WriteToFile_Header(ofs);
	WriteToFile_SaveData(ofs, dataSetsToSave);

	ofs.close();
	return true;
}

bool AppEngine::AutoSave(const std::string& file, size_t dataIdx, const std::string& autoSaveHeader)
{
	std::ofstream ofs(file, std::ofstream::app);
	if (!ofs.is_open())
		return false;

	WriteToFile_AutoSave(ofs, dataIdx, autoSaveHeader);

	ofs.close();
	return true;
}

std::string GetTimeStr();

void AppEngine::GenerateAutoSaveFile(bool writeHeader)
{
	this->autoSaveFile.clear();
	if (this->settings.autoSave.filePath.isEmpty() ||
		this->settings.autoSave.fileName.isEmpty()) {
		if (writeHeader)
			ErrorOutput("ERROR: Could not generate auto-save file (no auto-save file set).\n");
		return;
	}

	this->autoSaveFile = std::string(this->settings.autoSave.filePath.toStdString() + '/');
	if (this->settings.autoSave.timeStamp) {
		int n = this->settings.autoSave.fileName.lastIndexOf('.');
		std::string base = this->settings.autoSave.fileName.left(n).toStdString();
		std::string ext = n < 0 ? "" : this->settings.autoSave.fileName.mid(n).toStdString();
		this->autoSaveFile.append(
			base
			+ '_'
			+ GetTimeStr()
			+ ext
		);
	}
	else {
		this->autoSaveFile.append(this->settings.autoSave.fileName.toStdString());
	}

	if (writeHeader) {
		std::ofstream ofs(this->autoSaveFile, std::ofstream::out);
		if (!ofs.is_open()) {
			ErrorOutput("ERROR: Could not generate auto-save file (write failed).\n");
			return;
		}

		WriteToFile_Header(ofs);

		ofs.close();
	}
}

void AppEngine::WriteToFile_Header(std::ofstream& ofs)
{
	// User Header
	if (this->settings.save.showUserParameters) {
		ofs << UserHeader() << "\n\n";
	}

	// Data Header
	if (this->settings.save.showDataFileInfo) {
		ofs << this->appUI.GetDataFileInfo().toStdString() << "\n\n";
	}
}

void AppEngine::WriteToFile_SaveData(std::ofstream& ofs, const QVector<bool>& dataSetsToSave)
{
	// Datasets
	for (size_t dataIdx = 0; dataIdx < dataSetsToSave.size(); ++dataIdx) {
		if (dataSetsToSave.at(dataIdx)) {
			ofs << '\n';
			// Dataset Label
			if (this->settings.save.showDataSetLabel) {
				ofs << this->settings.save.dataSetLabel.toStdString() << '\n';
			}
			// Dataset Info
			if (this->settings.save.showDataSetInfo) {
				ofs << this->appUI.GetDataSetInfo(dataIdx).toStdString() << '\n';
			}
			// Data
			for (auto d : this->dataManager.GetDataSet(dataIdx)->data) {
				ofs << d.front();
				for (DataPoint::iterator zItr = d.begin() + 1; zItr != d.end(); ++zItr) {
					ofs << "," << *zItr;
				}
				ofs << '\n';
			}
		}
	}
}

void AppEngine::WriteToFile_AutoSave(std::ofstream& ofs, size_t dataIdx, const std::string& autoSaveHeader)
{
	ofs << '\n';
	// Auto-save Label
	if (this->settings.autoSave.showAutoSaveLabel) {
		ofs << this->settings.autoSave.autoSaveLabel.toStdString() << '\n';
	}
	// Auto-save Header
	if (this->settings.autoSave.showAutoSaveHeader) {
		ofs << autoSaveHeader << '\n';
	}
	// Dataset Label
	if (this->settings.autoSave.showDataSetLabel) {
		ofs << this->settings.autoSave.dataSetLabel.toStdString() << '\n';
	}
	// Dataset Info
	if (this->settings.autoSave.showDataSetInfo) {
		ofs << this->appUI.GetDataSetInfo(dataIdx).toStdString() << '\n';
	}
	// Data
	for (auto d : this->dataManager.GetDataSet(dataIdx)->data) {
		ofs << d.front();
		for (DataPoint::iterator zItr = d.begin() + 1; zItr != d.end(); ++zItr) {
			ofs << "," << *zItr;
		}
		ofs << '\n';
	}
}

std::string AppEngine::UserHeader() const
{
	std::string userHeader("User: ");
	userHeader.append(this->appUI.GetUser().toStdString());
	userHeader.append("\n\n");

	for (auto p : this->appUI.GetScriptParameterVals()) {
		userHeader.append(p.first.toStdString());
		userHeader.append(": ");
		userHeader.append(p.second.toStdString());
		userHeader.append("\n");
	}

	userHeader.append("\nNotes:\n");
	userHeader.append(this->appUI.GetNotes().toStdString());

	return userHeader;
}

/*
** PYTHON SLOTS
*/

void AppEngine::Slot_Error(const QString& errMsg)
{
	ErrorOutput(errMsg.toStdString());
}

void AppEngine::Slot_Msg(const QString& scriptStatus, bool append)
{
	this->appUI.SetScriptStatus(scriptStatus, append);
}

void AppEngine::Slot_ScriptInitialize(unsigned int nGraphs, const QStringList& scriptParameters, const QStringList& visaResources)
{
	QVector<GridPoint> plotArrangement;

	nGraphs = nGraphs < PLOTS_MAX_ROWS ? nGraphs : PLOTS_MAX_ROWS;
	for (unsigned int i = 0; i < nGraphs; ++i)
		plotArrangement.push_back(GridPoint((int)i, 1, 0, 1));

	Slot_ScriptInitializeEx(plotArrangement, scriptParameters, visaResources);
}

void AppEngine::Slot_ScriptInitializeEx(const QVector<GridPoint>& plotArrangement, const QStringList& scriptParameters, const QStringList& visaResources)
{
	ScriptInitialize_Params(scriptParameters);
	SetPlotArrangement(plotArrangement);
	this->appUI.SetVisaOptions(visaResources);
}

void AppEngine::Slot_Data(unsigned int dataID, unsigned int argc, double data[32])
{
	if (argc == 0 && dataID > 0) {
		this->plotManager->Clear2D(dataID - 1);
	}
	else {
		this->dataManager.AppendData(dataID, argc, data);
		if (dataID > 0)
			this->plotManager->AddData2D(dataID - 1, data[0], data[1]);
	}

	delete[] data;
}

void AppEngine::Slot_XData(unsigned int dataID, QVector<double> * dataX, QVector<double> * dataY, bool save)
{
	if (save)
		this->dataManager.AppendData(dataID, dataX, dataY);

	if (dataID > 0)
		this->plotManager->AddData2D(dataID - 1, dataX, dataY);

	delete dataX;
	delete dataY;
}

void AppEngine::Slot_DataInfo(unsigned int id, const QString& info)
{
	this->appUI.SetDataSetInfo(id, info);
	this->dataManager.SetDataInfo(id, info);
}

void AppEngine::Slot_DataFileInfo(const QString& info)
{
	this->appUI.SetDataFileInfo(info);
	this->dataManager.SetDataFileInfo(info);
}

void AppEngine::Slot_PlotProperty2D(unsigned int id, const QString& prop, const QString& val)
{
	EditPlotProperty(PlotType::TWODIMSN, id, prop, val);
}

void AppEngine::Slot_PlotPropertyCM(unsigned int id, const QString& prop, const QString& val)
{
	EditPlotProperty(PlotType::COLORMAP, id, prop, val);
}

void AppEngine::Slot_SaveData(unsigned int dataID, const QString& header)
{
	if (this->autoSaveFile.empty() || !AutoSave(this->autoSaveFile, dataID, header.toStdString())) {
		ErrorOutput("ERROR: Auto-save failed.\n");
	}
}

void AppEngine::Slot_ClearData(unsigned int dataID)
{
	this->dataManager.ClearData(dataID);
}

void AppEngine::Slot_CMData(unsigned int graphID, unsigned int xIdx, unsigned int yIdx, double z)
{
	this->plotManager->AddDataCM(graphID - 1, xIdx, yIdx, z);
}

void AppEngine::Slot_CMSetup(unsigned int graphID, double xMin, double xMax, double yMin, double yMax, unsigned int xSize, unsigned int ySize, bool zRange, double zMin, double zMax, bool show)
{
	if (graphID == 0)
		return;

	switch (this->appUI.SetupColormap(graphID - 1, xMin, xMax, yMin, yMax, xSize, ySize, zRange, zMin, zMax)) {
	case AppUI::UI_ERR_CODE::PLOT_EDITOR_INDEX_OUT_OF_RANGE:
		ErrorOutput("ERROR::UI: Plot index out of range.\n");
		return;
	case AppUI::UI_ERR_CODE::NONE:
		break;
	default:
		ErrorOutput("ERROR::UI: Error setting up colormap.\n");
		return;
	}

	switch (this->plotManager->SetupColormap(graphID - 1, xMin, xMax, yMin, yMax, xSize, ySize, zRange, zMin, zMax)) {
	case PlotManager::PLOT_ERR_CODE::INDEX_OUT_OF_RANGE:
		ErrorOutput("ERROR::PLOT: Plot index out of range.\n");
		return;
	case PlotManager::PLOT_ERR_CODE::NONE:
		break;
	default:
		ErrorOutput("ERROR::PLOT: Error setting up colormap.\n");
	}

	if (!show) {
		Slot_CMShow(graphID, show);
	}
}

void AppEngine::Slot_CMShow(unsigned int graphID, bool show)
{
	if (graphID == 0)
		return;

	switch (this->appUI.ShowColormap(graphID - 1, show)) {
	case AppUI::UI_ERR_CODE::PLOT_EDITOR_INDEX_OUT_OF_RANGE:
		ErrorOutput("ERROR::UI: Plot index out of range.\n");
		return;
	case AppUI::UI_ERR_CODE::NONE:
		break;
	default:
		ErrorOutput("ERROR::UI: Error showing colormap.\n");
		return;
	}

	switch (this->plotManager->ShowColormap(graphID - 1, show)) {
	case PlotManager::PLOT_ERR_CODE::INDEX_OUT_OF_RANGE:
		ErrorOutput("ERROR::PLOT: Plot index out of range.\n");
		return;
	case PlotManager::PLOT_ERR_CODE::NONE:
		break;
	default:
		ErrorOutput("ERROR::PLOT: Error showing colormap.\n");
	}
}

void AppEngine::Slot_CustomFnName(unsigned int fnNum, const QString& name)
{
	if (fnNum == 0)
		return;

	this->appUI.SetCustomControl(fnNum - 1, name);
}

void AppEngine::Slot_AutoSaveConfig(bool enable, const QString& file)
{
	this->appUI.EnableAutoSave(enable);
	this->autoSaveFlag = enable;

	if (!file.isEmpty()) {
		QFileInfo fi(file);
		this->settings.autoSave.fileName = fi.fileName();
		this->settings.autoSave.filePath = fi.absolutePath();
	}
}

void AppEngine::Slot_PlotArrangement(const QVector<GridPoint>& plotArrangement)
{
	SetPlotArrangement(plotArrangement);
}

void AppEngine::Slot_RetFn_Init(int status)
{
	if (status == 0) {
		this->appUI.SetScriptStatus(QString("Script Loaded"), true);
		this->appUI.EnableControl_Run(true);
		this->appUI.EnableControl_Custom(0, true);
	}
	else {
		this->appUI.SetScriptStatus(QString("Error Initializing Script"), true);
	}
	this->appUI.EnableControl_Load(true);
}

void AppEngine::Slot_RetFn_Run(int status)
{
	if (this->settings.python.reportRunStatus)
		this->appUI.SetScriptStatus(QString("Script Completed: %1").arg(status == 0 ? "OK" : "ERROR"), true);

	this->appUI.EnableControl_Load(true);
	this->appUI.EnableControl_Run(true);
	this->appUI.EnableControl_Stop(false);
}

void AppEngine::Slot_RetFn_Stop(int status)
{
}

void AppEngine::Slot_RetFn_Custom1(int status)
{
	this->appUI.EnableControl_Custom(1, true);
}

void AppEngine::Slot_RetFn_Custom2(int status)
{
	this->appUI.EnableControl_Custom(2, true);
}

void AppEngine::Slot_RetFn_Custom3(int status)
{
	this->appUI.EnableControl_Custom(3, true);
}

void AppEngine::Slot_RetFn_Custom4(int status)
{
	this->appUI.EnableControl_Custom(4, true);
}

void AppEngine::Slot_RetFn_Custom5(int status)
{
	this->appUI.EnableControl_Custom(5, true);
}

void AppEngine::Slot_RetFn_Custom6(int status)
{
	this->appUI.EnableControl_Custom(6, true);
}

void AppEngine::Slot_RetFn_Custom7(int status)
{
	this->appUI.EnableControl_Custom(7, true);
}

void AppEngine::Slot_RetFn_Custom8(int status)
{
	this->appUI.EnableControl_Custom(8, true);
}

/*
** PYTHON SLOTS END
*/


/*
** UI Slots
*/

void AppEngine::Slot_LoadModule(const QString& filename)
{
	this->appUI.EnableControl_Load(false);
	this->appUI.EnableControl_Run(false);
	this->appUI.EnableControl_Stop(false);
	this->appUI.EnableControl_Custom(0, false);
	this->appUI.EnableAutoSave(false);
	this->autoSaveFlag = false;

	this->plotManager->Clear();
	this->appUI.ClearScriptStatus();
	this->appUI.ClearErrorLog();
	this->appUI.ClearModuleInfo();
	this->appUI.ClearScriptParameters();

	if (this->pyEngine.Load(filename) == 0 &&
		this->pyEngine.Init() == 0) {
		this->appUI.SetModuleInfoCurrentModule(filename);
	}
	else {
		this->appUI.EnableControl_Load(true);
	}
}

void AppEngine::Slot_RunModule()
{
	std::vector<std::pair<std::string, std::string>> scriptArguments;

	this->appUI.EnableControl_Load(false);
	this->appUI.EnableControl_Run(false);
	this->appUI.EnableControl_Stop(false);
	this->appUI.EnableControl_Custom(0, false);

	this->plotManager->Clear();
	this->dataManager.ClearAllData();
	this->appUI.ClearScriptStatus();
	this->appUI.ClearErrorLog();
	this->appUI.SetModuleInfoScriptParameters(BuildScriptArguments(scriptArguments));
	if (this->settings.parameters.exportOnRun && !this->settings.parameters.file.isEmpty())
		ScriptParameters_Export(this->settings.parameters.file.toStdString());
	if (this->autoSaveFlag)
		this->appUI.OpenAutoSaveDialog();
	GenerateAutoSaveFile(this->settings.autoSave.generateOnRun);

	if (this->pyEngine.Reload() == 0 &&
		this->pyEngine.Run(scriptArguments) == 0) {
		this->appUI.EnableControl_Stop(true);
	}
	else {
		this->appUI.EnableControl_Load(true);
		this->appUI.EnableControl_Run(true);
	}
	this->appUI.EnableControl_Custom(0, true);
}

void AppEngine::Slot_StopModule()
{
	this->appUI.EnableControl_Stop(false);
	if (this->pyEngine.Stop()) {
		this->appUI.EnableControl_Stop(true);
	}
}

void AppEngine::Slot_CustomControl(size_t cc)
{
	this->appUI.EnableControl_Custom(cc + 1, false);
	if (this->pyEngine.Custom(cc)) {
		this->appUI.EnableControl_Custom(cc + 1, true);
	}
}

int ExecutePythonIDLE(const TCHAR * filename);

void AppEngine::Slot_CreateNewScript(const QString& filename)
{
	switch (ExecutePythonIDLE(filename.toStdWString().c_str())) {
	case 0:
		break;
	case 1:
		ErrorOutput("CREATE NEW SCRIPT: File creation failed.\n");
		break;
	case 2:
		ErrorOutput("CREATE NEW SCRIPT: Process creation failed.\n");
		break;
	default:
		ErrorOutput("CREATE NEW SCRIPT: Unknown error occurred.\n");
		break;
	}
}

void AppEngine::Slot_ExampleScript(unsigned int scriptID)
{
	Slot_LoadModule(this->exampleScripts.at(scriptID));
}

int OpenReferenceManual();

void AppEngine::Slot_ReferenceManual()
{
	if (OpenReferenceManual() <= 32) {
		ErrorOutput("ERROR: Could not open reference manual.\n");
	}
}

void AppEngine::Slot_ParamsImport(const QString& filename)
{
	this->settings.parameters.file = filename;
	ScriptParameters_Import(filename.toStdString());
}

void AppEngine::Slot_ParamsExport(const QString& filename)
{
	this->settings.parameters.file = filename;
	ScriptParameters_Export(filename.toStdString());
}

void AppEngine::Slot_PlotEditor_UpdateArrangement(const QVector<GridPoint>& plotArrangement)
{
	int minW, minH;
	this->appUI.GetPlotMinSize(minW, minH);
	this->plotManager->SetPlotArrangement(plotArrangement, minW, minH);
	this->dataManager.SetupDataSets(plotArrangement.size() + 1);
}

void AppEngine::Slot_PlotEditor_UpdateProperties(const QVector<size_t>& plotUpdateQueue)
{
	for (auto i : plotUpdateQueue) {
		PlotProperties p;

		if (this->appUI.GetPlotProperties(i, p) != AppUI::UI_ERR_CODE::NONE)
			continue;

		this->plotManager->SetPlotProperties(i, p);
	}
}

void AppEngine::Slot_UpdateDataInfo(const QString& dataInfo, const QVector<std::pair<bool, QString>>& dataSetInfo)
{
	this->dataManager.SetDataFileInfo(dataInfo);

	for (size_t i = 0; i < dataSetInfo.size(); ++i) {
		this->dataManager.SetDataInfo(i, dataSetInfo.at(i).second);
	}
}

void AppEngine::Slot_UpdatePythonPath()
{
	UpdatePythonPath();
}

void AppEngine::Slot_Save(const QString& file, const QVector<bool>& dataToSave, bool timeStamp)
{
	this->appUI.CloseSaveDialog(!Save(file.toStdString(), dataToSave));
}

/*
** UI Slots End
*/

int ExecutePythonIDLE(const TCHAR * filename)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	TCHAR *cmdLine = NULL;
	const TCHAR * cmdLineProg = L"python -m idlelib ";
	size_t cmdLineLen = 0;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (CopyFile(SCRIPTDEFAULT, filename, FALSE) == 0)
		return 1;

	cmdLineLen = wcslen(cmdLineProg) + wcslen(filename) + 1;
	cmdLine = (TCHAR *)malloc(cmdLineLen * sizeof(TCHAR));
	wcscpy_s(cmdLine, cmdLineLen, cmdLineProg);
	wcscat_s(cmdLine, cmdLineLen, filename);

	if (!CreateProcess(
		NULL,
		cmdLine,
		NULL,
		NULL,
		FALSE,
		DETACHED_PROCESS,
		NULL,
		NULL,
		&si,
		&pi)
		)
	{
		free(cmdLine);
		return 2;
	}
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	free(cmdLine);
	return 0;
}

int OpenReferenceManual()
{
	WCHAR szPath[MAX_PATH];
	DWORD p;
	std::wstring rmFile;

	if ((p = GetModuleFileName(NULL, szPath, MAX_PATH)) == 0) {
		return -1;
	}
	while (szPath[--p] != '\\') szPath[p] = 0;
	rmFile = std::wstring(szPath).append(REFMANUALFILE);

	return (int)ShellExecute(
		NULL,
		L"open",
		rmFile.c_str(),
		NULL,
		NULL,
		SW_SHOWDEFAULT
	);
}

std::string GetTimeStr()
{
	time_t t = time(NULL);
	struct tm buf;
	char str[26];
	localtime_s(&buf, &t);
	asctime_s(str, sizeof(str), &buf);
	std::string timeStr(str);
	std::replace(timeStr.begin(), timeStr.end(), ':', '-');
	std::replace(timeStr.begin(), timeStr.end(), ' ', '_');
	timeStr.pop_back();
	return timeStr;
}