#pragma once

#include <QDialog>
#include <QStringList>
#include <QFrame>
#include <QLayout>
#include <QLabel>
#include <QComboBox>
#include <QList>
#include "ui_VisaSetupDialog.h"

class VisaSetupDialog : public QDialog
{
	Q_OBJECT

public:
	VisaSetupDialog(QWidget *parent);
	~VisaSetupDialog();

	void GenerateVisaEntries(const QStringList& visaOptions);
	QStringList VisaAssignments();

public Q_SLOTS:
	void on_pushButton_save_clicked();
	void on_pushButton_cancel_clicked();

private:
	Ui::VisaSetupDialog ui;

	class VisaEntry {
	public:
		VisaEntry(QWidget *parent, const QStringList& visaOptions);
		VisaEntry(const VisaEntry& src);
		~VisaEntry();
		QFrame *Frame() const { return this->frame; }
		QString CurrentText() const { return this->comboBox->currentText(); }
		void Set() { this->resetVal = this->comboBox->currentIndex(); }
		void Reset() { this->comboBox->setCurrentIndex(this->resetVal); }

	private:
		QFrame *frame;
		QHBoxLayout *layout;
		QLabel *label;
		QComboBox *comboBox;
		int resetVal;
	};
	QList<VisaEntry *> visaEntries;

	void AddVisa(const QStringList& visaOptions);
	void RemoveAll();
};
