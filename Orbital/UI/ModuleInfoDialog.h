#pragma once

#include <QDialog>
#include "ui_ModuleInfoDialog.h"

class ModuleInfoDialog : public QDialog
{
	Q_OBJECT

public:
	ModuleInfoDialog(QWidget *parent);
	~ModuleInfoDialog();

	void Clear();
	void UpdateModuleFile(const QString& moduleFile);
	void UpdateScriptParameters(const QString& scriptParameters);

private:
	Ui::ModuleInfoDialog ui;
};
