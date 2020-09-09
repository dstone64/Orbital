#include "AutoSaveDialog.h"
#include <QFileDialog>
#include <QFileInfo>

AutoSaveDialog::AutoSaveDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui.setupUi(this);
}

AutoSaveDialog::~AutoSaveDialog()
{
}

void AutoSaveDialog::Setup(AppSettings *settings)
{
	this->settings = settings;
}

void AutoSaveDialog::showEvent(QShowEvent *e)
{
	ui.lineEdit_fileName->setText(settings->autoSave.fileName);
	ui.lineEdit_filePath->setText(settings->autoSave.filePath);
	ui.checkBox_generateNewFile->setChecked(settings->autoSave.generateOnRun);
	ui.checkBox_includeTimeStamp->setChecked(settings->autoSave.timeStamp);
	ui.checkBox_showAutoSaveLabel->setChecked(settings->autoSave.showAutoSaveLabel);
	ui.plainTextEdit_autoSaveLabel->setPlainText(settings->autoSave.autoSaveLabel);
	ui.checkBox_showAutoSaveHeader->setChecked(settings->autoSave.showAutoSaveHeader);
	ui.checkBox_showDataSetLabel->setChecked(settings->autoSave.showDataSetLabel);
	ui.plainTextEdit_dataSetLabel->setPlainText(settings->autoSave.dataSetLabel);
	ui.checkBox_showDataSetInfo->setChecked(settings->autoSave.showDataSetInfo);

	QDialog::showEvent(e);
}

void AutoSaveDialog::on_pushButton_filePath_clicked()
{
	QString saveFileDirectory = QFileDialog::getExistingDirectory(
		this,
		tr("Open Directory"),
		this->settings->autoSave.filePath,
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
	);
	if (saveFileDirectory.isEmpty())
		return;

	this->ui.lineEdit_filePath->setText(saveFileDirectory);
}

void AutoSaveDialog::on_pushButton_continue_clicked()
{
	settings->autoSave.fileName = ui.lineEdit_fileName->text();
	settings->autoSave.filePath = ui.lineEdit_filePath->text();
	settings->autoSave.generateOnRun = ui.checkBox_generateNewFile->isChecked();
	settings->autoSave.timeStamp = ui.checkBox_includeTimeStamp->isChecked();
	settings->autoSave.showAutoSaveLabel = ui.checkBox_showAutoSaveLabel->isChecked();
	settings->autoSave.autoSaveLabel = ui.plainTextEdit_autoSaveLabel->toPlainText();
	settings->autoSave.showAutoSaveHeader = ui.checkBox_showAutoSaveHeader->isChecked();
	settings->autoSave.showDataSetLabel = ui.checkBox_showDataSetLabel->isChecked();
	settings->autoSave.dataSetLabel = ui.plainTextEdit_dataSetLabel->toPlainText();
	settings->autoSave.showDataSetInfo = ui.checkBox_showDataSetInfo->isChecked();

	this->close();
}