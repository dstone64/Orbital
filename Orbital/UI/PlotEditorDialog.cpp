#include "PlotEditorDialog.h"
#include <QSpacerItem>

QSizePolicy PlotEditorDialog::PlotEditorTabItem::sizePolicy_PF(QSizePolicy::Preferred, QSizePolicy::Fixed);
QSizePolicy PlotEditorDialog::PlotEditorTabItem::sizePolicy_FP(QSizePolicy::Fixed, QSizePolicy::Preferred);

const QDoubleValidator * PlotEditorDialog::PlotEditorTab::qVal_double = new QDoubleValidator();
const QIntValidator * PlotEditorDialog::PlotEditorTab::qVal_int = new QIntValidator(1, INT32_MAX);

PlotEditorDialog::PlotEditorDialog(QWidget *parent) :
	QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint),
	plotArrangementDialog(this),
	pixmap_check(QString::fromUtf8(":/AppMainWindow/Resources/checkmark.png")),
	pixmap_exclamation(QString::fromUtf8(":/AppMainWindow/Resources/exclamationmark.png")),
	minW(PLOT_DEFAULT_DIMENSION),
	minH(PLOT_DEFAULT_DIMENSION),
	revertState(true),
	resetPlots(false)
{
	ui.setupUi(this);

	this->ui.lineEdit_plotMinWidth->setValidator(new QIntValidator(1, PLOT_MAX_DIMENSION, this));
	this->ui.lineEdit_plotMinHeight->setValidator(new QIntValidator(1, PLOT_MAX_DIMENSION, this));

	this->ui.lineEdit_plotMinWidth->setText(QString::number(PLOT_DEFAULT_DIMENSION));
	this->ui.lineEdit_plotMinHeight->setText(QString::number(PLOT_DEFAULT_DIMENSION));

	this->buttonGrid = new QButtonGrid(this->ui.frame_globalSettings, PLOTS_MAX_ROWS, PLOTS_MAX_COLS);
	this->ui.verticalLayout_globalSettings->insertWidget(2, this->buttonGrid);
	this->plotArrangement = this->buttonGrid->buttonArrangement();
	QObject::connect(this->buttonGrid, &QButtonGrid::gridChanged, this, &PlotEditorDialog::Slot_GridChanged);

	AddTab(PlotProperties::defaultPlotProperties);
	this->ui.label_arrangementSet->setPixmap(this->pixmap_check);
}

PlotEditorDialog::~PlotEditorDialog()
{
	while (this->DelTab() != 0);
}

int PlotEditorDialog::AddTab(const PlotProperties& p)
{
	PlotEditorTab *pet = new PlotEditorTab(p);

	this->tabs.append(pet);
	return this->ui.tabWidget_plotSettings->addTab(pet->tab, QString::number(this->tabs.size()));
}

int PlotEditorDialog::DelTab()
{
	if (this->tabs.size() < 1)
		return 0;

	this->ui.tabWidget_plotSettings->removeTab(this->tabs.size());
	delete this->tabs.last();
	this->tabs.removeLast();
	return this->tabs.size();
}

PlotEditorDialog::PlotEditError PlotEditorDialog::SetPlotArrangement(const QVector<GridPoint>& plotArrangement)
{
	int currentPlotCount = this->tabs.size();
	int newPlotCount = plotArrangement.size();

	switch (this->buttonGrid->setButtonArrangement(plotArrangement)) {
	case QButtonGrid::QButtonGrid_Err::VALID:
		break;
	case QButtonGrid::QButtonGrid_Err::INVALID_SIZE:
		return PlotEditError::PLOTARRANGE_INVALID_SIZE;
	case QButtonGrid::QButtonGrid_Err::INVALID_VALUE:
		return PlotEditError::PLOTARRANGE_INVALID_VALUE;
	}
	this->plotArrangement = QVector<GridPoint>(plotArrangement);

	if (currentPlotCount < newPlotCount) {
		for (int i = currentPlotCount; i < newPlotCount; ++i)
			AddTab(PlotProperties::defaultPlotProperties);
	}
	else {
		for (int i = newPlotCount; i < currentPlotCount; ++i)
			DelTab();
	}

	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::GetPlotProperties(size_t plotIdx, PlotProperties& plotProperties) const
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	plotProperties = this->tabs.at(plotIdx)->GetPlotProperties();
	plotProperties.minH = this->minH * this->plotArrangement.at(plotIdx).rowspan;
	plotProperties.minW = this->minW * this->plotArrangement.at(plotIdx).colspan;
	return PlotEditError::NONE;
}

void PlotEditorDialog::GetPlotMinSize(int& w, int& h) const
{
	w = this->minW;
	h = this->minH;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_Title2D(size_t plotIdx, const QString& title)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.twoD.title->lineEdit->setText(title);
	this->tabs.at(plotIdx)->tabItems.twoD.title->resetVal = QString(title);
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_XLabel2D(size_t plotIdx, const QString& label)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.twoD.xAxis->lineEdit->setText(label);
	this->tabs.at(plotIdx)->tabItems.twoD.xAxis->resetVal = QString(label);
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_YLabel2D(size_t plotIdx, const QString& label)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.twoD.yAxis->lineEdit->setText(label);
	this->tabs.at(plotIdx)->tabItems.twoD.yAxis->resetVal = QString(label);
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_LineStyle(size_t plotIdx, const QString& ls)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	int idx = AppPlot::lsOptions.indexOfKey(ls);
	if (idx < 0)
		return PlotEditError::NO_SUCH_VALUE;

	this->tabs.at(plotIdx)->tabItems.twoD.lineStyle->comboBox->setCurrentIndex(idx);
	this->tabs.at(plotIdx)->tabItems.twoD.lineStyle->resetVal = idx;
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_ScatterStyle(size_t plotIdx, const QString& ss)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	int idx = AppPlot::ssOptions.indexOfKey(ss);
	if (idx < 0)
		return PlotEditError::NO_SUCH_VALUE;

	this->tabs.at(plotIdx)->tabItems.twoD.scatterStyle->comboBox->setCurrentIndex(idx);
	this->tabs.at(plotIdx)->tabItems.twoD.scatterStyle->resetVal = idx;
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_ScatterSize(size_t plotIdx, double ssz)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	int idx = AppPlot::sszOptions.indexOfValue(ssz);
	if (idx < 0)
		return PlotEditError::NO_SUCH_VALUE;

	this->tabs.at(plotIdx)->tabItems.twoD.scatterSize->comboBox->setCurrentIndex(idx);
	this->tabs.at(plotIdx)->tabItems.twoD.scatterSize->resetVal = idx;
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_Color(size_t plotIdx, const QString& color)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	int idx = AppPlot::colorOptions.indexOfKey(color);
	if (idx < 0)
		return PlotEditError::NO_SUCH_VALUE;

	this->tabs.at(plotIdx)->tabItems.twoD.color->comboBox->setCurrentIndex(idx);
	this->tabs.at(plotIdx)->tabItems.twoD.color->resetVal = idx;
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_ShowCM(size_t plotIdx, bool show)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.show->checkBox->setChecked(show);
	this->tabs.at(plotIdx)->tabItems.colorMap.show->resetVal = show;
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_SetupCM(size_t plotIdx, double xMin, double xMax, double yMin, double yMax, int xSize, int ySize)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.xRange->lineEdit_min->setText(QString::number(xMin));
	this->tabs.at(plotIdx)->tabItems.colorMap.xRange->lineEdit_max->setText(QString::number(xMax));
	this->tabs.at(plotIdx)->tabItems.colorMap.xRange->Set();
	this->tabs.at(plotIdx)->tabItems.colorMap.yRange->lineEdit_min->setText(QString::number(yMin));
	this->tabs.at(plotIdx)->tabItems.colorMap.yRange->lineEdit_max->setText(QString::number(yMax));
	this->tabs.at(plotIdx)->tabItems.colorMap.yRange->Set();
	this->tabs.at(plotIdx)->tabItems.colorMap.dataSize->lineEdit_min->setText(QString::number(xSize));
	this->tabs.at(plotIdx)->tabItems.colorMap.dataSize->lineEdit_max->setText(QString::number(ySize));
	this->tabs.at(plotIdx)->tabItems.colorMap.dataSize->Set();
	this->tabs.at(plotIdx)->tabItems.colorMap.show->checkBox->setChecked(true);
	this->tabs.at(plotIdx)->tabItems.colorMap.show->resetVal = true;
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_TitleCM(size_t plotIdx, const QString& title)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.title->lineEdit->setText(title);
	this->tabs.at(plotIdx)->tabItems.colorMap.title->resetVal = QString(title);
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_XLabelCM(size_t plotIdx, const QString& label)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.xAxis->lineEdit->setText(label);
	this->tabs.at(plotIdx)->tabItems.colorMap.xAxis->resetVal = QString(label);
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_YLabelCM(size_t plotIdx, const QString& label)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.yAxis->lineEdit->setText(label);
	this->tabs.at(plotIdx)->tabItems.colorMap.yAxis->resetVal = QString(label);
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_ZLabel(size_t plotIdx, const QString & label)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.zAxis->lineEdit->setText(label);
	this->tabs.at(plotIdx)->tabItems.colorMap.zAxis->resetVal = QString(label);
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_XRange(size_t plotIdx, double xMin, double xMax)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.xRange->lineEdit_min->setText(QString::number(xMin));
	this->tabs.at(plotIdx)->tabItems.colorMap.xRange->lineEdit_max->setText(QString::number(xMax));
	this->tabs.at(plotIdx)->tabItems.colorMap.xRange->Set();
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_YRange(size_t plotIdx, double yMin, double yMax)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.yRange->lineEdit_min->setText(QString::number(yMin));
	this->tabs.at(plotIdx)->tabItems.colorMap.yRange->lineEdit_max->setText(QString::number(yMax));
	this->tabs.at(plotIdx)->tabItems.colorMap.yRange->Set();
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_ZRange(size_t plotIdx, double zMin, double zMax, bool manual)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.zRange->lineEdit_min->setText(QString::number(zMin));
	this->tabs.at(plotIdx)->tabItems.colorMap.zRange->lineEdit_max->setText(QString::number(zMax));
	this->tabs.at(plotIdx)->tabItems.colorMap.zRange->checkBox->setChecked(manual);
	this->tabs.at(plotIdx)->tabItems.colorMap.zRange->Set();
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_DataSize(size_t plotIdx, int xSize, int ySize)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	this->tabs.at(plotIdx)->tabItems.colorMap.dataSize->lineEdit_min->setText(QString::number(xSize));
	this->tabs.at(plotIdx)->tabItems.colorMap.dataSize->lineEdit_max->setText(QString::number(ySize));
	this->tabs.at(plotIdx)->tabItems.colorMap.dataSize->Set();
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_ColorMin(size_t plotIdx, const QString& color)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	int idx = AppPlot::colorOptions.indexOfKey(color);
	if (idx < 0)
		return PlotEditError::NO_SUCH_VALUE;

	this->tabs.at(plotIdx)->tabItems.colorMap.colorMin->comboBox->setCurrentIndex(idx);
	this->tabs.at(plotIdx)->tabItems.colorMap.colorMin->resetVal = idx;
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_ColorMid(size_t plotIdx, const QString& color)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	int idx = AppPlot::colorOptions.indexOfKey(color);
	if (idx < 0)
		return PlotEditError::NO_SUCH_VALUE;

	this->tabs.at(plotIdx)->tabItems.colorMap.colorMid->comboBox->setCurrentIndex(idx);
	this->tabs.at(plotIdx)->tabItems.colorMap.colorMid->resetVal = idx;
	return PlotEditError::NONE;
}

PlotEditorDialog::PlotEditError PlotEditorDialog::EditPlot_ColorMax(size_t plotIdx, const QString& color)
{
	if (plotIdx >= this->tabs.size())
		return PlotEditError::INDEX_OUT_OF_RANGE;

	int idx = AppPlot::colorOptions.indexOfKey(color);
	if (idx < 0)
		return PlotEditError::NO_SUCH_VALUE;

	this->tabs.at(plotIdx)->tabItems.colorMap.colorMax->comboBox->setCurrentIndex(idx);
	this->tabs.at(plotIdx)->tabItems.colorMap.colorMax->resetVal = idx;
	return PlotEditError::NONE;
}

void PlotEditorDialog::showEvent(QShowEvent *e)
{
	QDialog::showEvent(e);

	// Store current button grid
	this->buttonGridTemp = new QButtonGrid(*this->buttonGrid);

	// Store current tabs
	this->tabsTemp.clear();
	for (auto itr = this->tabs.begin(); itr != this->tabs.end(); ++itr)
		this->tabsTemp.push_back((*itr)->GetPlotProperties());

	this->revertState = true;
}

void PlotEditorDialog::closeEvent(QCloseEvent *e)
{
	if (this->revertState) {
		// Revert button grid
		QButtonGrid *bg = this->buttonGrid;
		this->ui.verticalLayout_globalSettings->replaceWidget(this->buttonGrid, this->buttonGridTemp);
		this->buttonGrid = this->buttonGridTemp;
		this->buttonGridTemp = bg;
		this->plotArrangement = this->buttonGrid->buttonArrangement();
		QObject::connect(this->buttonGrid, &QButtonGrid::gridChanged, this, &PlotEditorDialog::Slot_GridChanged);
		this->ui.label_arrangementSet->setPixmap(this->pixmap_check);

		// Revert tabs
		int currentTabCount = this->tabs.size();
		int previousTabCount = this->tabsTemp.size();
		if (currentTabCount < previousTabCount) {
			for (int i = currentTabCount; i < previousTabCount; ++i)
				AddTab(this->tabsTemp.at(i));
		}
		else {
			for (int i = previousTabCount; i < currentTabCount; ++i)
				DelTab();
		}
	}
	delete this->buttonGridTemp;
	this->resetPlots = false;

	QDialog::closeEvent(e);
}

void PlotEditorDialog::on_pushButton_save_clicked()
{
	QVector<size_t> plotUpdateQueue;

	Set();
	if (this->resetPlots)
		emit Signal_UpdatePlotArrangement(this->plotArrangement);

	for (size_t i = 0; i < this->tabs.size(); ++i) {
		if (this->tabs.at(i)->queuedForUpdate) {
			plotUpdateQueue.push_back(i);
			this->tabs.at(i)->queuedForUpdate = false;
		}
	}
	if (plotUpdateQueue.size() > 0)
		emit Signal_UpdatePlotProperties(plotUpdateQueue);

	this->revertState = false;
	this->close();
}

void PlotEditorDialog::on_pushButton_cancel_clicked()
{
	Reset();
	this->revertState = true;
	this->close();
}

void PlotEditorDialog::on_pushButton_apply_clicked()
{
	this->plotArrangement = this->buttonGrid->buttonArrangement();
	this->resetPlots = true;

	int currentPlotCount = this->tabs.size();
	int newPlotCount = this->plotArrangement.size();

	if (currentPlotCount < newPlotCount) {
		for (int i = currentPlotCount; i < newPlotCount; ++i)
			AddTab(PlotProperties::defaultPlotProperties);
	}
	else {
		for (int i = newPlotCount; i < currentPlotCount; ++i)
			DelTab();
	}

	this->ui.label_arrangementSet->setPixmap(this->pixmap_check);
}

void PlotEditorDialog::on_pushButton_gridArrangement_clicked()
{
	this->plotArrangementDialog.SetPlotArrangement(this->plotArrangement);
	this->plotArrangementDialog.open();
}

void PlotEditorDialog::Slot_GridChanged()
{
	this->ui.label_arrangementSet->setPixmap(this->pixmap_exclamation);
}

/*
** Resets all user input prompts to their default values.
** Used by the cancellation signal.
*/
void PlotEditorDialog::Reset()
{
	this->ui.lineEdit_plotMinWidth->setText(QString::number(this->minW));
	this->ui.lineEdit_plotMinHeight->setText(QString::number(this->minH));

	for (auto itr = this->tabs.begin(); itr != this->tabs.end(); ++itr)
		(*itr)->Reset();
}

/*
** Sets the default values of all UI inputs to their current values.
** Used by the save signal.
*/
void PlotEditorDialog::Set()
{
	for (auto itr = this->tabs.begin(); itr != this->tabs.end(); ++itr)
		(*itr)->Set();

	if (this->ui.lineEdit_plotMinWidth->hasAcceptableInput() &&
		this->ui.lineEdit_plotMinWidth->text().toInt() != this->minW) {
		this->minW = this->ui.lineEdit_plotMinWidth->text().toInt();
		SetTabsQueuedForUpdate();
	}
	else {
		this->ui.lineEdit_plotMinWidth->setText(QString::number(this->minW));
	}

	if (this->ui.lineEdit_plotMinHeight->hasAcceptableInput() &&
		this->ui.lineEdit_plotMinHeight->text().toInt() != this->minH) {
		this->minH = this->ui.lineEdit_plotMinHeight->text().toInt();
		SetTabsQueuedForUpdate();
	}
	else {
		this->ui.lineEdit_plotMinHeight->setText(QString::number(this->minH));
	}

	if (this->resetPlots)
		SetTabsQueuedForUpdate();
}

/*
** Sets the update status for all tabs. Used when a global setting has changed.
*/
void PlotEditorDialog::SetTabsQueuedForUpdate(bool queuedForUpdate)
{
	for (auto itr = this->tabs.begin(); itr != this->tabs.end(); ++itr)
		(*itr)->queuedForUpdate = queuedForUpdate;
}

PlotEditorDialog::PlotEditorTabItem::PlotEditorTabItem(QWidget* parent, PlotEditorTabItem_t type, const QString& label) : type(type)
{
	this->frame = new QFrame(parent);
	sizePolicy_PF.setHeightForWidth(this->frame->sizePolicy().hasHeightForWidth());
	this->frame->setSizePolicy(sizePolicy_PF);
	this->frame->setAutoFillBackground(true);
	this->frame->setFrameShape(QFrame::Box);
	this->frame->setFrameShadow(QFrame::Raised);

	this->label = new QLabel(label, this->frame);
	sizePolicy_FP.setHeightForWidth(this->label->sizePolicy().hasHeightForWidth());
	this->label->setSizePolicy(sizePolicy_FP);
	this->label->setMinimumSize(QSize(128, 0));
	this->label->setFrameShape(QFrame::Box);
	this->label->setFrameShadow(QFrame::Raised);

	this->hlo = new QHBoxLayout(this->frame);
	this->hlo->setSpacing(6);
	this->hlo->setContentsMargins(4, 4, 4, 4);
	this->hlo->addWidget(this->label);
}

PlotEditorDialog::TabItem_Text::TabItem_Text(
	QWidget* parent, const QString& label, const QString& resetVal = QString())
	: PlotEditorTabItem(parent, TEXT, label), resetVal(resetVal)
{
	this->lineEdit = new QLineEdit(resetVal, frame);
	this->hlo->addWidget(lineEdit);
}

void PlotEditorDialog::TabItem_Text::Reset()
{
	this->lineEdit->setText(this->resetVal);
}

bool PlotEditorDialog::TabItem_Text::Set()
{
	bool retval = (QString::compare(this->lineEdit->text(), this->resetVal) != 0);
	if (retval)
		this->resetVal = QString(this->lineEdit->text());
	return retval;
}

PlotEditorDialog::TabItem_Combo::TabItem_Combo(
	QWidget* parent, const QString& label, const QVector<QString>& options, int resetVal = 0)
	: PlotEditorTabItem(parent, COMBO, label), resetVal(resetVal)
{
	this->comboBox = new QComboBox(this->frame);
	this->hlo->addWidget(comboBox);
	for (QVector<const QString>::iterator itr = options.begin(); itr != options.end(); ++itr)
		this->comboBox->addItem(*itr);
	this->comboBox->setCurrentIndex(resetVal);
}

void PlotEditorDialog::TabItem_Combo::Reset()
{
	this->comboBox->setCurrentIndex(this->resetVal);
}

bool PlotEditorDialog::TabItem_Combo::Set()
{
	bool retval = (this->comboBox->currentIndex() != this->resetVal);
	if (retval)
		this->resetVal = this->comboBox->currentIndex();
	return retval;
}

PlotEditorDialog::TabItem_Check::TabItem_Check(
	QWidget* parent, const QString& label, bool resetVal = false)
	: PlotEditorTabItem(parent, CHECK, label), resetVal(resetVal)
{
	this->checkBox = new QCheckBox(this->frame);
	this->hlo->addWidget(this->checkBox);
	this->checkBox->setChecked(resetVal);
}

void PlotEditorDialog::TabItem_Check::Reset()
{
	this->checkBox->setChecked(this->resetVal);
}

bool PlotEditorDialog::TabItem_Check::Set()
{
	bool retval = (this->checkBox->isChecked() != this->resetVal);
	if (retval)
		this->resetVal = this->checkBox->isChecked();
	return retval;
}

PlotEditorDialog::TabItem_Interval::TabItem_Interval(
	QWidget* parent, const QString& label, const QValidator* v, const QString& resetVal_min, const QString& resetVal_max)
	: PlotEditorTabItem(parent, INTERVAL, label), resetVal_min(resetVal_min), resetVal_max(resetVal_max)
{
	this->lineEdit_min = new QLineEdit(resetVal_min, this->frame);
	this->lineEdit_max = new QLineEdit(resetVal_max, this->frame);
	this->lineEdit_min->setValidator(v);
	this->lineEdit_max->setValidator(v);
	this->lineEdit_min->setAlignment(Qt::AlignRight);
	this->lineEdit_max->setAlignment(Qt::AlignRight);
	this->hlo->addWidget(lineEdit_min);
	this->hlo->addWidget(lineEdit_max);
}

void PlotEditorDialog::TabItem_Interval::Reset()
{
	this->lineEdit_min->setText(this->resetVal_min);
	this->lineEdit_max->setText(this->resetVal_max);
}

bool PlotEditorDialog::TabItem_Interval::Set()
{
	bool retval = false;
	if (this->lineEdit_min->hasAcceptableInput() && (QString::compare(this->lineEdit_min->text(), this->resetVal_min) != 0)) {
		this->resetVal_min = QString(this->lineEdit_min->text());
		retval = true;
	}
	else {
		this->lineEdit_min->setText(this->resetVal_min);
	}
	if (this->lineEdit_max->hasAcceptableInput() && (QString::compare(this->lineEdit_max->text(), this->resetVal_max) != 0)) {
		this->resetVal_max = QString(this->lineEdit_max->text());
		retval = true;
	}
	else {
		this->lineEdit_max->setText(this->resetVal_max);
	}
	return retval;
}

PlotEditorDialog::TabItem_IntCheck::TabItem_IntCheck(
	QWidget* parent, const QString& label, const QValidator* v, const QString& resetVal_min, const QString& resetVal_max, bool resetVal_isChecked)
	: PlotEditorTabItem(parent, INTCHECK, label), resetVal_isChecked(resetVal_isChecked), resetVal_min(resetVal_min), resetVal_max(resetVal_max)
{
	this->checkBox = new QCheckBox(this->frame);
	this->lineEdit_min = new QLineEdit(resetVal_min, this->frame);
	this->lineEdit_max = new QLineEdit(resetVal_max, this->frame);
	this->lineEdit_min->setValidator(v);
	this->lineEdit_max->setValidator(v);
	this->lineEdit_min->setAlignment(Qt::AlignRight);
	this->lineEdit_max->setAlignment(Qt::AlignRight);
	this->hlo->addWidget(this->checkBox);
	this->hlo->addWidget(this->lineEdit_min);
	this->hlo->addWidget(this->lineEdit_max);
	this->checkBox->setChecked(resetVal_isChecked);
}

void PlotEditorDialog::TabItem_IntCheck::Reset()
{
	this->checkBox->setChecked(this->resetVal_isChecked);
	this->lineEdit_min->setText(this->resetVal_min);
	this->lineEdit_max->setText(this->resetVal_max);
}

bool PlotEditorDialog::TabItem_IntCheck::Set()
{
	bool retval = false;
	if (this->checkBox->isChecked() != this->resetVal_isChecked) {
		this->resetVal_isChecked = this->checkBox->isChecked();
		retval = true;
	}
	if (this->lineEdit_min->hasAcceptableInput() && (QString::compare(this->lineEdit_min->text(), this->resetVal_min) != 0)) {
		this->resetVal_min = QString(this->lineEdit_min->text());
		retval = true;
	}
	else {
		this->lineEdit_min->setText(this->resetVal_min);
	}
	if (this->lineEdit_max->hasAcceptableInput() && (QString::compare(this->lineEdit_max->text(), this->resetVal_max) != 0)) {
		this->resetVal_max = QString(this->lineEdit_max->text());
		retval = true;
	}
	else {
		this->lineEdit_max->setText(this->resetVal_max);
	}
	return retval;
}

PlotEditorDialog::PlotEditorTab::PlotEditorTab(const PlotProperties& p)
	: queuedForUpdate(false)
{
	this->tab = new QWidget();

	this->tabLayout = new QHBoxLayout(this->tab);
	this->tabLayout->setSpacing(6);
	this->tabLayout->setContentsMargins(0, 0, 0, 0);

	this->tabWidget = new QTabWidget(this->tab);

// TWO-DIMENSIONAL PLOT (2D) TAB
	this->tab_2D = new QWidget();

	this->vlo_2D = new QVBoxLayout(this->tab_2D);
	this->vlo_2D->setSpacing(6);
	this->vlo_2D->setContentsMargins(0, 0, 0, 0);

	this->scrollArea_2D = new QScrollArea(this->tab_2D);
	this->scrollArea_2D->setFrameShape(QFrame::NoFrame);
	this->scrollArea_2D->setLineWidth(0);
	this->scrollArea_2D->setWidgetResizable(true);

	this->scrollAreaWidgetContents_2D = new QWidget();

	this->vlo_scrollAreaWidgetContents_2D = new QVBoxLayout(this->scrollAreaWidgetContents_2D);
	this->vlo_scrollAreaWidgetContents_2D->setSpacing(6);
	this->vlo_scrollAreaWidgetContents_2D->setContentsMargins(11, 11, 11, 11);

	this->tabItems.twoD.title = new TabItem_Text(scrollAreaWidgetContents_2D,
		QString("Title"),
		p.twoDPlot.title
	);
	this->tabItems_2D.append(this->tabItems.twoD.title);

	this->tabItems.twoD.xAxis = new TabItem_Text(scrollAreaWidgetContents_2D,
		QString("X-Axis Label"),
		p.twoDPlot.xLabel
	);
	this->tabItems_2D.append(this->tabItems.twoD.xAxis);

	this->tabItems.twoD.yAxis = new TabItem_Text(scrollAreaWidgetContents_2D,
		QString("Y-Axis Label"),
		p.twoDPlot.yLabel
	);
	this->tabItems_2D.append(this->tabItems.twoD.yAxis);

	this->tabItems.twoD.lineStyle = new TabItem_Combo(scrollAreaWidgetContents_2D,
		QString("Line Style"),
		AppPlot::lsOptions.keys(),
		AppPlot::lsOptions.indexOfValue(p.twoDPlot.lineStyle)
	);
	this->tabItems_2D.append(this->tabItems.twoD.lineStyle);

	this->tabItems.twoD.scatterStyle = new TabItem_Combo(scrollAreaWidgetContents_2D,
		QString("Scatter Style"),
		AppPlot::ssOptions.keys(),
		AppPlot::ssOptions.indexOfValue(p.twoDPlot.scatterStyle)
	);
	this->tabItems_2D.append(this->tabItems.twoD.scatterStyle);

	this->tabItems.twoD.scatterSize = new TabItem_Combo(scrollAreaWidgetContents_2D,
		QString("Scatter Size"),
		AppPlot::sszOptions.keys(),
		AppPlot::sszOptions.indexOfValue(p.twoDPlot.scatterSize)
	);
	this->tabItems_2D.append(this->tabItems.twoD.scatterSize);

	this->tabItems.twoD.color = new TabItem_Combo(scrollAreaWidgetContents_2D,
		QString("Color"),
		AppPlot::colorOptions.keys().mid(1, -1),
		AppPlot::colorOptions.indexOfValue(p.twoDPlot.color) - 1
	);
	this->tabItems_2D.append(this->tabItems.twoD.color);

	for (QVector<PlotEditorTabItem *>::iterator itr = this->tabItems_2D.begin(); itr != this->tabItems_2D.end(); ++itr)
		this->vlo_scrollAreaWidgetContents_2D->addWidget((*itr)->frame);
	this->vlo_scrollAreaWidgetContents_2D->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

	this->scrollArea_2D->setWidget(this->scrollAreaWidgetContents_2D);
	this->vlo_2D->addWidget(this->scrollArea_2D);
	// 2D TAB END

// COLOR MAP TAB
	this->tab_CM = new QWidget();

	this->vlo_CM = new QVBoxLayout(this->tab_CM);
	this->vlo_CM->setSpacing(6);
	this->vlo_CM->setContentsMargins(0, 0, 0, 0);

	this->scrollArea_CM = new QScrollArea(this->tab_CM);
	this->scrollArea_CM->setFrameShape(QFrame::NoFrame);
	this->scrollArea_CM->setLineWidth(0);
	this->scrollArea_CM->setWidgetResizable(true);

	this->scrollAreaWidgetContents_CM = new QWidget();

	this->vlo_scrollAreaWidgetContents_CM = new QVBoxLayout(this->scrollAreaWidgetContents_CM);
	this->vlo_scrollAreaWidgetContents_CM->setSpacing(6);
	this->vlo_scrollAreaWidgetContents_CM->setContentsMargins(11, 11, 11, 11);

	this->tabItems.colorMap.show = new TabItem_Check(scrollAreaWidgetContents_CM,
		QString("Show"),
		p.colorMap.show
	);
	this->tabItems_CM.append(this->tabItems.colorMap.show);

	this->tabItems.colorMap.title = new TabItem_Text(scrollAreaWidgetContents_CM,
		QString("Title"),
		p.colorMap.title
	);
	this->tabItems_CM.append(this->tabItems.colorMap.title);

	this->tabItems.colorMap.xAxis = new TabItem_Text(scrollAreaWidgetContents_CM,
		QString("X-Axis Label"),
		p.colorMap.xLabel
	);
	this->tabItems_CM.append(this->tabItems.colorMap.xAxis);

	this->tabItems.colorMap.yAxis = new TabItem_Text(scrollAreaWidgetContents_CM,
		QString("Y-Axis Label"),
		p.colorMap.yLabel
	);
	this->tabItems_CM.append(this->tabItems.colorMap.yAxis);

	this->tabItems.colorMap.zAxis = new TabItem_Text(scrollAreaWidgetContents_CM,
		QString("Z-Axis Label"),
		p.colorMap.zLabel
	);
	this->tabItems_CM.append(this->tabItems.colorMap.zAxis);

	this->tabItems.colorMap.xRange = new TabItem_Interval(scrollAreaWidgetContents_CM,
		QString("X Range"),
		PlotEditorTab::qVal_double,
		QString::number(p.colorMap.xRange[0]), QString::number(p.colorMap.xRange[1])
	);
	this->tabItems_CM.append(this->tabItems.colorMap.xRange);

	this->tabItems.colorMap.yRange = new TabItem_Interval(scrollAreaWidgetContents_CM,
		QString("Y Range"),
		PlotEditorTab::qVal_double,
		QString::number(p.colorMap.yRange[0]), QString::number(p.colorMap.yRange[1])
	);
	this->tabItems_CM.append(this->tabItems.colorMap.yRange);

	this->tabItems.colorMap.dataSize = new TabItem_Interval(scrollAreaWidgetContents_CM,
		QString("Data Size (x, y)"),
		PlotEditorTab::qVal_int,
		QString::number(p.colorMap.dataSize[0]), QString::number(p.colorMap.dataSize[1])
	);
	this->tabItems_CM.append(this->tabItems.colorMap.dataSize);

	this->tabItems.colorMap.zRange = new TabItem_IntCheck(scrollAreaWidgetContents_CM,
		QString("Z Range"),
		PlotEditorTab::qVal_double,
		QString::number(p.colorMap.zRange[0]), QString::number(p.colorMap.zRange[1])
	);
	this->tabItems_CM.append(this->tabItems.colorMap.zRange);

	this->tabItems.colorMap.colorMin = new TabItem_Combo(scrollAreaWidgetContents_CM,
		QString("Color Min"),
		AppPlot::colorOptions.keys().mid(1, -1),
		AppPlot::colorOptions.indexOfValue(p.colorMap.colorMin) - 1
	);
	this->tabItems_CM.append(this->tabItems.colorMap.colorMin);

	this->tabItems.colorMap.colorMid = new TabItem_Combo(scrollAreaWidgetContents_CM,
		QString("Color Mid"),
		AppPlot::colorOptions.keys(),
		AppPlot::colorOptions.indexOfValue(p.colorMap.colorMid)
	);
	this->tabItems_CM.append(this->tabItems.colorMap.colorMid);

	this->tabItems.colorMap.colorMax = new TabItem_Combo(scrollAreaWidgetContents_CM,
		QString("Color Max"),
		AppPlot::colorOptions.keys().mid(1, -1),
		AppPlot::colorOptions.indexOfValue(p.colorMap.colorMax) - 1
	);
	this->tabItems_CM.append(this->tabItems.colorMap.colorMax);

	for (QVector<PlotEditorTabItem *>::iterator itr = this->tabItems_CM.begin(); itr != this->tabItems_CM.end(); ++itr)
		this->vlo_scrollAreaWidgetContents_CM->addWidget((*itr)->frame);
	this->vlo_scrollAreaWidgetContents_CM->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

	this->scrollArea_CM->setWidget(this->scrollAreaWidgetContents_CM);
	this->vlo_CM->addWidget(this->scrollArea_CM);
	// CM TAB END

	this->tabWidget->addTab(this->tab_2D, QString("2D Plot"));
	this->tabWidget->addTab(this->tab_CM, QString("Color Map"));
	this->tabLayout->addWidget(this->tabWidget);
}

PlotEditorDialog::PlotEditorTab::~PlotEditorTab()
{
	for (auto itr = this->tabItems_2D.begin(); itr != this->tabItems_2D.end(); ++itr)
		delete (*itr);
	for (auto itr = this->tabItems_CM.begin(); itr != this->tabItems_CM.end(); ++itr)
		delete (*itr);
	delete this->tab;
}

/*
** Resets the tab items to their default values.
*/
void PlotEditorDialog::PlotEditorTab::Reset()
{
	this->queuedForUpdate = false;

	for (auto itr = this->tabItems_2D.begin(); itr != this->tabItems_2D.end(); ++itr)
		(*itr)->Reset();
	for (auto itr = this->tabItems_CM.begin(); itr != this->tabItems_CM.end(); ++itr)
		(*itr)->Reset();
}

/*
** Sets the tab items' default values to their current inputs.
** Note that an update to the default value(s) occurs only if the input(s) differ from the
**   default value(s).
*/
void PlotEditorDialog::PlotEditorTab::Set()
{
	this->queuedForUpdate = false;

	for (auto itr = this->tabItems_2D.begin(); itr != this->tabItems_2D.end(); ++itr) {
		if ((*itr)->Set())
			this->queuedForUpdate = true;
	}
	for (auto itr = this->tabItems_CM.begin(); itr != this->tabItems_CM.end(); ++itr) {
		if ((*itr)->Set())
			this->queuedForUpdate = true;
	}
}

PlotProperties PlotEditorDialog::PlotEditorTab::GetPlotProperties() const
{
	PlotProperties p;

	p.twoDPlot.title = this->tabItems.twoD.title->resetVal;
	p.twoDPlot.xLabel = this->tabItems.twoD.xAxis->resetVal;
	p.twoDPlot.yLabel = this->tabItems.twoD.yAxis->resetVal;
	p.twoDPlot.lineStyle = AppPlot::lsOptions.values().at(this->tabItems.twoD.lineStyle->resetVal);
	p.twoDPlot.scatterStyle = AppPlot::ssOptions.values().at(this->tabItems.twoD.scatterStyle->resetVal);
	p.twoDPlot.scatterSize = AppPlot::sszOptions.values().at(this->tabItems.twoD.scatterSize->resetVal);
	p.twoDPlot.color = AppPlot::colorOptions.values().at(this->tabItems.twoD.color->resetVal + 1);

	p.colorMap.title = this->tabItems.colorMap.title->resetVal;
	p.colorMap.xLabel = this->tabItems.colorMap.xAxis->resetVal;
	p.colorMap.yLabel = this->tabItems.colorMap.yAxis->resetVal;
	p.colorMap.zLabel = this->tabItems.colorMap.zAxis->resetVal;
	p.colorMap.xRange[0] = this->tabItems.colorMap.xRange->resetVal_min.toDouble();
	p.colorMap.xRange[1] = this->tabItems.colorMap.xRange->resetVal_max.toDouble();
	p.colorMap.yRange[0] = this->tabItems.colorMap.yRange->resetVal_min.toDouble();
	p.colorMap.yRange[1] = this->tabItems.colorMap.yRange->resetVal_max.toDouble();
	p.colorMap.zRange[0] = this->tabItems.colorMap.zRange->resetVal_min.toDouble();
	p.colorMap.zRange[1] = this->tabItems.colorMap.zRange->resetVal_max.toDouble();
	p.colorMap.dataSize[0] = this->tabItems.colorMap.dataSize->resetVal_min.toInt();
	p.colorMap.dataSize[1] = this->tabItems.colorMap.dataSize->resetVal_max.toInt();
	p.colorMap.colorMin = AppPlot::colorOptions.values().at(this->tabItems.colorMap.colorMin->resetVal + 1);
	p.colorMap.colorMid = AppPlot::colorOptions.values().at(this->tabItems.colorMap.colorMid->resetVal);
	p.colorMap.colorMax = AppPlot::colorOptions.values().at(this->tabItems.colorMap.colorMax->resetVal + 1);
	p.colorMap.manualZRange = this->tabItems.colorMap.zRange->resetVal_isChecked;
	p.colorMap.show = this->tabItems.colorMap.show->resetVal;

	p.queuedForUpdate = this->queuedForUpdate;

	return p;
}