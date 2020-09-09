#pragma once

#include <QDialog>
#include <QVector>
#include "ui_PlotArrangementDialog.h"
#include "GridPoint.h"

class PlotArrangementDialog : public QDialog
{
	Q_OBJECT

public:
	PlotArrangementDialog(QWidget *parent);
	~PlotArrangementDialog();

	void SetPlotArrangement(const QVector<GridPoint>&);

private:
	Ui::PlotArrangementDialog ui;
};
