#pragma once

#include <QDialog>
#include <QString>
#include "ui_SettingsDialog.h"
#include "AppConfig.h"
#include <QStringList>

class SettingsDialog : public QDialog
{
	Q_OBJECT

public:
	SettingsDialog(QWidget* parent);
	~SettingsDialog();

	void Setup(AppSettings* settings);
	void showEvent(QShowEvent* e);

public Q_SLOTS:
	void on_pushButton_save_clicked();
	void on_pushButton_cancel_clicked();
	void on_pushButton_autoSaveFileDirectory_clicked();
	void on_pushButton_parametersFile_clicked();
	void on_pushButton_pythonDependenciesAdd_clicked();
	void on_pushButton_pythonDependenciesRemove_clicked();

Q_SIGNALS:
	void Signal_UpdatePythonPath();

private:
	Ui::SettingsDialog ui;
	AppSettings* settings;
	bool updatePythonPath;
};
