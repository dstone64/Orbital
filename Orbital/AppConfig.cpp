#include "AppConfig.h"
#include <fstream>
#include <regex>

#ifdef _DEBUG
#include <Windows.h>
#else
#include <ShlObj.h>
#endif

#include <QFileInfo>
#include <QStringList>

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/filewritestream.h>

void parse(std::ifstream&, std::map<std::string, QString>&);
bool ConfigRead(rapidjson::Document&);
bool ConfigWrite(const rapidjson::Document&);

AppConfig::AppConfig(const wchar_t * configFile)
{
#ifdef _WIN32
#ifdef _DEBUG
	WCHAR szPath[MAX_PATH];
	DWORD p;
	if ((p = GetModuleFileName(NULL, szPath, MAX_PATH)) == 0) {
		return;
	}
	while (szPath[--p] != '\\') szPath[p] = 0;
	this->configFile = std::wstring(szPath).append(std::wstring(configFile));
#else //_DEBUG
	PWSTR path;
	if (SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &path) != S_OK) {
		return;
	}
	this->configFile = std::wstring(path).append(L"\\Orbital\\").append(configFile);
	CoTaskMemFree(path);
#endif //_DEBUG
#endif //_WIN32
	std::ifstream ifs(this->configFile, std::ifstream::in);
	if (ifs.is_open()) {
		parse(ifs, this->map);
		ifs.close();
	}
}

AppConfig::~AppConfig()
{
}

void parse(std::ifstream& ifs, std::map<std::string, QString>& map)
{
	std::regex re("^(\\w+)\\s*=\\s*(.*)$");
	std::smatch sm;
	for (std::string line; getline(ifs, line); !ifs.eof() && !ifs.fail()) {
		if (std::regex_match(line, sm, re)) {
			map[sm[1]] = QString::fromStdString(sm[2]);
		}
	}
}

void AppConfig::update() const
{
	if (this->configFile.empty())
		return;

	std::ofstream ofs(this->configFile, std::ofstream::out);
	if (ofs.is_open()) {
		for (auto itr = this->map.begin(); itr != this->map.end(); ++itr) {
			ofs << (*itr).first << '=' << (*itr).second.toStdString() << '\n';
		}
		ofs.close();
	}
}

QString Tokenify(const QString& str, bool toMultiline)
{
	QString retStr = QString(str);
	if (toMultiline) {
		for (int i = retStr.indexOf("\\"); i >= 0 && i < retStr.size() - 1; i = retStr.indexOf("\\", i + 1)) {
			if (retStr.at(i + 1) == QChar('n')) {
				retStr.replace(i, 2, '\n');
			}
			else {
				retStr.remove(i, 1);
			}
		}
	}
	else {
		retStr.replace("\\", "\\\\").replace("\n", "\\n");
	}
	return retStr;
}

QString VerifyDirectories(const QString& dirList)
{
	QStringList dirs = dirList.split(QChar(';'), QString::SkipEmptyParts);
	QString retStr;
	for (auto d : dirs) {
		if (QFileInfo(d).isDir())
			retStr.append(d + ";");
	}
	return retStr;
}

void AppSettings::Setup(AppConfig * config)
{
	//autoSave.fileName = config->get("AutoSaveFileName");
	//autoSave.filePath = config->get("AutoSaveFilePath");
	autoSave.generateOnRun		 = config->get("AutoSaveGenerateOnRun") == "TRUE";
	autoSave.timeStamp			 = config->get("AutoSaveTimeStamp") == "TRUE";
	autoSave.showAutoSaveLabel	 = config->get("AutoSaveLabelShow") == "TRUE";
	autoSave.autoSaveLabel		 = Tokenify(config->get("AutoSaveLabel"), true);
	autoSave.showAutoSaveHeader	 = config->get("AutoSaveHeaderShow", "TRUE") == "TRUE";
	autoSave.showDataSetLabel	 = config->get("AutoSaveDataSetLabelShow", "TRUE") == "TRUE";
	autoSave.dataSetLabel		 = Tokenify(config->get("AutoSaveDataSetLabel", "Data Set Label"), true);
	autoSave.showDataSetInfo	 = config->get("AutoSaveDataSetInfoShow") == "TRUE";

	save.showUserParameters	 = config->get("SaveUserParametersShow", "TRUE") == "TRUE";
	save.showDataFileInfo	 = config->get("SaveDataFileInfoShow", "TRUE") == "TRUE";
	save.showDataSetLabel	 = config->get("SaveDataSetLabelShow", "TRUE") == "TRUE";
	save.dataSetLabel		 = Tokenify(config->get("SaveDataSetLabel", "Data Set Label"), true);
	save.showDataSetInfo	 = config->get("DataSetInfoShow") == "TRUE";

	parameters.exportOnRun = config->get("ParametersExportOnRun") == "TRUE";

	python.dependencies = VerifyDirectories(config->get("PythonDependencies"));
	python.reportRunStatus = config->get("PythonReportRunStatus", "TRUE") == "TRUE";
}

void AppSettings::UpdateConfig(AppConfig * config)
{
	//config->get("AutoSaveFileName") = autoSave.fileName;
	//config->get("AutoSaveFilePath") = autoSave.filePath;
	config->get("AutoSaveGenerateOnRun")	= autoSave.generateOnRun ? "TRUE" : "FALSE";
	config->get("AutoSaveTimeStamp")		= autoSave.timeStamp ? "TRUE" : "FALSE";
	config->get("AutoSaveLabelShow")		= autoSave.showAutoSaveLabel ? "TRUE" : "FALSE";
	config->get("AutoSaveLabel")			= Tokenify(autoSave.autoSaveLabel, false);
	config->get("AutoSaveHeaderShow")		= autoSave.showAutoSaveHeader ? "TRUE" : "FALSE";
	config->get("AutoSaveDataSetLabelShow") = autoSave.showDataSetLabel ? "TRUE" : "FALSE";
	config->get("AutoSaveDataSetLabel")		= Tokenify(autoSave.dataSetLabel, false);
	config->get("AutoSaveDataSetInfoShow")	= autoSave.showDataSetInfo ? "TRUE" : "FALSE";

	config->get("SaveUserParametersShow")	= save.showUserParameters ? "TRUE" : "FALSE";
	config->get("SaveDataFileInfoShow")		= save.showDataFileInfo ? "TRUE" : "FALSE";
	config->get("SaveDataSetLabelShow")		= save.showDataSetLabel ? "TRUE" : "FALSE";
	config->get("SaveDataSetLabel")			= Tokenify(save.dataSetLabel, false);
	config->get("DataSetInfoShow")			= save.showDataSetInfo ? "TRUE" : "FALSE";

	config->get("ParametersExportOnRun") = parameters.exportOnRun ? "TRUE" : "FALSE";

	config->get("PythonDependencies") = python.dependencies;
	config->get("PythonReportRunStatus") = python.reportRunStatus ? "TRUE" : "FALSE";
}