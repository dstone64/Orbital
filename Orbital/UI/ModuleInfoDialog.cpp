#include "ModuleInfoDialog.h"

ModuleInfoDialog::ModuleInfoDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui.setupUi(this);
}

ModuleInfoDialog::~ModuleInfoDialog()
{
}

void ModuleInfoDialog::Clear()
{
	this->ui.lineEdit_currentModule->clear();
	this->ui.plainTextEdit_scriptParameters->clear();
}

void ModuleInfoDialog::UpdateModuleFile(const QString& moduleFile)
{
	this->ui.lineEdit_currentModule->setText(moduleFile);
}

void ModuleInfoDialog::UpdateScriptParameters(const QString& scriptParameters)
{
	this->ui.plainTextEdit_scriptParameters->setPlainText(scriptParameters);
}