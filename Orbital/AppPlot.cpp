#include "AppPlot.h"

const PlotProperties PlotProperties::defaultPlotProperties = PlotProperties();

const QCustomContainer<QString, QCPGraph::LineStyle> AppPlot::lsOptions = {
	{ "None", QCPGraph::LineStyle::lsNone },
	{ "Line", QCPGraph::LineStyle::lsLine },
	{ "Step Left", QCPGraph::LineStyle::lsStepLeft },
	{ "Step Right", QCPGraph::LineStyle::lsStepRight },
	{ "Step Center", QCPGraph::LineStyle::lsStepCenter },
	{ "Impulse", QCPGraph::LineStyle::lsImpulse }
};

const QCustomContainer<QString, QCPScatterStyle::ScatterShape> AppPlot::ssOptions = {
	{ "None", QCPScatterStyle::ScatterShape::ssNone },
	{ "Dot", QCPScatterStyle::ScatterShape::ssDot },
	{ "Cross", QCPScatterStyle::ScatterShape::ssCross },
	{ "Plus", QCPScatterStyle::ScatterShape::ssPlus },
	{ "Circle", QCPScatterStyle::ScatterShape::ssCircle },
	{ "Disc", QCPScatterStyle::ScatterShape::ssDisc },
	{ "Square", QCPScatterStyle::ScatterShape::ssSquare },
	{ "Diamond", QCPScatterStyle::ScatterShape::ssDiamond },
	{ "Star", QCPScatterStyle::ScatterShape::ssStar },
	{ "Triangle", QCPScatterStyle::ScatterShape::ssTriangle },
	{ "Triangle Inverted", QCPScatterStyle::ScatterShape::ssTriangleInverted },
	{ "Cross Square", QCPScatterStyle::ScatterShape::ssCrossSquare },
	{ "Plus Square", QCPScatterStyle::ScatterShape::ssPlusSquare },
	{ "Cross Circle", QCPScatterStyle::ScatterShape::ssCrossCircle },
	{ "Plus Circle", QCPScatterStyle::ScatterShape::ssPlusCircle },
	{ "Peace", QCPScatterStyle::ScatterShape::ssPeace }
};

const QCustomContainer<QString, double> AppPlot::sszOptions = {
	{ "1", 1.0 },
	{ "2", 2.0 },
	{ "4", 4.0 },
	{ "6", 6.0 },
	{ "8", 8.0 },
	{ "10", 10.0 },
	{ "12", 12.0 }
};

const QCustomContainer<QString, Qt::GlobalColor> AppPlot::colorOptions = {
	{ "None", Qt::GlobalColor::color0 },
	{ "Black", Qt::GlobalColor::black },
	{ "Red", Qt::GlobalColor::red },
	{ "Green", Qt::GlobalColor::green },
	{ "Blue", Qt::GlobalColor::blue },
	{ "Cyan", Qt::GlobalColor::cyan },
	{ "Magenta", Qt::GlobalColor::magenta },
	{ "Yellow", Qt::GlobalColor::yellow },
	{ "Gray", Qt::GlobalColor::gray },
	{ "Dark Red", Qt::GlobalColor::darkRed },
	{ "Dark Green", Qt::GlobalColor::darkGreen },
	{ "Dark Blue", Qt::GlobalColor::darkBlue },
	{ "Dark Cyan", Qt::GlobalColor::darkCyan },
	{ "Dark Magenta", Qt::GlobalColor::darkMagenta },
	{ "Dark Yellow", Qt::GlobalColor::darkYellow },
	{ "Dark Gray", Qt::GlobalColor::darkGray },
	{ "Light Gray", Qt::GlobalColor::lightGray }
};

QPlot_2D::QPlot_2D(
	const QString& title,
	const QString& xLabel, const QString& yLabel,
	int minH, int minW,
	const QCPRange& xRange, const QCPRange& yRange,
	QCPGraph::LineStyle ls,
	const QCPScatterStyle& ss,
	const QPen& pen)
{
	this->plot = new QCustomPlot();
	this->plot->xAxis->setLabel(xLabel);
	this->plot->yAxis->setLabel(yLabel);
	this->plot->setMinimumSize(minW, minH);
	this->plot->xAxis->setRange(xRange);
	this->plot->yAxis->setRange(yRange);
	this->plot->addGraph();
	this->plot->graph(0)->setLineStyle(ls);
	this->plot->graph(0)->setScatterStyle(ss);
	this->plot->graph(0)->setPen(pen);
	this->plot->plotLayout()->insertRow(0);
	this->titleElement = new QCPTextElement(this->plot, title);
	this->plot->plotLayout()->addElement(0, 0, this->titleElement);
	this->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	this->plot->setContextMenuPolicy(Qt::CustomContextMenu);
}

QPlot_2D::~QPlot_2D()
{
	delete this->plot;
}

QPlot_2D::QPlot_2D(const QPlot_2D& src)
{
	this->plot = new QCustomPlot();
	this->plot->xAxis->setLabel(src.plot->xAxis->label());
	this->plot->yAxis->setLabel(src.plot->yAxis->label());
	this->plot->setMinimumSize(src.plot->minimumWidth(), src.plot->minimumHeight());
	this->plot->xAxis->setRange(src.plot->xAxis->range());
	this->plot->yAxis->setRange(src.plot->yAxis->range());
	this->plot->addGraph();
	this->plot->graph(0)->setLineStyle(src.plot->graph(0)->lineStyle());
	this->plot->graph(0)->setScatterStyle(src.plot->graph(0)->scatterStyle());
	this->plot->graph(0)->setPen(src.plot->graph(0)->pen());
	this->plot->plotLayout()->insertRow(0);
	this->titleElement = new QCPTextElement(this->plot, src.titleElement->text());
	this->plot->plotLayout()->addElement(0, 0, this->titleElement);
	this->plot->setInteractions(src.plot->interactions());
	this->plot->setContextMenuPolicy(Qt::CustomContextMenu);
	this->plot->graph(0)->data()->set(*src.plot->graph(0)->data());
}

void QPlot_2D::setRangeX(double l, double u)
{
	this->plot->xAxis->setRange(l, u);
}

const QCPRange QPlot_2D::getRangeX() const
{
	return this->plot->xAxis->range();
}

void QPlot_2D::setRangeY(double l, double u)
{
	this->plot->yAxis->setRange(l, u);
}

const QCPRange QPlot_2D::getRangeY() const
{
	return this->plot->yAxis->range();
}

void QPlot_2D::setLineStyle(QCPGraph::LineStyle ls)
{
	this->plot->graph(0)->setLineStyle(ls);
}

QCPGraph::LineStyle QPlot_2D::getLineStyle()
{
	return this->plot->graph(0)->lineStyle();
}

void QPlot_2D::setScatStyle(const QCPScatterStyle& style)
{
	this->plot->graph(0)->setScatterStyle(style);
}

QCPScatterStyle QPlot_2D::getScatStyle()
{
	return this->plot->graph(0)->scatterStyle();
}

void QPlot_2D::setPen(const QPen& pen)
{
	this->plot->graph(0)->setPen(pen);
}

void QPlot_2D::setTitle(const QString& title)
{
	this->titleElement->setText(title);
}

void QPlot_2D::setInteractions(const bool& interact)
{
	if (interact) {
		this->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	}
	else {
		this->plot->setInteractions(0);
	}
}

void QPlot_2D::addData(double x, double y)
{
	this->plot->graph(0)->addData(x, y);
}

void QPlot_2D::addData(const QVector<qreal>& x, const QVector<qreal>& y, bool sorted)
{
	this->plot->graph(0)->addData(x, y, sorted);
}

void QPlot_2D::clear()
{
	this->plot->graph(0)->data()->clear();
}


QPlot_CM::QPlot_CM(
	const QString& title,
	const QString& xLabel, const QString& yLabel,
	int minH, int minW,
	const QCPRange& xRange, const QCPRange& yRange,
	int sizeX, int sizeY,
	const QString& zLabel, const QCPRange& zRange,
	Qt::GlobalColor colorMin, Qt::GlobalColor colorMid, Qt::GlobalColor colorMax)
{
	this->plot = new QCustomPlot();
	this->plot->setMinimumSize(minW, minH);

	// Configure axis rect
	this->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
	this->plot->axisRect()->setupFullAxesBox(true);
	this->plot->xAxis->setLabel(xLabel);
	this->plot->yAxis->setLabel(yLabel);

	// Color map setup
	this->map = new QCPColorMap(this->plot->xAxis, this->plot->yAxis);
	this->map->data()->setSize(sizeX, sizeY);
	this->map->data()->setRange(xRange, yRange);

	// Add color scale
	colorScale = new QCPColorScale(this->plot);
	this->plot->plotLayout()->addElement(0, 1, colorScale);
	colorScale->setType(QCPAxis::atRight);
	colorScale->axis()->setLabel(zLabel);
	colorScale->setDataRange(zRange);
	colorScale->axis()->axisRect()->setRangeDrag(0);
	colorScale->axis()->axisRect()->setRangeZoom(0);
	this->map->setColorScale(colorScale);

	// Color gradient setup
	QCPColorGradient colorGradient;
	colorGradient.setColorStopAt(0, QColor(colorMin));
	colorGradient.setColorStopAt(1, QColor(colorMax));
	if (colorMid != QCOLOR_NONE)
		colorGradient.setColorStopAt(0.5, QColor(colorMid));
	this->map->setGradient(colorGradient);

	this->map->rescaleDataRange();

	QCPMarginGroup * marginGroup = new QCPMarginGroup(this->plot);
	this->plot->axisRect()->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);
	colorScale->setMarginGroup(QCP::msBottom | QCP::msTop, marginGroup);

	this->plot->rescaleAxes();

	this->titleElement = new QCPTextElement(this->plot, title);
	this->plot->plotLayout()->insertRow(0);
	this->plot->plotLayout()->addElement(0, 0, this->titleElement);
	this->plot->setContextMenuPolicy(Qt::CustomContextMenu);
}

QPlot_CM::~QPlot_CM()
{
	delete this->plot;
}

void QPlot_CM::setColor(const QCPColorGradient& colorGradient)
{
	this->map->colorScale()->setGradient(colorGradient);
}

QCPColorGradient QPlot_CM::getColor()
{
	return this->map->colorScale()->gradient();
}

void QPlot_CM::setDataSize(int xSize, int ySize)
{
	this->map->data()->setSize(xSize, ySize);
}

void QPlot_CM::setRange(const QCPRange& xRange, const QCPRange& yRange)
{
	this->map->data()->setRange(xRange, yRange);
}

void QPlot_CM::setTitle(const QString& title)
{
	this->titleElement->setText(title);
}

void QPlot_CM::setLabelZ(const QString& zLabel)
{
	this->colorScale->axis()->setLabel(zLabel);
}

void QPlot_CM::setRangeZ(const QCPRange& range)
{
	this->map->colorScale()->setDataRange(range);
}

QCPColorMap * const QPlot_CM::getMap()
{
	return this->map;
}

QCPColorMapData * QPlot_CM::getData()
{
	return this->map->data();
}

void QPlot_CM::setCell(int xIndex, int yIndex, double z)
{
	this->map->data()->setCell(xIndex, yIndex, z);
}

void QPlot_CM::clear()
{
	this->map->data()->fill(this->map->colorScale()->dataRange().lower);
}


AppPlot::AppPlot(const PlotProperties& p) :
	autoRescaleDataCM(!p.colorMap.manualZRange),
	autoRescaleAxesCM(true),
	autoRescaleAxes2D(true),
	queuedForRedraw(false)
{
	this->plot2D = new QPlot_2D(
		p.twoDPlot.title,
		p.twoDPlot.xLabel, p.twoDPlot.yLabel,
		p.minH, p.minW,
		QCPRange(p.colorMap.xRange[0], p.colorMap.xRange[1]),
		QCPRange(p.colorMap.yRange[0], p.colorMap.yRange[1]),
		p.twoDPlot.lineStyle,
		QCPScatterStyle(p.twoDPlot.scatterStyle, p.twoDPlot.scatterSize),
		QPen(p.twoDPlot.color)
	);
	this->plotCM = new QPlot_CM(
		p.colorMap.title,
		p.colorMap.xLabel, p.colorMap.yLabel,
		p.minH, p.minW,
		QCPRange(p.colorMap.xRange[0], p.colorMap.xRange[1]),
		QCPRange(p.colorMap.yRange[0], p.colorMap.yRange[1]),
		p.colorMap.dataSize[0], p.colorMap.dataSize[1],
		p.colorMap.zLabel,
		QCPRange(p.colorMap.zRange[0], p.colorMap.zRange[1]),
		p.colorMap.colorMin, p.colorMap.colorMid, p.colorMap.colorMax
	);

	this->vloWidget = new QWidget();
	this->vlo = new QVBoxLayout(this->vloWidget);
	this->vlo->setContentsMargins(0, 0, 0, 0);
	this->vlo->addWidget(this->plot2D->getPlot());
	this->currentPlot = PlotType::TWODIMSN;

	QObject::connect(this->plot2D->getPlot(), &QCustomPlot::mouseDoubleClick, this, &AppPlot::on_doubleClick2D);
	QObject::connect(this->plotCM->getPlot(), &QCustomPlot::mouseDoubleClick, this, &AppPlot::on_doubleClickCM);
	QObject::connect(this->plot2D->getPlot(), &QCustomPlot::customContextMenuRequested, this, &AppPlot::on_rightClick2D);
	QObject::connect(this->plotCM->getPlot(), &QCustomPlot::customContextMenuRequested, this, &AppPlot::on_rightClickCM);
}

AppPlot::~AppPlot()
{
	delete this->plot2D;
	delete this->plotCM;
	delete this->vloWidget;
}

QPlot * AppPlot::plot(PlotType pt)
{
	switch (pt)
	{
	case PlotType::TWODIMSN:
		return this->plot2D;
	case PlotType::COLORMAP:
		return this->plotCM;
	default:
		return nullptr;
	}
}

void AppPlot::setMinSize(int minH, int minW)
{
	this->plot2D->setMinSize(minH, minW);
	this->plotCM->setMinSize(minH, minW);
}

void AppPlot::swap()
{
	switch (this->currentPlot)
	{
	case PlotType::TWODIMSN:
	{
		this->vlo->replaceWidget(this->plot2D->getPlot(), this->plotCM->getPlot());
		QPlot_2D *newPlot = new QPlot_2D(*this->plot2D);
		delete this->plot2D;
		this->plot2D = newPlot;
		QObject::connect(newPlot->getPlot(), &QCustomPlot::mouseDoubleClick, this, &AppPlot::on_doubleClick2D);
		QObject::connect(newPlot->getPlot(), &QCustomPlot::customContextMenuRequested, this, &AppPlot::on_rightClick2D);
		this->currentPlot = PlotType::COLORMAP;
		break;
	}
	case PlotType::COLORMAP:
	{
		this->vlo->replaceWidget(this->plotCM->getPlot(), this->plot2D->getPlot());
		this->currentPlot = PlotType::TWODIMSN;
		break;
	}
	default:
		break;
	}
}

void AppPlot::redraw()
{
	if (this->queuedForRedraw) {
		switch (this->currentPlot)
		{
		case PlotType::TWODIMSN:
			if (this->autoRescaleAxes2D) {
				this->plot2D->getPlot()->rescaleAxes();
			}
			this->plot2D->getPlot()->replot();
			break;
		case PlotType::COLORMAP:
			if (this->autoRescaleAxesCM) {
				this->plotCM->getMap()->rescaleDataRange();
			}
			if (this->autoRescaleAxesCM) {
				this->plotCM->getPlot()->rescaleAxes();
			}
			this->plotCM->getPlot()->replot();
			break;
		default:
			break;
		}
		this->queuedForRedraw = false;
	}
}

void AppPlot::updateProperties(const PlotProperties& p)
{
	// 2-D Plot Settings
	this->plot2D->setTitle(p.twoDPlot.title);
	this->plot2D->setLabelX(p.twoDPlot.xLabel);
	this->plot2D->setLabelY(p.twoDPlot.yLabel);
	this->plot2D->setLineStyle(p.twoDPlot.lineStyle);
	this->plot2D->setScatStyle(QCPScatterStyle(p.twoDPlot.scatterStyle, p.twoDPlot.scatterSize));
	this->plot2D->setPen(QPen(p.twoDPlot.color));

	// Color Map Settings
	this->plotCM->setTitle(p.colorMap.title);
	this->plotCM->setLabelX(p.colorMap.xLabel);
	this->plotCM->setLabelY(p.colorMap.yLabel);
	this->plotCM->setLabelZ(p.colorMap.zLabel);
	this->plotCM->setDataSize(p.colorMap.dataSize[0], p.colorMap.dataSize[1]);
	this->plotCM->setRange(
		QCPRange(p.colorMap.xRange[0], p.colorMap.xRange[1]),
		QCPRange(p.colorMap.yRange[0], p.colorMap.yRange[1])
	);
	this->autoRescaleDataCM = p.colorMap.manualZRange;
	if (p.colorMap.manualZRange)
		this->plotCM->setRangeZ(QCPRange(p.colorMap.zRange[0], p.colorMap.zRange[1]));
	QCPColorGradient colorGradient;
	colorGradient.setColorStopAt(0, p.colorMap.colorMin);
	colorGradient.setColorStopAt(1, p.colorMap.colorMax);
	if (p.colorMap.colorMid != QCOLOR_NONE)
		colorGradient.setColorStopAt(0.5, p.colorMap.colorMid);
	this->plotCM->setColor(colorGradient);

	// Global Settings
	this->plot2D->setMinSize(p.minH, p.minW);
	this->plotCM->setMinSize(p.minH, p.minW);

	if ((p.colorMap.show && this->currentPlot == PlotType::TWODIMSN) ||
		(!p.colorMap.show && this->currentPlot == PlotType::COLORMAP))
		swap();

	this->queuedForRedraw = true;
}

void AppPlot::setPlot2D_title(const QString& s)
{
	this->plot2D->setTitle(s);
	this->queuedForRedraw = true;
}

void AppPlot::setPlot2D_xLabel(const QString& s)
{
	this->plot2D->setLabelX(s);
	this->queuedForRedraw = true;
}

void AppPlot::setPlot2D_yLabel(const QString& s)
{
	this->plot2D->setLabelY(s);
	this->queuedForRedraw = true;
}

void AppPlot::setPlot2D_lineStyle(QCPGraph::LineStyle ls)
{
	this->plot2D->setLineStyle(ls);
	this->queuedForRedraw = true;
}

void AppPlot::setPlot2D_scatterStyle(QCPScatterStyle::ScatterShape shape)
{
	QCPScatterStyle ss = this->plot2D->getScatStyle();
	ss.setShape(shape);
	this->plot2D->setScatStyle(ss);
	this->queuedForRedraw = true;
}

void AppPlot::setPlot2D_scatterSize(double size)
{
	QCPScatterStyle ss = this->plot2D->getScatStyle();
	ss.setSize(size);
	this->plot2D->setScatStyle(ss);
	this->queuedForRedraw = true;
}

void AppPlot::setPlot2D_color(Qt::GlobalColor c)
{
	this->plot2D->setPen(QPen(c));
	this->queuedForRedraw = true;
}

void AppPlot::setPlotCM_title(const QString& s)
{
	this->plotCM->setTitle(s);
	this->queuedForRedraw = true;
}

void AppPlot::setPlotCM_xLabel(const QString& s)
{
	this->plotCM->setLabelX(s);
	this->queuedForRedraw = true;
}

void AppPlot::setPlotCM_yLabel(const QString& s)
{
	this->plotCM->setLabelY(s);
	this->queuedForRedraw = true;
}

void AppPlot::setPlotCM_zLabel(const QString& s)
{
	this->plotCM->setLabelZ(s);
	this->queuedForRedraw = true;
}

void AppPlot::setPlotCM_colorMin(Qt::GlobalColor c)
{
	QCPColorGradient colorGradient = this->plotCM->getColor();
	colorGradient.setColorStopAt(0, c);
	this->plotCM->setColor(colorGradient);
	this->queuedForRedraw = true;
}

void AppPlot::setPlotCM_colorMid(Qt::GlobalColor c)
{
	QCPColorGradient colorGradient = this->plotCM->getColor();
	colorGradient.setColorStopAt(0.5, c);
	this->plotCM->setColor(colorGradient);
	this->queuedForRedraw = true;
}

void AppPlot::setPlotCM_colorMax(Qt::GlobalColor c)
{
	QCPColorGradient colorGradient = this->plotCM->getColor();
	colorGradient.setColorStopAt(1, c);
	this->plotCM->setColor(colorGradient);
	this->queuedForRedraw = true;
}

void AppPlot::setPlotCM_range(double xMin, double xMax, double yMin, double yMax)
{
	this->plotCM->setRange(
		QCPRange(xMin, xMax),
		QCPRange(yMin, yMax)
	);
	this->queuedForRedraw = true;
}

void AppPlot::setPlotCM_size(int xSize, int ySize)
{
	this->plotCM->setDataSize(xSize, ySize);
	this->queuedForRedraw = true;
}

void AppPlot::addData(double x, double y)
{
	this->plot2D->addData(x, y);
	this->queuedForRedraw = true;
}

void AppPlot::addData(const QVector<qreal>& x, const QVector<qreal>& y, bool sorted)
{
	this->plot2D->addData(x, y, sorted);
	this->queuedForRedraw = true;
}

void AppPlot::setCell(int xIndex, int yIndex, double z)
{
	this->plotCM->setCell(xIndex, yIndex, z);
	this->queuedForRedraw = true;
}

void AppPlot::clear()
{
	this->plot2D->clear();
	this->plotCM->clear();
	this->queuedForRedraw = true;
}

void AppPlot::clear2D()
{
	this->plot2D->clear();
	this->queuedForRedraw = true;
}

void AppPlot::clearCM()
{
	this->plotCM->clear();
	this->queuedForRedraw = true;
}

void AppPlot::on_doubleClick2D()
{
	this->plot2D->getPlot()->rescaleAxes();
	this->plot2D->getPlot()->replot();
}

void AppPlot::on_doubleClickCM()
{
	this->plotCM->getPlot()->rescaleAxes();
	this->plotCM->getPlot()->replot();
}

void AppPlot::on_rightClick2D(QPoint pos)
{
	QMenu *menu = new QMenu();
	menu->setAttribute(Qt::WA_DeleteOnClose);
	menu->addAction("Toggle Auto-Rescale", this, &AppPlot::toggleAutoRescale2D);
	menu->addAction("Save As PNG", this, &AppPlot::savePlotImage);
	menu->popup(this->plot2D->getPlot()->mapToGlobal(pos));
}

void AppPlot::on_rightClickCM(QPoint pos)
{
	QMenu *menu = new QMenu();
	menu->setAttribute(Qt::WA_DeleteOnClose);
	menu->addAction("Toggle Auto-Rescale", this, &AppPlot::toggleAutoRescaleCM);
	menu->addAction("Save As PNG", this, &AppPlot::saveColorMapImage);
	menu->popup(this->plotCM->getPlot()->mapToGlobal(pos));
}

void AppPlot::toggleAutoRescale2D()
{
	this->autoRescaleAxes2D = !this->autoRescaleAxes2D;
}

void AppPlot::toggleAutoRescaleCM()
{
	this->autoRescaleAxesCM = !this->autoRescaleAxesCM;
}

void AppPlot::savePlotImage()
{
	QString filename = QFileDialog::getSaveFileName((QWidget*)nullptr, tr("Save Image"), NULL, tr("PNG (*.png)"));
	this->plot2D->getPlot()->savePng(filename, this->vloWidget->size().width(), this->vloWidget->size().height());
}

void AppPlot::saveColorMapImage()
{
	QString filename = QFileDialog::getSaveFileName((QWidget*)nullptr, tr("Save Image"), NULL, tr("PNG (*.png)"));
	this->plotCM->getPlot()->savePng(filename, this->vloWidget->size().width(), this->vloWidget->size().height());
}