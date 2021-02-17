#include "PlotManager.h"
#include "commondefine.h"

PlotManager::PlotManager(QGridLayout *plotLayout, QObject *parent) :
	QObject(parent),
	plotLayout(plotLayout),
	redrawTimer(this),
	editablePlotProperties_2D({
		{ PLOTPROPERTY_TITLE, &PlotManager::EditPlotProperty_2D_Title },
		{ PLOTPROPERTY_LABELX, &PlotManager::EditPlotProperty_2D_LabelX },
		{ PLOTPROPERTY_LABELY, &PlotManager::EditPlotProperty_2D_LabelY },
		{ PLOTPROPERTY_LINESTYLE, &PlotManager::EditPlotProperty_2D_LineStyle },
		{ PLOTPROPERTY_SCATSTYLE, &PlotManager::EditPlotProperty_2D_ScatterStyle },
		{ PLOTPROPERTY_SCATSIZE, &PlotManager::EditPlotProperty_2D_ScatterSize },
		{ PLOTPROPERTY_COLOR, &PlotManager::EditPlotProperty_2D_Color }}),
	editablePlotProperties_CM({
		{ PLOTPROPERTY_TITLE, &PlotManager::EditPlotProperty_CM_Title },
		{ PLOTPROPERTY_LABELX, &PlotManager::EditPlotProperty_CM_LabelX },
		{ PLOTPROPERTY_LABELY, &PlotManager::EditPlotProperty_CM_LabelY },
		{ PLOTPROPERTY_LABELZ, &PlotManager::EditPlotProperty_CM_LabelZ },
		{ PLOTPROPERTY_COLORMIN, &PlotManager::EditPlotProperty_CM_ColorMin },
		{ PLOTPROPERTY_COLORMID, &PlotManager::EditPlotProperty_CM_ColorMid },
		{ PLOTPROPERTY_COLORMAX, &PlotManager::EditPlotProperty_CM_ColorMax }})
{
	QObject::connect(&this->redrawTimer, &QTimer::timeout, this, &PlotManager::Slot_Redraw);

	this->plotVector.push_back(new AppPlot(PlotProperties::defaultPlotProperties));
	this->plotLayout->addWidget(this->plotVector.back()->widget());
	this->redrawTimer.start(16);
}

PlotManager::~PlotManager()
{
	for (auto itr = this->plotVector.begin(); itr != this->plotVector.end(); ++itr)
		delete *itr;
}

/*
** Sets up initialized plots and adds them to the main window UI according to
**   the given plot arrangement.
*/
void PlotManager::SetPlotArrangement(const QVector<GridPoint>& plotArrangement, int minW, int minH)
{
	size_t nPlots = (size_t)plotArrangement.size();
	size_t nPlots_current = this->plotVector.size();

	if (nPlots == 0 || nPlots > MAX_PLOTS)
		return;

	// Remove all plots from UI
	for (size_t i = 0; i < nPlots_current; ++i)
		this->plotLayout->removeWidget(this->plotVector.at(i)->widget());

	// Create/Destroy plots if necessary
	if (nPlots >= nPlots_current) {
		for (size_t i = nPlots_current; i < nPlots; ++i) {
			PlotProperties plotProperties(minW, minH);
			plotProperties.minH *= plotArrangement.at(i).rowspan;
			plotProperties.minW *= plotArrangement.at(i).colspan;
			this->plotVector.push_back(new AppPlot(plotProperties));
		}
	}
	else {
		for (size_t i = nPlots_current; i > nPlots; --i) {
			delete this->plotVector.back();
			this->plotVector.pop_back();
		}
	}

	// Add plots to UI
	for (size_t i = 0; i < nPlots; ++i) {
		this->plotLayout->addWidget(
			this->plotVector.at(i)->widget(),
			plotArrangement.at(i).row,  plotArrangement.at(i).col,
			plotArrangement.at(i).rowspan, plotArrangement.at(i).colspan
		);
	}
}

void PlotManager::SetPlotProperties(size_t pIdx, const PlotProperties& p)
{
	if (pIdx >= this->plotVector.size())
		return;

	this->plotVector.at(pIdx)->updateProperties(p);
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty(size_t pIdx, PlotType pt, const QString& prop, const QString& val)
{
	PLOT_ERR_CODE(PlotManager::*editFn)(size_t, const QString&) = nullptr;
	switch (pt) {
	case PlotType::TWODIMSN:
		editFn = this->editablePlotProperties_2D.value(prop, nullptr); break;
	case PlotType::COLORMAP:
		editFn = this->editablePlotProperties_CM.value(prop, nullptr); break;
	}
	if (editFn == nullptr)
		return PLOT_ERR_CODE::NO_SUCH_PROPERTY;

	return (this->*editFn)(pIdx, val);
}

PlotManager::PLOT_ERR_CODE PlotManager::SetupColormap(size_t pIdx, double xMin, double xMax, double yMin, double yMax, int xSize, int ySize, bool zRange, double zMin, double zMax)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	this->plotVector.at(pIdx)->setPlotCM_range(xMin, xMax, yMin, yMax);
	this->plotVector.at(pIdx)->setPlotCM_size(xSize, ySize);
	if (zRange)
		this->plotVector.at(pIdx)->setPlotCM_rangeZ(zMin, zMax);
	if (this->plotVector.at(pIdx)->showing() != PlotType::COLORMAP)
		this->plotVector.at(pIdx)->swap();
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::ShowColormap(size_t pIdx, bool show)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	switch (this->plotVector.at(pIdx)->showing()) {
	case PlotType::TWODIMSN:
		if (show) this->plotVector.at(pIdx)->swap();
		break;
	case PlotType::COLORMAP:
		if (!show) this->plotVector.at(pIdx)->swap();
		break;
	}
	return PLOT_ERR_CODE::NONE;
}

void PlotManager::Clear()
{
	for (auto p : this->plotVector)
		p->clear();
}

void PlotManager::AddData2D(size_t pIdx, double x, double y)
{
	if (pIdx >= this->plotVector.size())
		return;

	this->plotVector.at(pIdx)->addData(x, y);
}

void PlotManager::AddData2D(size_t pIdx, QVector<qreal> * x, QVector<qreal> * y)
{
	if (pIdx >= this->plotVector.size())
		return;

	this->plotVector.at(pIdx)->addData(*x, *y);
}

void PlotManager::Clear2D(size_t pIdx)
{
	if (pIdx >= this->plotVector.size())
		return;

	this->plotVector.at(pIdx)->clear2D();
}

void PlotManager::AddDataCM(size_t pIdx, int x, int y, double z)
{
	if (pIdx >= this->plotVector.size())
		return;
	
	this->plotVector.at(pIdx)->setCell(x, y, z);
}

void PlotManager::AddDataCM(size_t pIdx, int y, QVector<qreal> * z)
{
	if (pIdx >= this->plotVector.size())
		return;

	this->plotVector.at(pIdx)->setRow(y, *z);
}

void PlotManager::Slot_Redraw()
{
	for (auto itr = this->plotVector.begin(); itr != this->plotVector.end(); ++itr)
		(*itr)->redraw();
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_2D_Title(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	this->plotVector.at(pIdx)->setPlot2D_title(s);
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_2D_LabelX(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	this->plotVector.at(pIdx)->setPlot2D_xLabel(s);
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_2D_LabelY(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	this->plotVector.at(pIdx)->setPlot2D_yLabel(s);
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_2D_LineStyle(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	if (AppPlot::lsOptions.indexOfKey(s) < 0)
		return PLOT_ERR_CODE::NO_SUCH_VALUE;

	this->plotVector.at(pIdx)->setPlot2D_lineStyle(AppPlot::lsOptions.value(s));
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_2D_ScatterStyle(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	if (AppPlot::ssOptions.indexOfKey(s) < 0)
		return PLOT_ERR_CODE::NO_SUCH_VALUE;

	this->plotVector.at(pIdx)->setPlot2D_scatterStyle(AppPlot::ssOptions.value(s));
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_2D_ScatterSize(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	if (AppPlot::sszOptions.indexOfKey(s) < 0)
		return PLOT_ERR_CODE::NO_SUCH_VALUE;

	this->plotVector.at(pIdx)->setPlot2D_scatterSize(AppPlot::sszOptions.value(s));
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_2D_Color(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	if (AppPlot::colorOptions.indexOfKey(s) < 0)
		return PLOT_ERR_CODE::NO_SUCH_VALUE;

	this->plotVector.at(pIdx)->setPlot2D_color(AppPlot::colorOptions.value(s));
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_CM_Title(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	this->plotVector.at(pIdx)->setPlotCM_title(s);
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_CM_LabelX(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	this->plotVector.at(pIdx)->setPlotCM_xLabel(s);
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_CM_LabelY(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	this->plotVector.at(pIdx)->setPlotCM_yLabel(s);
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_CM_LabelZ(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	this->plotVector.at(pIdx)->setPlotCM_zLabel(s);
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_CM_ColorMin(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	if (AppPlot::colorOptions.indexOfKey(s) < 0)
		return PLOT_ERR_CODE::NO_SUCH_VALUE;

	this->plotVector.at(pIdx)->setPlotCM_colorMin(AppPlot::colorOptions.value(s));
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_CM_ColorMid(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	if (AppPlot::colorOptions.indexOfKey(s) < 0)
		return PLOT_ERR_CODE::NO_SUCH_VALUE;

	this->plotVector.at(pIdx)->setPlotCM_colorMid(AppPlot::colorOptions.value(s));
	return PLOT_ERR_CODE::NONE;
}

PlotManager::PLOT_ERR_CODE PlotManager::EditPlotProperty_CM_ColorMax(size_t pIdx, const QString & s)
{
	if (pIdx >= this->plotVector.size())
		return PLOT_ERR_CODE::INDEX_OUT_OF_RANGE;

	if (AppPlot::colorOptions.indexOfKey(s) < 0)
		return PLOT_ERR_CODE::NO_SUCH_VALUE;

	this->plotVector.at(pIdx)->setPlotCM_colorMax(AppPlot::colorOptions.value(s));
	return PLOT_ERR_CODE::NONE;
}
