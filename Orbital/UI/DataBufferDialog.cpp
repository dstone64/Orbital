#include "DataBufferDialog.h"

DataBufferDialog::DataBufferDialog(QWidget *parent, int dataIdx, DataManager *hDataManager)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint), dataIdx(dataIdx), hDataManager(hDataManager)
{
	ui.setupUi(this);
}

DataBufferDialog::~DataBufferDialog()
{
}

void DataBufferDialog::showEvent(QShowEvent * e)
{
	const std::vector<DataPoint> *a = &hDataManager->GetDataSet(this->dataIdx)->data;

	QString text;
	if (a) {
		for (int i = 0; i < 100 && i < a->size(); ++i) {
			for (int j = 0; j < a->at(i).size() - 1; ++j)
				text.append(QString::number(a->at(i).at(j)) + ",");
			text.append(QString::number(a->at(i).back()) + "\n");
		}
	}
	this->ui.plainTextEdit->setPlainText(text);
}
