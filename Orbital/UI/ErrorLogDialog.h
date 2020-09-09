#pragma once

#include <QDialog>
#include "ui_ErrorLogDialog.h"

class ErrorLogDialog : public QDialog
{
	Q_OBJECT

public:
	ErrorLogDialog(QWidget *parent);
	~ErrorLogDialog();

	void Append(const QString& s) { this->ui.plainTextEdit->appendPlainText(s); }
	void Clear() { this->ui.plainTextEdit->clear(); }

private:
	Ui::ErrorLogDialog ui;
};
