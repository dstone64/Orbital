#pragma once

#include <QDialog>
#include "ui_SaveDialog.h"
#include <QCheckBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QString>
#include <QVector>
#include "DataManager.h"

class SaveDataBox
{
public:
	SaveDataBox(const QString& dataName, bool checked, QWidget * parent);
	~SaveDataBox();

	void Set();
	void Reset();

	QGroupBox * groupBox;
	QHBoxLayout * layout;
	QCheckBox * checkBox;
	bool resetState;
};

class SaveDialog : public QDialog
{
	Q_OBJECT

public:
	SaveDialog(QWidget *parent);
	~SaveDialog();

	void Setup(DataManager *hDataManager);
	void SetSavePath(const QString& path);
	void Close(bool saveError);

public Q_SLOTS:
	void on_pushButton_save_clicked();
	void on_pushButton_cancel_clicked();

Q_SIGNALS:
	void Signal_Save(const QString&, const QVector<bool>&, bool timeStamp);

protected:
	void showEvent(QShowEvent * qEvent);

private:
	void SetDataBoxes(int n);
	void SetError();
	void ClearError();

	Ui::SaveDialog ui;
	DataManager *hDataManager;
	QVector<SaveDataBox *> dataBoxes;
	QString saveFilePath;
};
