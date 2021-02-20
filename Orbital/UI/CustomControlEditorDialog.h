#pragma once

#include <QDialog>
#include <QString>
#include <QStringList>
#include <QLineEdit>
#include <array>
#include "ui_CustomControlEditorDialog.h"
#include "commondefine.h"
#include "AppConfig.h"

class CustomControlEditorDialog : public QDialog
{
	Q_OBJECT

public:
	CustomControlEditorDialog(QWidget* parent);
	~CustomControlEditorDialog();

	void Setup(AppConfig* config);
	void UpdateConfig() const;
	const QStringList& CustomControlNames() const { return this->customControlNames; }
	void SetName(size_t customControl, const QString& newName);
	void SetAll(const QStringList& newNames);

public Q_SLOTS:
	void on_pushButton_save_clicked();
	void on_pushButton_cancel_clicked();

Q_SIGNALS:
	void Signal_CustomControlsUpdated();

private:
	Ui::CustomControlEditorDialog ui;
	AppConfig* config;
	QStringList customControlNames;
	std::array<QLineEdit*, N_CUSTOMCONTROLS> customControlLineEdits;
};
