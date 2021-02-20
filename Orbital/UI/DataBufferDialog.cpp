#include "DataBufferDialog.h"

#define DATABUFFERDIALOG_MAXDISPLAY 100

DataBufferDialog::DataBufferDialog(QWidget* parent, int dataIdx, DataManager* hDataManager)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint), dataIdx(dataIdx), hDataManager(hDataManager)
{
	ui.setupUi(this);
}

DataBufferDialog::~DataBufferDialog()
{
}

void DataBufferDialog::showEvent(QShowEvent* e)
{
	const std::vector<DataPoint>* data = &hDataManager->GetDataSet(this->dataIdx)->data;

	QString text;
	if (data) {
		for (int i = 0; i < DATABUFFERDIALOG_MAXDISPLAY && i < data->size(); ++i) {
			for (int j = 0; j < data->at(i).size() - 1; ++j)
				text.append(QString::number(data->at(i).at(j)) + ",");
			text.append(QString::number(data->at(i).back()) + "\n");
		}
	}
	this->ui.plainTextEdit->setPlainText(text);
}
