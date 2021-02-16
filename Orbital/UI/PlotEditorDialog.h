#pragma once

#include <QDialog>
#include <QWidget>
#include <QSizePolicy>
#include <QLayout>
#include <QTabWidget>
#include <QScrollArea>
#include <QFrame>
#include <QComboBox>
#include <QCheckBox>
#include <QVector>
#include <QPixmap>
#include "ui_PlotEditorDialog.h"
#include "PlotArrangementDialog.h"
#include "qcustomplot.h"
#include "QButtonGrid.h"
#include "AppPlot.h"

class PlotEditorDialog : public QDialog
{
	Q_OBJECT

public:
	enum PlotEditError {
		NONE,
		INDEX_OUT_OF_RANGE,
		NO_SUCH_VALUE,
		PLOTARRANGE_INVALID_SIZE,
		PLOTARRANGE_INVALID_VALUE
	};

	PlotEditorDialog(QWidget *parent);
	~PlotEditorDialog();

	PlotEditError SetPlotArrangement(const QVector<GridPoint>& plotArrangement);
	PlotEditError GetPlotProperties(size_t plotIdx, PlotProperties& plotProperties) const;
	void GetPlotMinSize(int& w, int& h) const;

	PlotEditError EditPlot_Title2D(size_t plotIdx, const QString& title);
	PlotEditError EditPlot_XLabel2D(size_t plotIdx, const QString& label);
	PlotEditError EditPlot_YLabel2D(size_t plotIdx, const QString& label);
	PlotEditError EditPlot_LineStyle(size_t plotIdx, const QString& ls);
	PlotEditError EditPlot_ScatterStyle(size_t plotIdx, const QString& ss);
	PlotEditError EditPlot_ScatterSize(size_t plotIdx, const QString& ssz);
	PlotEditError EditPlot_Color(size_t plotIdx, const QString& color);

	PlotEditError EditPlot_ShowCM(size_t plotIdx, bool show);
	PlotEditError EditPlot_SetupCM(size_t plotIdx, double xMin, double xMax, double yMin, double yMax, int xSize, int ySize, bool zRange, double zMin, double zMax);
	PlotEditError EditPlot_TitleCM(size_t plotIdx, const QString& title);
	PlotEditError EditPlot_XLabelCM(size_t plotIdx, const QString& label);
	PlotEditError EditPlot_YLabelCM(size_t plotIdx, const QString& label);
	PlotEditError EditPlot_ZLabel(size_t plotIdx, const QString& label);
	PlotEditError EditPlot_XRange(size_t plotIdx, double xMin, double xMax);
	PlotEditError EditPlot_YRange(size_t plotIdx, double yMin, double yMax);
	PlotEditError EditPlot_ZRange(size_t plotIdx, double zMin, double zMax, bool manual = true);
	PlotEditError EditPlot_DataSize(size_t plotIdx, int xSize, int ySize);
	PlotEditError EditPlot_ColorMin(size_t plotIdx, const QString& color);
	PlotEditError EditPlot_ColorMid(size_t plotIdx, const QString& color);
	PlotEditError EditPlot_ColorMax(size_t plotIdx, const QString& color);

	void showEvent(QShowEvent *e);
	void closeEvent(QCloseEvent *e);
	void keyPressEvent(QKeyEvent *e) { if (e->key() != Qt::Key_Escape) QDialog::keyPressEvent(e); }

public Q_SLOTS:
	void on_pushButton_save_clicked();
	void on_pushButton_cancel_clicked();
	void on_pushButton_apply_clicked();
	void on_pushButton_gridArrangement_clicked();
	void Slot_GridChanged();

Q_SIGNALS:
	void Signal_UpdatePlotArrangement(const QVector<GridPoint>& plotArrangement);
	void Signal_UpdatePlotProperties(const QVector<size_t>& plotUpdateQueue);

private:
	enum PlotEditorTabItem_t {
		TEXT,
		COMBO,
		CHECK,
		INTERVAL,
		INTCHECK
	};

	class PlotEditorTabItem {
	public:
		PlotEditorTabItem(QWidget *parent, PlotEditorTabItem_t type, const QString& label);
		~PlotEditorTabItem() {}
		const QFrame * Frame() const { return this->frame; }
		virtual void Reset() = 0;
		virtual bool Set() = 0;

		PlotEditorTabItem_t type;
		QFrame *frame;
		QLabel *label;
		QHBoxLayout *hlo;

	private:
		static QSizePolicy sizePolicy_PF;
		static QSizePolicy sizePolicy_FP;
	};
	class TabItem_Text : public PlotEditorTabItem {
	public:
		TabItem_Text(QWidget *parent, const QString& label, const QString& resetVal);
		TabItem_Text(QWidget *parent, const TabItem_Text& copy) : TabItem_Text(parent, copy.lineEdit->text(), copy.resetVal) {}
		~TabItem_Text() {}
		void Reset();
		bool Set();

		QLineEdit *lineEdit;
		QString resetVal;
	};
	class TabItem_Combo : public PlotEditorTabItem {
	public:
		TabItem_Combo(QWidget *parent, const QString& label, const QVector<QString>& options, int resetVal);
		~TabItem_Combo() {}
		void Reset();
		bool Set();

		QComboBox *comboBox;
		int resetVal;
	};
	class TabItem_Check : public PlotEditorTabItem {
	public:
		TabItem_Check(QWidget *parent, const QString& label, bool resetVal);
		~TabItem_Check() {}
		void Reset();
		bool Set();

		QCheckBox *checkBox;
		bool resetVal;
	};
	class TabItem_Interval : public PlotEditorTabItem {
	public:
		TabItem_Interval(QWidget *parent, const QString& label, const QValidator* v, const QString& resetVal_min, const QString& resetVal_max);
		~TabItem_Interval() {}
		void Reset();
		bool Set();

		QLineEdit *lineEdit_min;
		QLineEdit *lineEdit_max;
		QString resetVal_min;
		QString resetVal_max;
	};
	class TabItem_IntCheck : public PlotEditorTabItem {
	public:
		TabItem_IntCheck(QWidget *parent, const QString& label, const QValidator* v, const QString& resetVal_min, const QString& resetVal_max, bool resetVal_isChecked = false);
		~TabItem_IntCheck() {}
		void Reset();
		bool Set();

		QCheckBox *checkBox;
		QLineEdit *lineEdit_min;
		QLineEdit *lineEdit_max;
		bool resetVal_isChecked;
		QString resetVal_min;
		QString resetVal_max;
	};
	class PlotEditorTab {
	public:
		PlotEditorTab(const PlotProperties& p);
		~PlotEditorTab();

		void Reset();
		void Set();
		PlotProperties GetPlotProperties() const;

		QWidget *tab;
		QHBoxLayout *tabLayout;
		QTabWidget *tabWidget;

		QWidget *tab_2D;
		QVBoxLayout *vlo_2D;
		QScrollArea *scrollArea_2D;
		QWidget *scrollAreaWidgetContents_2D;
		QVBoxLayout *vlo_scrollAreaWidgetContents_2D;

		QWidget *tab_CM;
		QVBoxLayout *vlo_CM;
		QScrollArea *scrollArea_CM;
		QWidget *scrollAreaWidgetContents_CM;
		QVBoxLayout *vlo_scrollAreaWidgetContents_CM;

		QVector<PlotEditorTabItem *> tabItems_2D;
		QVector<PlotEditorTabItem *> tabItems_CM;

		struct {
			struct {
				TabItem_Text *title;
				TabItem_Text *xAxis;
				TabItem_Text *yAxis;
				TabItem_Combo *lineStyle;
				TabItem_Combo *scatterStyle;
				TabItem_Combo *scatterSize;
				TabItem_Combo *color;
			} twoD;
			struct {
				TabItem_Check *show;
				TabItem_Text *title;
				TabItem_Text *xAxis;
				TabItem_Text *yAxis;
				TabItem_Text *zAxis;
				TabItem_Interval *xRange;
				TabItem_Interval *yRange;
				TabItem_Interval *dataSize;
				TabItem_IntCheck *zRange;
				TabItem_Combo *colorMin;
				TabItem_Combo *colorMid;
				TabItem_Combo *colorMax;
			} colorMap;
		} tabItems;

		bool queuedForUpdate;

	private:
		static const QDoubleValidator * qVal_double;
		static const QIntValidator * qVal_int;
	};

	Ui::PlotEditorDialog ui;
	PlotArrangementDialog plotArrangementDialog;
	QVector<PlotEditorTab *> tabs;
	QVector<PlotProperties> tabsTemp;
	QVector<GridPoint> plotArrangement;
	QButtonGrid *buttonGrid;
	QButtonGrid *buttonGridTemp;
	QPixmap pixmap_check;
	QPixmap pixmap_exclamation;
	int minW;
	int minH;
	bool revertState;
	bool resetPlots;

	int AddTab(const PlotProperties& p);
	int DelTab();
	void Reset();
	void Set();
	void SetTabsQueuedForUpdate(bool queuedForUpdate = true);
};
