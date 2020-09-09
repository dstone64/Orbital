#include "SaveDialog.h"
#include <QFileDialog>
#include <QFileInfo>

SaveDataBox::SaveDataBox(const QString& dataName, bool checked, QWidget * parent) : groupBox(new QGroupBox(parent)), resetState(checked)
{
	this->layout = new QHBoxLayout(this->groupBox);
	this->layout->setSpacing(6);
	this->layout->setContentsMargins(11, 11, 11, 11);
	this->checkBox = new QCheckBox(dataName, this->groupBox);
	this->checkBox->setChecked(checked);
	this->layout->addWidget(this->checkBox);
}

SaveDataBox::~SaveDataBox()
{
	delete this->groupBox;
}

void SaveDataBox::Set()
{
	this->resetState = this->checkBox->isChecked();
}

void SaveDataBox::Reset()
{
	this->checkBox->setChecked(this->resetState);
}

SaveDialog::SaveDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint), hDataManager(nullptr)
{
	ui.setupUi(this);
	QObject::connect(this->ui.buttonBox, &QDialogButtonBox::accepted, this, &SaveDialog::on_pushButton_save_clicked);
	QObject::connect(this->ui.buttonBox, &QDialogButtonBox::rejected, this, &SaveDialog::on_pushButton_cancel_clicked);
}

SaveDialog::~SaveDialog()
{
	for (auto i : this->dataBoxes)
		delete i;
}

void SaveDialog::Setup(DataManager *hDataManager)
{
	this->hDataManager = hDataManager;

	this->dataBoxes.push_back(new SaveDataBox("Unplotted Data", true, this->ui.scrollAreaWidgetContents));
	this->ui.verticalLayout_dataSelect->insertWidget(0, this->dataBoxes.back()->groupBox);
	this->dataBoxes.push_back(new SaveDataBox("Plot 1", true, this->ui.scrollAreaWidgetContents));
	this->ui.verticalLayout_dataSelect->insertWidget(1, this->dataBoxes.back()->groupBox);
}

void SaveDialog::SetSavePath(const QString& path)
{
	this->saveFilePath = QString(path);
}

void SaveDialog::Close(bool saveError)
{
	if (saveError)
		SetError();
	else
		this->close();

	this->ui.buttonBox->setEnabled(true);
}

void SaveDialog::on_pushButton_save_clicked()
{
	QVector<bool> dataSetsToSave;
	QString saveFile = QFileDialog::getSaveFileName(
		this,
		tr("Save File"),
		this->saveFilePath,
		tr("CSV files (*.csv);;Text files (*.txt);;All files (*.*)"),
		(QString*)nullptr,
		QFileDialog::DontConfirmOverwrite
	);
	if (saveFile.isEmpty())
		return;
	ClearError();
	this->ui.buttonBox->setEnabled(false);

	QFileInfo fileInfo(saveFile);
	this->saveFilePath = fileInfo.absolutePath();
	for (auto dataBox : this->dataBoxes) {
		dataBox->Set();
		dataSetsToSave.push_back(dataBox->resetState);
	}

	emit Signal_Save(saveFile, dataSetsToSave, this->ui.checkBox_timeStamp->isChecked());
}

void SaveDialog::on_pushButton_cancel_clicked()
{
	for (auto dataBox : this->dataBoxes) {
		dataBox->Reset();
	}
	this->close();
}

void SaveDialog::showEvent(QShowEvent * qEvent)
{
	SetDataBoxes(this->hDataManager->DataSetCount());
	ClearError();
	QDialog::showEvent(qEvent);
}

void SaveDialog::SetDataBoxes(int n)
{
	if (n <= 2)
		return; // Should always have at least Unplotted and Plot 1

	if (n > this->dataBoxes.size()) {
		// Add
		for (int i = this->dataBoxes.size(); i < n; ++i) {
			SaveDataBox *saveDataBox = new SaveDataBox(QString("Plot %1 Data").arg(QString::number(i)), true, this->ui.scrollAreaWidgetContents);
			this->ui.verticalLayout_dataSelect->insertWidget(i, saveDataBox->groupBox);
			this->dataBoxes.push_back(saveDataBox);
		}
	}
	else {
		// Remove
		for (int i = this->dataBoxes.size(); i > n; --i) {
			this->ui.verticalLayout_dataSelect->removeWidget(this->dataBoxes.back()->groupBox);
			delete this->dataBoxes.back();
			this->dataBoxes.pop_back();
		}
	}
}

void SaveDialog::SetError()
{
	this->ui.label_error->setText("ERROR: SAVE FAILED");
}

void SaveDialog::ClearError()
{
	this->ui.label_error->clear();
}