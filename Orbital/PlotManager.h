#pragma once

#include <QObject>
#include <QGridLayout>
#include <QVector>
#include <QTimer>
#include <QString>
#include <QHash>
#include <vector>
#include "AppPlot.h"
#include "GridPoint.h"

class PlotManager : public QObject
{
	Q_OBJECT

public:
	enum class PLOT_ERR_CODE {
		NONE,
		UNDEFINED_ERROR,
		INDEX_OUT_OF_RANGE,
		NO_SUCH_VALUE,
		NO_SUCH_PROPERTY
	};

	PlotManager(QGridLayout *plotLayout, QObject *parent = Q_NULLPTR);
	~PlotManager();

	void SetPlotArrangement(const QVector<GridPoint>& plotArrangement, int minW, int minH);
	void SetPlotProperties(size_t pIdx, const PlotProperties& p);
	PLOT_ERR_CODE EditPlotProperty(size_t pIdx, PlotType pt, const QString& prop, const QString& val);
	PLOT_ERR_CODE SetupColormap(size_t pIdx, double xMin, double xMax, double yMin, double yMax, int xSize, int ySize);
	PLOT_ERR_CODE ShowColormap(size_t pIdx, bool show);
	void Clear();
	void AddData2D(size_t pIdx, double x, double y);
	void AddData2D(size_t pIdx, QVector<qreal> * x, QVector<qreal> * y);
	void Clear2D(size_t pIdx);
	void AddDataCM(size_t pIdx, int x, int y, double z);

public Q_SLOTS:
	void Slot_Redraw();

private:
	PLOT_ERR_CODE EditPlotProperty_2D_Title(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_2D_LabelX(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_2D_LabelY(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_2D_LineStyle(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_2D_ScatterStyle(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_2D_ScatterSize(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_2D_Color(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_CM_Title(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_CM_LabelX(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_CM_LabelY(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_CM_LabelZ(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_CM_ColorMin(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_CM_ColorMid(size_t pIdx, const QString& s);
	PLOT_ERR_CODE EditPlotProperty_CM_ColorMax(size_t pIdx, const QString& s);

	QTimer redrawTimer;
	QGridLayout *plotLayout;
	std::vector<AppPlot *> plotVector;

	QHash<QString, PlotManager::PLOT_ERR_CODE(PlotManager::*)(size_t, const QString&)> editablePlotProperties_2D;
	QHash<QString, PlotManager::PLOT_ERR_CODE(PlotManager::*)(size_t, const QString&)> editablePlotProperties_CM;
};