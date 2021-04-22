/******************************************************************************

	Copyright (C) 2020 by Dan Stone (danstone124@gmail.com)

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.If not, see < https://www.gnu.org/licenses/>.

******************************************************************************/

#pragma once

#include <QWidget>
#include <QVector>
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QScrollArea>
#include "GridPoint.h"

#define QBUTTONGRID_BUTTON_SIZE_MIN 34
#define QBUTTONGRID_MAX_ROWS 8
#define QBUTTONGRID_MAX_COLS 8

class QButtonGrid : public QWidget
{
	Q_OBJECT

public:
	enum QButtonGrid_Err {
		VALID,
		INVALID_SIZE,
		INVALID_VALUE
	};

	QButtonGrid(QWidget *parent = Q_NULLPTR, int maxRows = QBUTTONGRID_MAX_ROWS, int maxCols = QBUTTONGRID_MAX_COLS);
	QButtonGrid(const QButtonGrid& src);
	~QButtonGrid();

	QVector<GridPoint> buttonArrangement();
	QButtonGrid_Err setButtonArrangement(const QVector<GridPoint>& arrangement);

public Q_SLOTS:
	void on_pushButton_L_clicked();
	void on_pushButton_R_clicked();
	void on_pushButton_U_clicked();
	void on_pushButton_D_clicked();
	void on_pushButton_graphButton_clicked(int r, int c);
	void on_pushButton_combine_clicked();
	void on_pushButton_separate_clicked();

Q_SIGNALS:
	void gridChanged();

private:
	QWidget *parent;
	QGridLayout *widgetLayout;
	QGridLayout *gridLayout;
	QScrollArea *scrollArea;
	QWidget *scrollAreaWidgetContents;
	QFrame *frame_LR;
	QFrame *frame_UD;
	QFrame *frame_CS;
	QHBoxLayout *layout_LR;
	QVBoxLayout *layout_UD;
	QVBoxLayout *layout_CS;
	QPushButton *pushButton_U;
	QPushButton *pushButton_D;
	QPushButton *pushButton_L;
	QPushButton *pushButton_R;
	QPushButton *pushButton_combine;
	QPushButton *pushButton_separate;
	int graphButtonSizeMin;
	int maxRows;
	int maxCols;

	template<typename T>
	class Matrix
	{
	public:
		Matrix(int nRow, int nCol, T val);
		~Matrix();
		T& operator()(int r, int c) { return (*this->m->at(r))[c]; }
		T& itemAt(int r, int c) { return this->operator()(r, c); }
		int nRows() const { return this->nRow; }
		int nCols() const { return this->nCol; }
		void setCell(int r, int c, T val) { (*this->m->at(r))[c] = val; }
		void resize(int nRow, int nCol);
	private:
		int nRow;
		int nCol;
		QVector<QVector<T> *> *m;
	};

	class GraphButtonRoot;
	class GraphButton
	{
	public:
		GraphButton(GraphButtonRoot *root) : root(root) {}
		virtual ~GraphButton() {}
		GraphButtonRoot *getRoot() const { return this->root; }
		virtual bool isRoot() const = 0;

	private:
		GraphButtonRoot *root;
	};

	class GraphButtonRoot : public GraphButton
	{
	public:
		GraphButtonRoot(QButtonGrid *widget, int r, int c, int rs = 0, int cs = 0);
		~GraphButtonRoot();

		void setId(int id);
		void update();
		bool isRoot() const { return true; }

		QPushButton *pushButton;
		QGridLayout *gridLayout;
		int r;
		int c;
		int rs;
		int cs;

	private:
		int id;
		int graphButtonSizeMin;
	};

	class GraphButtonExt : public GraphButton
	{
	public:
		GraphButtonExt(GraphButtonRoot *root) : GraphButton(root) {}
		~GraphButtonExt() {}
		bool isRoot() const { return false; }
	};
	class GraphButtonMatrix
	{
	public:
		GraphButtonMatrix(QButtonGrid *widget, int maxRows, int maxCols);
		GraphButtonMatrix(QButtonGrid *widget, GraphButtonMatrix *copy);
		~GraphButtonMatrix();

		int nRows() const { return this->matrix.nRows(); }
		int nCols() const { return this->matrix.nCols(); }

		QVector<GridPoint> buttonArrangement();
		QButtonGrid_Err setButtonArrangement(const QVector<GridPoint>& ba);
		bool addRow();
		bool delRow();
		bool addCol();
		bool delCol();
		void toggleHighlights(int r, int c);
		void combine();
		void separate();

	private:
		void reorderIds();
		void select();
		void deselect();
		void separateButton(GraphButtonRoot *gb);

		Matrix<GraphButton *> matrix;
		QButtonGrid *widget;
		int maxRows;
		int maxCols;
	};

	GraphButtonMatrix *graphButtonGrid;
};
