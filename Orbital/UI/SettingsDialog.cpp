#include "SettingsDialog.h"
#include <QFileDialog>

SettingsDialog::SettingsDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint), updatePythonPath(false)
{
	ui.setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
}

void SettingsDialog::Setup(AppSettings *settings)
{
	this->settings = settings;
}

void SettingsDialog::showEvent(QShowEvent *e)
{
	ui.lineEdit_autoSaveFileName->setText(settings->autoSave.fileName);
	ui.lineEdit_autoSaveFileDirectory->setText(settings->autoSave.filePath);
	ui.checkBox_autoSaveGenerateOnRun->setChecked(settings->autoSave.generateOnRun);
	ui.checkBox_autoSaveGenerateTimeStamp->setChecked(settings->autoSave.timeStamp);
	ui.checkBox_autoSaveLabel->setChecked(settings->autoSave.showAutoSaveLabel);
	ui.plainTextEdit_autoSaveLabel->setPlainText(settings->autoSave.autoSaveLabel);
	ui.checkBox_autoSaveHeader->setChecked(settings->autoSave.showAutoSaveHeader);
	ui.checkBox_autoSaveDataSetLabel->setChecked(settings->autoSave.showDataSetLabel);
	ui.plainTextEdit_autoSaveDataSetLabel->setPlainText(settings->autoSave.dataSetLabel);
	ui.checkBox_autoSaveDataSetInfo->setChecked(settings->autoSave.showDataSetInfo);

	ui.checkBox_saveUserParameters->setChecked(settings->save.showUserParameters);
	ui.checkBox_saveDataFileInfo->setChecked(settings->save.showDataFileInfo);
	ui.checkBox_saveDataSetLabel->setChecked(settings->save.showDataSetLabel);
	ui.plainTextEdit_saveDataSetLabel->setPlainText(settings->save.dataSetLabel);
	ui.checkBox_saveDataSetInfo->setChecked(settings->save.showDataSetInfo);

	ui.checkBox_parametersExportOnRun->setChecked(settings->parameters.exportOnRun);
	ui.lineEdit_parametersFile->setText(settings->parameters.file);

	ui.listWidget_pythonDependencies->clear();
	for (auto i : settings->python.dependencies.split(QChar(';'), QString::SkipEmptyParts))
		ui.listWidget_pythonDependencies->addItem(i);
	ui.checkBox_pythonRunStatus->setChecked(settings->python.reportRunStatus);

	this->updatePythonPath = false;
	QDialog::showEvent(e);
}

void SettingsDialog::on_pushButton_save_clicked()
{
	settings->autoSave.fileName = ui.lineEdit_autoSaveFileName->text();
	settings->autoSave.filePath = ui.lineEdit_autoSaveFileDirectory->text();
	settings->autoSave.generateOnRun = ui.checkBox_autoSaveGenerateOnRun->isChecked();
	settings->autoSave.timeStamp = ui.checkBox_autoSaveGenerateTimeStamp->isChecked();
	settings->autoSave.showAutoSaveLabel = ui.checkBox_autoSaveLabel->isChecked();
	settings->autoSave.autoSaveLabel = ui.plainTextEdit_autoSaveLabel->toPlainText();
	settings->autoSave.showAutoSaveHeader = ui.checkBox_autoSaveHeader->isChecked();
	settings->autoSave.showDataSetLabel = ui.checkBox_autoSaveDataSetLabel->isChecked();
	settings->autoSave.dataSetLabel = ui.plainTextEdit_autoSaveDataSetLabel->toPlainText();
	settings->autoSave.showDataSetInfo = ui.checkBox_autoSaveDataSetInfo->isChecked();

	settings->save.showUserParameters = ui.checkBox_saveUserParameters->isChecked();
	settings->save.showDataFileInfo = ui.checkBox_saveDataFileInfo->isChecked();
	settings->save.showDataSetLabel = ui.checkBox_saveDataSetLabel->isChecked();
	settings->save.dataSetLabel = ui.plainTextEdit_saveDataSetLabel->toPlainText();
	settings->save.showDataSetInfo = ui.checkBox_saveDataSetInfo->isChecked();

	settings->parameters.exportOnRun = ui.checkBox_parametersExportOnRun->isChecked();
	settings->parameters.file = ui.lineEdit_parametersFile->text();

	settings->python.dependencies.clear();
	for (int i = 0; i < ui.listWidget_pythonDependencies->count(); ++i)
		settings->python.dependencies.append(ui.listWidget_pythonDependencies->item(i)->text() + QChar(';'));
	settings->python.reportRunStatus = ui.checkBox_pythonRunStatus->isChecked();

	if (this->updatePythonPath)
		emit Signal_UpdatePythonPath();
	this->close();
}

void SettingsDialog::on_pushButton_cancel_clicked()
{
	this->close();
}

void SettingsDialog::on_pushButton_autoSaveFileDirectory_clicked()
{
	QString dir = QFileDialog::getExistingDirectory(
		this,
		tr("Open Directory"),
		"",
		QFileDialog::ShowDirsOnly
	);

	if (dir.isEmpty())
		return;

	ui.lineEdit_autoSaveFileDirectory->setText(dir);
}

void SettingsDialog::on_pushButton_parametersFile_clicked()
{
	QString file = QFileDialog::getSaveFileName(
		this,
		tr("Parameters File"),
		"",
		tr("Text Documents (*.txt)")
	);

	if (file.isEmpty())
		return;

	ui.lineEdit_parametersFile->setText(file);
}

void SettingsDialog::on_pushButton_pythonDependenciesAdd_clicked()
{
	QString dir = QFileDialog::getExistingDirectory(
		this,
		tr("Open Directory"),
		"",
		QFileDialog::ShowDirsOnly
	);

	if (dir.isEmpty())
		return;

	bool add = true;
	for (int i = 0; i < ui.listWidget_pythonDependencies->count(); ++i) {
		if (ui.listWidget_pythonDependencies->item(i)->text().compare(dir) == 0) {
			add = false;
			break;
		}
	}
	if (add) {
		ui.listWidget_pythonDependencies->addItem(dir);
		this->updatePythonPath = true;
	}
}

void SettingsDialog::on_pushButton_pythonDependenciesRemove_clicked()
{
	for (auto i : ui.listWidget_pythonDependencies->selectedItems()) {
		delete i;
	}
}
