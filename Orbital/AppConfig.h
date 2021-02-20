#pragma once

#include <map>
#include <string>
#include <QString>

class AppConfig
{
public:
	AppConfig(const wchar_t* configFile);
	~AppConfig();
	AppConfig(const AppConfig&) = delete;
	AppConfig& operator=(const AppConfig&) = delete;

	void update() const;
	std::wstring file() const { return configFile; }
	QString& get(const std::string& k) { return map[k]; }
	QString& get(const std::string& k, const QString& v) {
		if (map.find(k) != map.end())
			return map[k];
		return (map[k] = v);
	}

private:
	std::wstring configFile;
	std::map<std::string, QString> map;
};

struct AppSettings {
	struct {
		QString fileName;
		QString filePath;
		QString autoSaveLabel;
		QString dataSetLabel;
		bool generateOnRun;
		bool timeStamp;
		bool showAutoSaveLabel;
		bool showAutoSaveHeader;
		bool showDataSetLabel;
		bool showDataSetInfo;
	} autoSave;
	struct {
		QString dataSetLabel;
		bool showUserParameters;
		bool showDataFileInfo;
		bool showDataSetLabel;
		bool showDataSetInfo;
	} save;
	struct {
		QString file;
		bool exportOnRun;
	} parameters;
	struct {
		QString dependencies;
		bool reportRunStatus;
	} python;

	void Setup(AppConfig* config);
	void UpdateConfig(AppConfig* config);
};
