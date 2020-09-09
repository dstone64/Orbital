#include "PlotArrangementDialog.h"
#include <QString>

PlotArrangementDialog::PlotArrangementDialog(QWidget *parent)
	: QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint)
{
	ui.setupUi(this);
}

PlotArrangementDialog::~PlotArrangementDialog()
{
}

void PlotArrangementDialog::SetPlotArrangement(const QVector<GridPoint>& plotArrangement)
{
	QString pyListPlotArrangement('[');

	for (auto itr = plotArrangement.begin(); itr != plotArrangement.end(); ++itr) {
		pyListPlotArrangement.append('[');
		pyListPlotArrangement.append(QString::number(itr->row));
		pyListPlotArrangement.append(',');
		pyListPlotArrangement.append(QString::number(itr->rowspan));
		pyListPlotArrangement.append(',');
		pyListPlotArrangement.append(QString::number(itr->col));
		pyListPlotArrangement.append(',');
		pyListPlotArrangement.append(QString::number(itr->colspan));
		pyListPlotArrangement.append("],");
	}
	pyListPlotArrangement.back() = QChar(']');

	this->ui.plainTextEdit->setPlainText(pyListPlotArrangement);
}