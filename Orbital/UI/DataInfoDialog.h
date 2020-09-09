#pragma once

#include <QDialog>
#include <QWidget>
#include <QFrame>
#include <QLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QVector>
#include <QString>
#include <utility>
#include "ui_DataInfoDialog.h"
#include "DataBufferDialog.h"

class DataInfoDialog : public QDialog
{
	Q_OBJECT

public:
	DataInfoDialog(QWidget *parent);
	~DataInfoDialog();
	void Setup(DataManager *hDataManager);
	void SetDataSets(int nDataSets);
	void SetDataFileInfo(const QString& text);
	QString GetDataFileInfo() const;
	void SetDataSetInfo(int dataSetIdx, const QString& text);
	QString GetDataSetInfo(int dataSetIdx) const;
	void SetDataSetBuffering(int dataSetIdx, bool buffer);

public Q_SLOTS:
	void on_pushButton_save_clicked();
	void on_pushButton_cancel_clicked();

Q_SIGNALS:
	void Signal_UpdateDataInfo(const QString& dataInfo, const QVector<std::pair<bool, QString>>& dataSetInfo);

private:
	class DataInfoUI
	{
	public:
		DataInfoUI(QWidget *parent, int dataIdx, DataManager *hDataManager, const QString& dataLabel, QWidget *scrollAreaContents, const QString& defaultVal_dataSetInfo, bool defaultVal_buffer);
		~DataInfoUI();
		QWidget *Tab() { return this->tab; }
		QFrame *Frame() { return this->frame; }
		QPushButton *PushButton() { return this->pushButton; }
		QString DataSetInfo() const { return this->plainTextEdit->toPlainText(); }
		bool IsBuffering() const { return this->checkBox->isChecked(); }
		void SetDataSetInfo(const QString& text);
		void SetBuffering(bool buffer);
		void Reset();
		void Set(QVector<std::pair<bool, QString>>&);

		static QSizePolicy sizePolicyPushButton;
	private:
		DataBufferDialog dataBufferDialog;
		QWidget *tab;
		QHBoxLayout *tabLayout;
		QPlainTextEdit *plainTextEdit;
		QFrame *frame;
		QHBoxLayout *frameLayout;
		QPushButton *pushButton;
		QCheckBox *checkBox;
		QString resetVal_dataSetInfo;
		bool resetVal_buffer;
	};
	void AddDataSet(const QString& tabLabel, const QString& dataLabel, const QString& defaultVal_dataSetInfo = QString(), bool defaultVal_buffer = true);
	void RemoveDataSet();

	Ui::DataInfoDialog ui;
	QVector<DataInfoUI*> dataInfoUI;
	QString resetVal_dataFileInfo;
	DataManager *hDataManager;
};
