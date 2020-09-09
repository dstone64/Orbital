#include "DataManager.h"
#include <algorithm>
#include <ctime>
#include <fstream>
#include <QFileInfo>
#include <QString>

DataSet::DataSet()
{
}

DataSet::~DataSet()
{
}

DataManager::DataManager()
{
	SetupDataSets(2);
}

DataManager::~DataManager()
{
}

void DataManager::SetupDataSets(size_t n)
{
	if (n <= 1)
		return;

	if (n > this->dataSets.size()) {
		for (size_t i = this->dataSets.size(); i < n; ++i)
			this->dataSets.push_back(new DataSet);
	}
	else {
		for (size_t i = this->dataSets.size(); i > n; --i) {
			delete this->dataSets.back();
			this->dataSets.pop_back();
		}
	}
}

void DataManager::ResetDataSets()
{
	for (size_t i = 0; i < this->dataSets.size(); ++i) {
		delete this->dataSets[i];
		this->dataSets[i] = new DataSet();
	}
}

void DataManager::ClearData(size_t idx)
{
	if (idx >= this->dataSets.size())
		return;

	this->dataSets.at(idx)->Clear();
}

void DataManager::ClearAllData()
{
	for (auto dataSet : this->dataSets) {
		dataSet->Clear();
	}
}

void DataManager::DestroyDataSet(size_t idx)
{
	if (idx >= this->dataSets.size())
		return;

	delete this->dataSets.at(idx);
	this->dataSets.erase(this->dataSets.begin() + idx);
}

void DataManager::DestroyAllData()
{
	for (auto itr = this->dataSets.begin(); itr != this->dataSets.end(); ++itr)
		delete (*itr);
	this->dataSets.clear();
}

void DataManager::AppendData(size_t idx, unsigned int n, double data[32])
{
	if (idx >= this->dataSets.size() || !this->dataSets.at(idx)->enabled)
		return;

	size_t offset = (n > 32 ? 32 : (size_t)n);
	this->dataSets.at(idx)->Append(DataPoint(data, data + offset));
}

void DataManager::AppendData(size_t idx, const QVector<double> * x, const QVector<double> * y)
{
	if (idx >= this->dataSets.size() || !this->dataSets.at(idx)->enabled)
		return;

	size_t szData = (x->size() < y->size() ? x->size() : y->size());
	for (size_t i = 0; i < szData; ++i)
		this->dataSets.at(idx)->Append(DataPoint{ x->at(i), y->at(i) });
}

const DataSet * DataManager::GetDataSet(size_t idx) const
{
	return this->dataSets.at(idx);
}

size_t DataManager::DataSetCount() const
{
	return this->dataSets.size();
}

void DataManager::SetDataInfo(size_t idx, const QString& info, bool buffer)
{
	if (idx >= this->dataSets.size())
		return;

	this->dataSets.at(idx)->SetInfo(info);
	this->dataSets.at(idx)->SetBuffering(buffer);
}

void DataManager::SetDataFileInfo(const QString& info)
{
	this->dataFileInfo = QString(info);
}