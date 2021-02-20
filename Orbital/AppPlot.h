#pragma once

#include "qcustomplot.h"
#include "QCustomContainer.h"

#define QCOLOR_NONE Qt::GlobalColor::color0
#define PLOT_DEFAULT_DIMENSION 100
#define PLOT_MAX_DIMENSION 2000

#define PLOTS_MAX_ROWS 8
#define PLOTS_MAX_COLS 8
#define MAX_PLOTS (PLOTS_MAX_ROWS * PLOTS_MAX_COLS)

class PlotProperties
{
public:
	PlotProperties()
	{
		twoDPlot.title = QString("");
		twoDPlot.xLabel = QString("x-axis");
		twoDPlot.yLabel = QString("y-axis");
		twoDPlot.lineStyle = QCPGraph::LineStyle::lsLine;
		twoDPlot.scatterStyle = QCPScatterStyle::ScatterShape::ssCircle;
		twoDPlot.scatterSize = 4.0;
		twoDPlot.color = Qt::GlobalColor::blue;

		colorMap.title = QString("");
		colorMap.xLabel = QString("x-axis");
		colorMap.yLabel = QString("y-axis");
		colorMap.zLabel = QString("z-axis");
		colorMap.xRange[0] = -4;
		colorMap.xRange[1] = 4;
		colorMap.yRange[0] = -4;
		colorMap.yRange[1] = 4;
		colorMap.zRange[0] = 0;
		colorMap.zRange[1] = 1;
		colorMap.dataSize[0] = 200;
		colorMap.dataSize[1] = 200;
		colorMap.colorMin = Qt::GlobalColor::blue;
		colorMap.colorMid = QCOLOR_NONE;
		colorMap.colorMax = Qt::GlobalColor::red;
		colorMap.manualZRange = false;
		colorMap.show = false;

		minW = PLOT_DEFAULT_DIMENSION;
		minH = PLOT_DEFAULT_DIMENSION;
		queuedForUpdate = false;
	}
	PlotProperties(int minW, int minH) : PlotProperties()
	{
		this->minW = minW;
		this->minH = minH;
	}
	~PlotProperties() {}
	PlotProperties(const PlotProperties& src)
	{
		twoDPlot.title = src.twoDPlot.title;
		twoDPlot.xLabel = src.twoDPlot.xLabel;
		twoDPlot.yLabel = src.twoDPlot.yLabel;
		twoDPlot.lineStyle = src.twoDPlot.lineStyle;
		twoDPlot.scatterStyle = src.twoDPlot.scatterStyle;
		twoDPlot.scatterSize = src.twoDPlot.scatterSize;
		twoDPlot.color = src.twoDPlot.color;

		colorMap.title = src.colorMap.title;
		colorMap.xLabel = src.colorMap.xLabel;
		colorMap.yLabel = src.colorMap.yLabel;
		colorMap.zLabel = src.colorMap.zLabel;
		colorMap.xRange[0] = src.colorMap.xRange[0];
		colorMap.xRange[1] = src.colorMap.xRange[1];
		colorMap.yRange[0] = src.colorMap.yRange[0];
		colorMap.yRange[1] = src.colorMap.yRange[1];
		colorMap.zRange[0] = src.colorMap.zRange[0];
		colorMap.zRange[1] = src.colorMap.zRange[1];
		colorMap.dataSize[0] = src.colorMap.dataSize[0];
		colorMap.dataSize[1] = src.colorMap.dataSize[1];
		colorMap.colorMin = src.colorMap.colorMin;
		colorMap.colorMid = src.colorMap.colorMid;
		colorMap.colorMax = src.colorMap.colorMax;
		colorMap.manualZRange = src.colorMap.manualZRange;
		colorMap.show = src.colorMap.show;

		minW = src.minW;
		minH = src.minH;
		queuedForUpdate = src.queuedForUpdate;
	}

	static const PlotProperties defaultPlotProperties;

	struct {
		QString title;
		QString xLabel;
		QString yLabel;
		QCPGraph::LineStyle lineStyle;
		QCPScatterStyle::ScatterShape scatterStyle;
		double scatterSize;
		Qt::GlobalColor color;
	} twoDPlot;

	struct {
		QString title;
		QString xLabel;
		QString yLabel;
		QString zLabel;
		double xRange[2];
		double yRange[2];
		double zRange[2];
		int dataSize[2];
		Qt::GlobalColor colorMin;
		Qt::GlobalColor colorMid;
		Qt::GlobalColor colorMax;
		bool manualZRange;
		bool show;
	} colorMap;

	int minW;
	int minH;
	bool queuedForUpdate;
};

typedef enum {
	TWODIMSN,
	COLORMAP
} PlotType;

class QPlot
{
public:
	virtual ~QPlot() {}
	QCustomPlot* getPlot() const { return this->plot; }
	void setLabelX(const QString& l) { this->plot->xAxis->setLabel(l); }
	void setLabelY(const QString& l) { this->plot->yAxis->setLabel(l); }
	void setMinSize(int minH, int minW) { this->plot->setMinimumSize(minW, minH); }

protected:
	QCustomPlot* plot;
};

class QPlot_2D : public QPlot
{
public:
	QPlot_2D(
		const QString& title,
		const QString& xLabel, const QString& yLabel,
		int minH, int minW,
		const QCPRange& xRange, const QCPRange& yRange,
		QCPGraph::LineStyle ls,
		const QCPScatterStyle& ss,
		const QPen& pen
	);
	~QPlot_2D();
	QPlot_2D(const QPlot_2D& src);

	void setRangeX(double l, double u);
	const QCPRange getRangeX() const;
	void setRangeY(double l, double u);
	const QCPRange getRangeY() const;
	void setLineStyle(QCPGraph::LineStyle ls);
	QCPGraph::LineStyle getLineStyle();
	void setScatStyle(const QCPScatterStyle& style);
	QCPScatterStyle getScatStyle();
	void setPen(const QPen& pen);
	void setTitle(const QString& title);
	void setInteractions(const bool& interact);
	void addData(double x, double y);
	void addData(const QVector<qreal>& x, const QVector<qreal>& y, bool sorted);
	void clear();

private:
	QCPTextElement* titleElement;
};

class QPlot_CM : public QPlot
{
public:
	QPlot_CM(
		const QString& title,
		const QString& xLabel, const QString& yLabel,
		int minH, int minW,
		const QCPRange& xRange, const QCPRange& yRange,
		int sizeX, int sizeY,
		const QString& zLabel, const QCPRange& zRange,
		Qt::GlobalColor colorMin, Qt::GlobalColor colorMid, Qt::GlobalColor colorMax
	);
	~QPlot_CM();

	void setColor(const QCPColorGradient& colorGradient);
	QCPColorGradient getColor();
	void setDataSize(int xSize, int ySize);
	void setRange(const QCPRange& xRange, const QCPRange& yRange);
	void setTitle(const QString& title);
	void setLabelZ(const QString& zLabel);
	void setRangeZ(const QCPRange& range);

	QCPColorMap* const getMap();
	QCPColorMapData* getData();
	void setCell(int xIndex, int yIndex, double z);
	void setRow(int yIndex, const QVector<qreal>& z);
	void clear();

private:
	QCPColorMap* map;
	QCPColorScale* colorScale;
	QCPTextElement* titleElement;
};

class AppPlot : public QObject
{
public:
	static const QCustomContainer<QString, QCPGraph::LineStyle> lsOptions;
	static const QCustomContainer<QString, QCPScatterStyle::ScatterShape> ssOptions;
	static const QCustomContainer<QString, double> sszOptions;
	static const QCustomContainer<QString, Qt::GlobalColor> colorOptions;

	AppPlot(const PlotProperties& ps);
	~AppPlot();

	QPlot* plot(PlotType pt);
	QWidget* widget() const { return this->vloWidget; }
	PlotType showing() const { return this->currentPlot; }
	bool queued() const { return this->queuedForRedraw; }
	void setMinSize(int minH, int minW);
	void swap();
	void redraw();
	void updateProperties(const PlotProperties& p);
	void setAutoRescaleCM(bool autoRescale) { this->autoRescaleDataCM = autoRescale; }
	void setPlot2D_title(const QString& s);
	void setPlot2D_xLabel(const QString& s);
	void setPlot2D_yLabel(const QString& s);
	void setPlot2D_lineStyle(QCPGraph::LineStyle ls);
	void setPlot2D_scatterStyle(QCPScatterStyle::ScatterShape shape);
	void setPlot2D_scatterSize(double size);
	void setPlot2D_color(Qt::GlobalColor c);
	void setPlotCM_title(const QString& s);
	void setPlotCM_xLabel(const QString& s);
	void setPlotCM_yLabel(const QString& s);
	void setPlotCM_zLabel(const QString& s);
	void setPlotCM_colorMin(Qt::GlobalColor c);
	void setPlotCM_colorMid(Qt::GlobalColor c);
	void setPlotCM_colorMax(Qt::GlobalColor c);
	void setPlotCM_range(double xMin, double xMax, double yMin, double yMax);
	void setPlotCM_rangeZ(double zMin, double zMax, bool autoRescaleData = false);
	void setPlotCM_size(int xSize, int ySize);

	void addData(double x, double y);
	void addData(const QVector<qreal>& x, const QVector<qreal>& y, bool sorted = false);
	void setCell(int xIndex, int yIndex, double z);
	void setRow(int yIndex, const QVector<qreal>& z);
	void clear2D();
	void clearCM();
	void clear();

public Q_SLOTS:
	void on_doubleClick2D();
	void on_doubleClickCM();
	void on_rightClick2D(QPoint pos);
	void on_rightClickCM(QPoint pos);
	void toggleAutoRescale2D();
	void toggleAutoRescaleCM();
	void savePlotImage();
	void saveColorMapImage();

private:
	QPlot_2D* plot2D;
	QPlot_CM* plotCM;
	PlotType currentPlot;
	QWidget* vloWidget;
	QVBoxLayout* vlo;
	bool autoRescaleDataCM;
	bool autoRescaleAxesCM;
	bool autoRescaleAxes2D;
	bool queuedForRedraw;
};