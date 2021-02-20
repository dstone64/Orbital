#pragma once

#include <QDialog>
#include <QString>
#include "ui_AutoSaveDialog.h"
#include "AppConfig.h"

class AutoSaveDialog : public QDialog
{
	Q_OBJECT

public:
	AutoSaveDialog(QWidget* parent);
	~AutoSaveDialog();

	void Setup(AppSettings* settings);
	void showEvent(QShowEvent* e);

public Q_SLOTS:
	void on_pushButton_filePath_clicked();
	void on_pushButton_continue_clicked();

private:
	Ui::AutoSaveDialog ui;
	AppSettings* settings;
};
