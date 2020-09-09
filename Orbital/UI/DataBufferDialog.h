#pragma once

#include <QDialog>
#include "ui_DataBufferDialog.h"
#include "DataManager.h"

class DataBufferDialog : public QDialog
{
	Q_OBJECT

public:
	DataBufferDialog(QWidget *parent, int dataIdx, DataManager *hDataManager);
	~DataBufferDialog();

	void showEvent(QShowEvent *e);

private:
	Ui::DataBufferDialog ui;
	const int dataIdx;
	DataManager *hDataManager;
};
