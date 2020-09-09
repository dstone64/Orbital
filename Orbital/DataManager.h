#pragma once

#include <vector>
#include <string>
#include <QVector>
#include <QString>
#include "SettingsDialog.h"

typedef std::vector<double> DataPoint;

typedef struct {
	unsigned int maxDomain;
	bool bufferData;
	bool limitDomain;
} DataSettings;

class DataSet
{
public:
	DataSet();
	~DataSet();

	void Append(const DataPoint& d) { this->data.push_back(d); }
	void Clear() { this->data.clear(); }
	void SetInfo(const QString& info) { this->info = info.toStdString(); }
	void SetBuffering(bool buffer) { this->enabled = buffer; }

	std::vector<DataPoint> data;
	std::string info;
	bool enabled;
};

class DataManager
{
public:
	DataManager();
	~DataManager();

	void SetupDataSets(size_t n);
	void ResetDataSets();
	void ClearData(size_t idx);
	void ClearAllData();
	void DestroyDataSet(size_t idx);
	void DestroyAllData();
	void AppendData(size_t idx, unsigned int n, double data[32]);
	void AppendData(size_t idx, const QVector<double> * x, const QVector<double> * y);
	const DataSet * GetDataSet(size_t idx) const;
	size_t DataSetCount() const;
	void SetDataInfo(size_t idx, const QString& info, bool buffer = true);
	void SetDataFileInfo(const QString& info);

private:
	std::vector<DataSet *> dataSets;
	QString dataFileInfo;
};