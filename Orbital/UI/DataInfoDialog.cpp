#include "DataInfoDialog.h"

QSizePolicy DataInfoDialog::DataInfoUI::sizePolicyPushButton(QSizePolicy::Fixed, QSizePolicy::Fixed);

DataInfoDialog::DataInfoDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui.setupUi(this);

	DataInfoDialog::DataInfoUI::sizePolicyPushButton.setHorizontalStretch(0);
	DataInfoDialog::DataInfoUI::sizePolicyPushButton.setVerticalStretch(0);
	DataInfoDialog::DataInfoUI::sizePolicyPushButton.setHeightForWidth(false);
}

DataInfoDialog::~DataInfoDialog()
{
}

void DataInfoDialog::Setup(DataManager *hDataManager)
{
	this->hDataManager = hDataManager;

	AddDataSet("0", "Unplotted Data");
	AddDataSet("1", "Plot 1");
}

void DataInfoDialog::SetDataSets(int nDataSets)
{
	if (nDataSets < 1)
		return;

	if (nDataSets > this->dataInfoUI.size()) {
		for (int i = this->dataInfoUI.size(); i < nDataSets; ++i)
			AddDataSet(QString::number(i), QString("Plot ").append(QString::number(i)));
	}
	else {
		for (int i = this->dataInfoUI.size(); i > nDataSets; --i)
			RemoveDataSet();
	}
}

void DataInfoDialog::SetDataFileInfo(const QString& text)
{
	this->ui.plainTextEdit_dataFileInfo->setPlainText(text);
	this->resetVal_dataFileInfo = QString(text);
}

QString DataInfoDialog::GetDataFileInfo() const
{
	return this->resetVal_dataFileInfo;
}

void DataInfoDialog::SetDataSetInfo(int dataSetIdx, const QString& text)
{
	if (dataSetIdx >= this->dataInfoUI.size())
		return;

	this->dataInfoUI.at(dataSetIdx)->SetDataSetInfo(text);
}

QString DataInfoDialog::GetDataSetInfo(int dataSetIdx) const
{
	if (dataSetIdx >= this->dataInfoUI.size())
		return QString();

	return this->dataInfoUI.at(dataSetIdx)->DataSetInfo();
}

void DataInfoDialog::SetDataSetBuffering(int dataSetIdx, bool buffer)
{
	if (dataSetIdx >= this->dataInfoUI.size())
		return;

	this->dataInfoUI.at(dataSetIdx)->SetBuffering(buffer);
}

void DataInfoDialog::on_pushButton_save_clicked()
{
	QVector<std::pair<bool, QString>> dataSetInfo;

	this->resetVal_dataFileInfo = this->ui.plainTextEdit_dataFileInfo->toPlainText();
	for (auto itr = this->dataInfoUI.begin(); itr != this->dataInfoUI.end(); ++itr)
		(*itr)->Set(dataSetInfo);

	this->close();
	emit Signal_UpdateDataInfo(this->resetVal_dataFileInfo, dataSetInfo);
}

void DataInfoDialog::on_pushButton_cancel_clicked()
{
	this->ui.plainTextEdit_dataFileInfo->setPlainText(this->resetVal_dataFileInfo);
	for (auto itr = this->dataInfoUI.begin(); itr != this->dataInfoUI.end(); ++itr)
		(*itr)->Reset();

	this->close();
}

void DataInfoDialog::AddDataSet(const QString& tabLabel, const QString& dataLabel, const QString& defaultVal_dataSetInfo, bool defaultVal_buffer)
{
	DataInfoUI *diui = new DataInfoUI(this, this->dataInfoUI.size(), this->hDataManager, dataLabel, this->ui.scrollAreaWidgetContents_data, defaultVal_dataSetInfo, defaultVal_buffer);
	this->ui.tabWidget->addTab(diui->Tab(), tabLabel);
	this->ui.verticalLayout_scrollAreaWidgetContents_data->insertWidget(this->dataInfoUI.size(), diui->Frame());
	this->dataInfoUI.push_back(diui);
}

void DataInfoDialog::RemoveDataSet()
{
	DataInfoUI *diui = this->dataInfoUI.takeLast();
	this->ui.tabWidget->removeTab(this->dataInfoUI.size());
	this->ui.verticalLayout_scrollAreaWidgetContents_data->removeWidget(diui->Frame());
	delete diui;
}

DataInfoDialog::DataInfoUI::DataInfoUI(QWidget *parent, int dataIdx, DataManager *hDataManager, const QString& dataLabel, QWidget *scrollAreaContents, const QString& defaultVal_dataSetInfo, bool defaultVal_buffer)
	: dataBufferDialog(parent, dataIdx, hDataManager)
{
	this->tab = new QWidget();
	this->tabLayout = new QHBoxLayout(this->tab);
	this->plainTextEdit = new QPlainTextEdit(defaultVal_dataSetInfo, this->tab);

	this->tabLayout->setSpacing(6);
	this->tabLayout->setContentsMargins(6, 6, 6, 6);
	this->tabLayout->addWidget(this->plainTextEdit);

	this->frame = new QFrame(scrollAreaContents);
	this->frameLayout = new QHBoxLayout(this->frame);
	this->pushButton = new QPushButton(this->frame);
	this->checkBox = new QCheckBox(dataLabel, this->frame);
	this->checkBox->setChecked(defaultVal_buffer);

	this->frameLayout->setSpacing(6);
	this->frameLayout->setContentsMargins(0, 0, 0, 0);
	this->pushButton->setSizePolicy(DataInfoUI::sizePolicyPushButton);
	this->pushButton->setMaximumSize(QSize(24, 20));
	this->frameLayout->addWidget(this->pushButton);
	this->frameLayout->addWidget(this->checkBox);

	QObject::connect(this->pushButton, &QPushButton::clicked, &this->dataBufferDialog, &DataBufferDialog::open);
}

DataInfoDialog::DataInfoUI::~DataInfoUI()
{
	delete this->tab;
	delete this->frame;
}

void DataInfoDialog::DataInfoUI::SetDataSetInfo(const QString& text)
{
	this->plainTextEdit->setPlainText(text);
	this->resetVal_dataSetInfo = QString(text);
}

void DataInfoDialog::DataInfoUI::SetBuffering(bool buffer)
{
	this->checkBox->setChecked(buffer);
	this->resetVal_buffer = buffer;
}

void DataInfoDialog::DataInfoUI::Reset()
{
	this->plainTextEdit->setPlainText(this->resetVal_dataSetInfo);
	this->checkBox->setChecked(this->resetVal_buffer);
}

void DataInfoDialog::DataInfoUI::Set(QVector<std::pair<bool, QString>>& dataSetInfo)
{
	this->resetVal_dataSetInfo = this->plainTextEdit->toPlainText();
	this->resetVal_buffer = this->checkBox->isChecked();
	dataSetInfo.push_back(std::make_pair(this->resetVal_buffer, this->resetVal_dataSetInfo));
}