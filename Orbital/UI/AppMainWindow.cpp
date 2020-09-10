#include "AppMainWindow.h"
#include <QFileDialog>
#include <QScrollBar>

AppMainWindow::AppMainWindow(QWidget *parent)
	: QMainWindow(parent), customControls()
{
	ui.setupUi(this);
	ui.frame_customControls->setStyleSheet("#frame_customControls { border: 1px solid lightgray; }");

	PlotPanelSetup();
	CustomControlPanelSetup();

	QObject::connect(this->ui.actionCreate_New, &QAction::triggered, this, &AppMainWindow::Slot_CreateNewScript);
	QObject::connect(this->ui.actionReference_Manual, &QAction::triggered, [=] { emit Signal_ReferenceManual(); });
}

void AppMainWindow::AddExampleScript(unsigned int scriptID, const QString& script)
{
	QAction *action = new QAction(script, this);
	this->ui.menuExamples->addAction(action);
	QObject::connect(action, &QAction::triggered, [=] { emit Signal_ExampleScript(scriptID); });
}

void AppMainWindow::SetCustomControl(size_t n, const QString& label)
{
	if (n >= N_CUSTOMCONTROLS)
		return;

	this->customControls[n]->setText(label);
}

void AppMainWindow::SetCustomControls(const QStringList& customControls)
{
	if (customControls.size() != N_CUSTOMCONTROLS)
		return;

	for (unsigned int i = 0; i < N_CUSTOMCONTROLS; ++i)
		this->customControls[i]->setText(customControls.at(i));
}

void AppMainWindow::SetScriptStatus(const QString& scriptStatus, bool append)
{
	int sliderVal = this->ui.plainTextEdit_scriptStatus->verticalScrollBar()->value();

	if (append)
		this->ui.plainTextEdit_scriptStatus->appendPlainText(scriptStatus);
	else
		this->ui.plainTextEdit_scriptStatus->setPlainText(scriptStatus);

	this->ui.plainTextEdit_scriptStatus->verticalScrollBar()->setValue(sliderVal);
}

void AppMainWindow::ClearScriptStatus()
{
	this->ui.plainTextEdit_scriptStatus->clear();
}

void AppMainWindow::SetErrorStatus(const QString& errorStatus)
{
	this->ui.plainTextEdit_errorStatus->setPlainText(errorStatus);
}

void AppMainWindow::ClearErrorStatus()
{
	this->ui.plainTextEdit_errorStatus->clear();
}

void AppMainWindow::SetScriptParameterKeys(const QStringList& parameters)
{
	this->ui.tableWidget_scriptParams->setRowCount(0);

	for (int i = 0; i < parameters.size(); ++i) {
		QTableWidgetItem *paramItem = new QTableWidgetItem(parameters.at(i));
		paramItem->setFlags(paramItem->flags() & ~Qt::ItemIsEditable);
		this->ui.tableWidget_scriptParams->insertRow(i);
		this->ui.tableWidget_scriptParams->setItem(i, 0, paramItem);
	}
}

QVector<std::pair<QString, QString>> AppMainWindow::GetScriptParameterVals() const
{
	int nParams = this->ui.tableWidget_scriptParams->rowCount();
	QTableWidgetItem *k;
	QTableWidgetItem *v = Q_NULLPTR;

	QVector<std::pair<QString, QString>> params(nParams);
	for (int i = 0; i < nParams; ++i) {
		k = this->ui.tableWidget_scriptParams->item(i, 0);
		if ((v = this->ui.tableWidget_scriptParams->item(i, 1)) != Q_NULLPTR)
			params[i] = std::make_pair(k->text(), v->text());
		else
			params[i] = std::make_pair(k->text(), "");
	}

	return params;
}

void AppMainWindow::SetScriptParameterVals(const QVector<std::pair<QString, QString>>& params)
{
	for (auto p : params) {
		QList<QTableWidgetItem *> l = this->ui.tableWidget_scriptParams->findItems(p.first, Qt::MatchFixedString | Qt::MatchCaseSensitive);
		if (l.isEmpty())
			continue;
		this->ui.tableWidget_scriptParams->item(this->ui.tableWidget_scriptParams->row(l.first()), 1)->setText(p.second);
	}
}

void AppMainWindow::ClearScriptParameters()
{
	this->ui.tableWidget_scriptParams->setRowCount(0);
}

void AppMainWindow::EnableControl_Load(bool enable)
{
	this->ui.pushButton_load->setEnabled(enable);
}

void AppMainWindow::EnableControl_Run(bool enable)
{
	this->ui.pushButton_run->setEnabled(enable);
}

void AppMainWindow::EnableControl_Stop(bool enable)
{
	this->ui.pushButton_stop->setEnabled(enable);
}

void AppMainWindow::EnableControl_Custom(size_t n, bool enable)
{
	if (n > N_CUSTOMCONTROLS)
		return;

	if (n == 0) {
		for (auto i : this->customControls)
			i->setEnabled(enable);
	}
	else {
		this->customControls.at(n - 1)->setEnabled(enable);
	}
}

void AppMainWindow::EnableAutoSave(bool enable)
{
	this->ui.checkBox_autoSave->setChecked(enable);
}

QString AppMainWindow::GetUser() const
{
	return this->ui.lineEdit_userParam->text();
}

QString AppMainWindow::GetNotes() const
{
	return this->ui.plainTextEdit_scriptNotes->toPlainText();
}

void AppMainWindow::on_pushButton_load_clicked()
{
	QString filename = QFileDialog::getOpenFileName(
		this,
		tr("Open File"),
		QString(),
		tr("Python files (*.py *.pyw)")
	);
	if (filename.isEmpty())
		return;

	emit Signal_LoadModule(filename);
}

void AppMainWindow::on_pushButton_run_clicked()
{
	emit Signal_RunModule();
}

void AppMainWindow::on_pushButton_stop_clicked()
{
	emit Signal_StopModule();
}

void AppMainWindow::on_pushButton_customControl_clicked(unsigned int cc)
{
	emit Signal_CustomControl(cc);
}

void AppMainWindow::on_pushButton_save_clicked()
{
	emit Signal_Save();
}

void AppMainWindow::on_pushButton_importParams_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Parameter File"), "", tr("Text files (*.txt)"));
	if (fileName.isEmpty())
		return;

	emit Signal_ParamsImport(fileName);
}

void AppMainWindow::on_pushButton_exportParams_clicked()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save Parameter File"), "", tr("Text files (*.txt)"));
	if (fileName.isEmpty())
		return;

	emit Signal_ParamsExport(fileName);
}

void AppMainWindow::Slot_CreateNewScript()
{
	QString filename = QFileDialog::getSaveFileName(
		this,
		tr("Create new script file"),
		QString(),
		tr("Python files (*.py *.pyw)")
	);
	if (filename.isEmpty())
		return;

	emit Signal_CreateNewScript(filename);
}

void AppMainWindow::PlotPanelSetup()
{
	this->plotLayout = new QGridLayout(this->ui.scrollAreaWidgetContents_plotPanel);
	this->plotLayout->setContentsMargins(1, 1, 1, 1);
	this->plotLayout->setSpacing(4);
}

void AppMainWindow::CustomControlPanelSetup()
{
	for (unsigned int i = 0; i < N_CUSTOMCONTROLS; ++i) {
		QPushButton *pushButton = new QPushButton(this->ui.frame_customControls);
		this->ui.gridLayout_customControls->addWidget(pushButton, (i / 2), (i % 2));
		this->customControls[i] = pushButton;
		QObject::connect(pushButton, &QPushButton::clicked, [=] { this->on_pushButton_customControl_clicked(i); });
	}
}