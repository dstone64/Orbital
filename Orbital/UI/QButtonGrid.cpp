#include "QButtonGrid.h"

QButtonGrid::QButtonGrid(QWidget *parent, int maxRows, int maxCols) :
	QWidget(parent),
	parent(parent),
	widgetLayout(new QGridLayout(this)),
	scrollAreaWidgetContents(new QWidget()),
	scrollArea(new QScrollArea(this)),
	frame_UD(new QFrame(this)),
	frame_LR(new QFrame(this)),
	frame_CS(new QFrame(this)),
	graphButtonSizeMin(QBUTTONGRID_BUTTON_SIZE_MIN),
	maxRows(maxRows), maxCols(maxCols)
{
	QSizePolicy sizePolicy_PF(QSizePolicy::Preferred, QSizePolicy::Fixed);
	sizePolicy_PF.setHorizontalStretch(0);
	sizePolicy_PF.setVerticalStretch(0);
	QSizePolicy sizePolicy_PP(QSizePolicy::Preferred, QSizePolicy::Preferred);
	sizePolicy_PP.setHorizontalStretch(0);
	sizePolicy_PP.setVerticalStretch(0);
	QSizePolicy sizePolicy_FP(QSizePolicy::Fixed, QSizePolicy::Preferred);
	sizePolicy_FP.setHorizontalStretch(0);
	sizePolicy_FP.setVerticalStretch(0);
	QSizePolicy sizePolicy_FF(QSizePolicy::Fixed, QSizePolicy::Fixed);
	sizePolicy_FF.setHorizontalStretch(0);
	sizePolicy_FF.setVerticalStretch(0);

	scrollArea->setWidgetResizable(true);
	scrollArea->setWidget(scrollAreaWidgetContents);

	gridLayout = new QGridLayout(scrollAreaWidgetContents);
	gridLayout->setContentsMargins(1, 1, 1, 1);
	gridLayout->setSpacing(1);

	sizePolicy_PF.setHeightForWidth(frame_UD->sizePolicy().hasHeightForWidth());
	frame_UD->setSizePolicy(sizePolicy_PF);
	frame_UD->setMinimumSize(QSize(0, 56));
	frame_UD->setMaximumSize(QSize(16777215, 56));
	frame_UD->setFrameShape(QFrame::NoFrame);
	frame_UD->setLineWidth(0);
	layout_UD = new QVBoxLayout(frame_UD);
	layout_UD->setSpacing(0);
	layout_UD->setContentsMargins(0, 0, 0, 0);
	pushButton_U = new QPushButton(QChar(0x2191), frame_UD);
	sizePolicy_PP.setHeightForWidth(pushButton_U->sizePolicy().hasHeightForWidth());
	pushButton_U->setSizePolicy(sizePolicy_PP);
	pushButton_D = new QPushButton(QChar(0x2193), frame_UD);
	sizePolicy_PP.setHeightForWidth(pushButton_D->sizePolicy().hasHeightForWidth());
	pushButton_D->setSizePolicy(sizePolicy_PP);
	layout_UD->addWidget(pushButton_U);
	layout_UD->addWidget(pushButton_D);

	sizePolicy_FP.setHeightForWidth(frame_LR->sizePolicy().hasHeightForWidth());
	frame_LR->setSizePolicy(sizePolicy_FP);
	frame_LR->setMinimumSize(QSize(56, 0));
	frame_LR->setMaximumSize(QSize(56, 16777215));
	frame_LR->setFrameShape(QFrame::NoFrame);
	frame_LR->setLineWidth(0);
	layout_LR = new QHBoxLayout(frame_LR);
	layout_LR->setSpacing(0);
	layout_LR->setContentsMargins(0, 0, 0, 0);
	pushButton_L = new QPushButton(QChar(0x2190), frame_LR);
	sizePolicy_PP.setHeightForWidth(pushButton_L->sizePolicy().hasHeightForWidth());
	pushButton_L->setSizePolicy(sizePolicy_PP);
	pushButton_R = new QPushButton(QChar(0x2192), frame_LR);
	sizePolicy_PP.setHeightForWidth(pushButton_R->sizePolicy().hasHeightForWidth());
	pushButton_R->setSizePolicy(sizePolicy_PP);
	layout_LR->addWidget(pushButton_L);
	layout_LR->addWidget(pushButton_R);

	sizePolicy_FF.setHeightForWidth(frame_CS->sizePolicy().hasHeightForWidth());
	frame_CS->setSizePolicy(sizePolicy_FF);
	frame_CS->setMinimumSize(QSize(56, 56));
	frame_CS->setMaximumSize(QSize(56, 56));
	frame_CS->setFrameShape(QFrame::NoFrame);
	frame_CS->setLineWidth(0);
	layout_CS = new QVBoxLayout(frame_CS);
	layout_CS->setSpacing(0);
	layout_CS->setContentsMargins(0, 0, 0, 0);
	pushButton_combine = new QPushButton("Combine", frame_CS);
	sizePolicy_PP.setHeightForWidth(pushButton_combine->sizePolicy().hasHeightForWidth());
	pushButton_combine->setSizePolicy(sizePolicy_PP);
	pushButton_separate = new QPushButton("Separate", frame_CS);
	sizePolicy_PP.setHeightForWidth(pushButton_separate->sizePolicy().hasHeightForWidth());
	pushButton_separate->setSizePolicy(sizePolicy_PP);
	layout_CS->addWidget(pushButton_combine);
	layout_CS->addWidget(pushButton_separate);

	widgetLayout->addWidget(scrollArea, 0, 0, 1, 1);
	widgetLayout->addWidget(frame_UD, 1, 0, 1, 1);
	widgetLayout->addWidget(frame_LR, 0, 1, 1, 1);
	widgetLayout->addWidget(frame_CS, 1, 1, 1, 1);

	QObject::connect(pushButton_L, &QPushButton::clicked, this, &QButtonGrid::on_pushButton_L_clicked);
	QObject::connect(pushButton_R, &QPushButton::clicked, this, &QButtonGrid::on_pushButton_R_clicked);
	QObject::connect(pushButton_U, &QPushButton::clicked, this, &QButtonGrid::on_pushButton_U_clicked);
	QObject::connect(pushButton_D, &QPushButton::clicked, this, &QButtonGrid::on_pushButton_D_clicked);
	QObject::connect(pushButton_combine, &QPushButton::clicked, this, &QButtonGrid::on_pushButton_combine_clicked);
	QObject::connect(pushButton_separate, &QPushButton::clicked, this, &QButtonGrid::on_pushButton_separate_clicked);

	graphButtonGrid = new GraphButtonMatrix(this, maxRows, maxCols);
}

QButtonGrid::QButtonGrid(const QButtonGrid& src) : QButtonGrid(src.parent, src.maxRows, src.maxCols)
{
	delete graphButtonGrid;
	graphButtonGrid = new GraphButtonMatrix(this, src.graphButtonGrid);
}

QButtonGrid::~QButtonGrid()
{
	delete graphButtonGrid;
}

QVector<GridPoint> QButtonGrid::buttonArrangement()
{
	return graphButtonGrid->buttonArrangement();
}

QButtonGrid::QButtonGrid_Err QButtonGrid::setButtonArrangement(const QVector<GridPoint>& arrangement)
{
	return graphButtonGrid->setButtonArrangement(arrangement);
}

template<typename T>
QButtonGrid::Matrix<T>::Matrix(int nRow, int nCol, T val) :
	nRow(nRow),
	nCol(nCol),
	m(new QVector<QVector<T> *>(nRow))
{
	for (int r = 0; r < nRow; ++r)
		(*this->m)[r] = new QVector<T>(nCol, val);
}

template<typename T>
QButtonGrid::Matrix<T>::~Matrix()
{
	for (size_t r = this->nRow; r > 0; --r)
		delete (*this->m)[r - 1];
	delete this->m;
}

template<typename T>
void QButtonGrid::Matrix<T>::resize(int nRow, int nCol)
{
	if (nCol != this->nCol) {
		for (int r = 0; r < this->nRow; ++r)
			this->m->at(r)->resize(nCol);
		this->nCol = nCol;
	}
	if (nRow < this->nRow) {
		for (int r = nRow; r < this->nRow; ++r)
			delete this->m->at(r);
		this->m->resize(nRow);
	}
	else if (nRow > this->nRow) {
		this->m->resize(nRow);
		for (int r = this->nRow; r < nRow; ++r)
			(*this->m)[r] = new QVector<T>(this->nCol);
	}
	this->nRow = nRow;
}

QButtonGrid::GraphButtonRoot::GraphButtonRoot(QButtonGrid *widget, int r, int c, int rs, int cs) :
	GraphButton(this),
	r(r), c(c), rs(rs), cs(cs), id(0),
	pushButton(new QPushButton(widget->scrollAreaWidgetContents)),
	gridLayout(widget->gridLayout),
	graphButtonSizeMin(widget->graphButtonSizeMin)
{
	QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
	sizePolicy.setHorizontalStretch(0);
	sizePolicy.setVerticalStretch(0);
	sizePolicy.setHeightForWidth(this->pushButton->sizePolicy().hasHeightForWidth());
	this->pushButton->setSizePolicy(sizePolicy);
	this->pushButton->setMinimumSize(QSize(graphButtonSizeMin, graphButtonSizeMin));
	this->pushButton->setCheckable(true);
	QObject::connect(this->pushButton, &QPushButton::clicked, [=] { widget->on_pushButton_graphButton_clicked(this->r, this->c); });
	widget->gridLayout->addWidget(this->pushButton, r, c, rs + 1, cs + 1);
}

QButtonGrid::GraphButtonRoot::~GraphButtonRoot()
{
	this->gridLayout->removeWidget(this->pushButton);
	delete this->pushButton;
}

void QButtonGrid::GraphButtonRoot::setId(int id)
{
	this->id = id;
	this->pushButton->setText(QString::number(id));
}

void QButtonGrid::GraphButtonRoot::update()
{
	this->gridLayout->removeWidget(this->pushButton);
	this->gridLayout->addWidget(this->pushButton, this->r, this->c, this->rs + 1, this->cs + 1);
	this->pushButton->setMinimumSize(
		QSize(
			(graphButtonSizeMin + this->cs * (graphButtonSizeMin + this->gridLayout->horizontalSpacing())),
			(graphButtonSizeMin + this->rs * (graphButtonSizeMin + this->gridLayout->verticalSpacing()))
		)
	);
}

QButtonGrid::GraphButtonMatrix::GraphButtonMatrix(QButtonGrid *widget, int maxRows, int maxCols) :
	matrix(1, 1, new GraphButtonRoot(widget, 0, 0)),
	widget(widget),
	maxRows(maxRows > 0 ? maxRows : 1),
	maxCols(maxCols > 0 ? maxCols : 1)
{
	((GraphButtonRoot *)this->matrix(0, 0))->setId(1);
	widget->gridLayout->setColumnStretch(0, 1);
	widget->gridLayout->setRowStretch(0, 1);
}

QButtonGrid::GraphButtonMatrix::GraphButtonMatrix(QButtonGrid *widget, GraphButtonMatrix *copy) :
	GraphButtonMatrix(widget, copy->maxRows, copy->maxCols)
{
	int nRows = copy->matrix.nRows();
	int nCols = copy->matrix.nCols();

	this->matrix.resize(nRows, nCols);
	for (int r = 0; r < nRows; ++r)
		this->widget->gridLayout->setRowStretch(r, 1);
	for (int c = 0; c < nCols; ++c)
		this->widget->gridLayout->setColumnStretch(c, 1);
	delete this->matrix(0, 0);

	for (int r = 0; r < nRows; ++r) {
		for (int c = 0; c < nCols; ++c) {
			if (copy->matrix(r, c)->isRoot()) {
				this->matrix.setCell(r, c, new GraphButtonRoot(this->widget, r, c, copy->matrix(r, c)->getRoot()->rs, copy->matrix(r, c)->getRoot()->cs));
			}
			else {
				this->matrix.setCell(r, c, new GraphButtonExt(this->matrix(copy->matrix(r, c)->getRoot()->r, copy->matrix(r, c)->getRoot()->c)->getRoot()));
			}
		}
	}
	reorderIds();
}

QButtonGrid::GraphButtonMatrix::~GraphButtonMatrix()
{
	for (int r = 0; r < this->matrix.nRows(); ++r) {
		for (int c = 0; c < this->matrix.nCols(); ++c) {
			delete this->matrix(r, c);
		}
	}
}

QVector<GridPoint> QButtonGrid::GraphButtonMatrix::buttonArrangement()
{
	QVector<GridPoint> bl;
	for (int r = 0; r < this->matrix.nRows(); ++r) {
		for (int c = 0; c < this->matrix.nCols(); ++c) {
			if (this->matrix(r, c)->isRoot()) {
				GraphButtonRoot *gb = this->matrix(r, c)->getRoot();
				bl.push_back(GridPoint(
					gb->r,
					gb->rs + 1,
					gb->c,
					gb->cs + 1
					));
			}
		}
	}
	return bl;
}

QButtonGrid::QButtonGrid_Err QButtonGrid::GraphButtonMatrix::setButtonArrangement(const QVector<GridPoint>& ba)
{
// Validate the given arrangement
	if (ba.size() > (this->maxCols * this->maxCols) ||
		ba.size() < 1)
		return QButtonGrid_Err::INVALID_SIZE;

	int maxRow = 0;
	int maxCol = 0;
	for (auto i = ba.begin(); i != ba.end(); ++i) {
		if (i->row + i->rowspan > maxRow) maxRow = i->row + i->rowspan;
		if (i->col + i->colspan > maxCol) maxCol = i->col + i->colspan;
	}
	if (ba.first().row != 0 || ba.first().col != 0)
		return QButtonGrid_Err::INVALID_VALUE;
	if (maxRow > this->maxRows || maxCol > this->maxCols)
		return QButtonGrid_Err::INVALID_SIZE;

	Matrix<bool> m(maxRow, maxCol, false);
	for (auto i = ba.begin(); i != ba.end(); ++i) {
		for (int r = 0; r < i->rowspan; ++r) {
			for (int c = 0; c < i->colspan; ++c) {
				if (m(i->row + r, i->col + c))
					return QButtonGrid_Err::INVALID_VALUE;
				m.setCell(i->row + r, i->col + c, true);
			}
		}
	}
	for (int r = 0; r < maxRow; ++r) {
		for (int c = 0; c < maxCol; ++c) {
			if (!m(r, c))
				return QButtonGrid_Err::INVALID_VALUE;
		}
	}
	// End validation

// Reset current arrangement
	for (int r = this->matrix.nRows(); r > 1; --r)
		delRow();
	for (int c = this->matrix.nCols(); c > 1; --c)
		delCol();

// Rebuild arrangement
	for (int r = 0; r < maxRow - 1; ++r)
		addRow();
	for (int c = 0; c < maxCol - 1; ++c)
		addCol();

	for (auto i = ba.begin(); i != ba.end(); ++i) {
		this->matrix(i->row, i->col)->getRoot()->pushButton->setChecked(true);
		this->matrix(i->row + i->rowspan - 1, i->col + i->colspan - 1)->getRoot()->pushButton->setChecked(true);
		select();
		combine();
		deselect();
	}

	return QButtonGrid_Err::VALID;
}

void QButtonGrid::on_pushButton_L_clicked()
{
	if (graphButtonGrid->delCol())
		emit gridChanged();
}

void QButtonGrid::on_pushButton_R_clicked()
{
	if (graphButtonGrid->addCol())
		emit gridChanged();
}

void QButtonGrid::on_pushButton_U_clicked()
{
	if (graphButtonGrid->delRow())
		emit gridChanged();
}

void QButtonGrid::on_pushButton_D_clicked()
{
	if (graphButtonGrid->addRow())
		emit gridChanged();
}

void QButtonGrid::on_pushButton_graphButton_clicked(int r, int c)
{
	graphButtonGrid->toggleHighlights(r, c);
}

void QButtonGrid::on_pushButton_combine_clicked()
{
	graphButtonGrid->combine();
	emit gridChanged();
}

void QButtonGrid::on_pushButton_separate_clicked()
{
	graphButtonGrid->separate();
	emit gridChanged();
}

bool QButtonGrid::GraphButtonMatrix::addRow()
{
	int r = this->matrix.nRows();
	if (r >= this->maxRows)
		return false;

	this->matrix.resize(r + 1, this->matrix.nCols());
	for (int c = 0; c < this->matrix.nCols(); ++c)
		this->matrix.setCell(r, c, new GraphButtonRoot(this->widget, r, c));
	this->reorderIds();
	this->widget->gridLayout->setRowStretch(r, 1);

	return true;
}

bool QButtonGrid::GraphButtonMatrix::delRow()
{
	int r = this->matrix.nRows() - 1;
	if (r <= 0)
		return false;

	for (int c = 0; c < this->matrix.nCols(); ++c) {
		GraphButton *gb = this->matrix(r, c);
		if (!gb->isRoot() && gb->getRoot()->c == c) {
			gb->getRoot()->rs -= 1;
			gb->getRoot()->update();
		}
		delete gb;
	}
	this->matrix.resize(r, this->matrix.nCols());
	this->reorderIds();
	this->widget->gridLayout->setRowStretch(r, 0);

	return true;
}

bool QButtonGrid::GraphButtonMatrix::addCol()
{
	int c = this->matrix.nCols();
	if (c >= this->maxCols)
		return false;

	this->matrix.resize(this->matrix.nRows(), c + 1);
	for (int r = 0; r < this->matrix.nRows(); ++r)
		this->matrix.setCell(r, c, new GraphButtonRoot(this->widget, r, c));
	this->reorderIds();
	this->widget->gridLayout->setColumnStretch(c, 1);

	return true;
}

bool QButtonGrid::GraphButtonMatrix::delCol()
{
	int c = this->matrix.nCols() - 1;
	if (c <= 0)
		return false;

	for (int r = 0; r < this->matrix.nRows(); ++r) {
		GraphButton *gb = this->matrix(r, c);
		if (!gb->isRoot() && gb->getRoot()->r == r) {
			gb->getRoot()->cs -= 1;
			gb->getRoot()->update();
		}
		delete gb;
	}
	this->matrix.resize(this->matrix.nRows(), c);
	this->reorderIds();
	this->widget->gridLayout->setColumnStretch(c, 0);

	return true;
}

void QButtonGrid::GraphButtonMatrix::toggleHighlights(int r, int c)
{
	if (this->matrix(r, c)->getRoot()->pushButton->isChecked())
		this->select();
	else
		this->deselect();
}

void QButtonGrid::GraphButtonMatrix::combine()
{
	int rMin = this->maxRows;
	int rMax = 0;
	int cMin = this->maxCols;
	int cMax = 0;
	GraphButtonRoot *root = NULL;

	for (int r = 0; r < this->matrix.nRows(); ++r) {
		for (int c = 0; c < this->matrix.nCols(); ++c) {
			if (this->matrix(r, c)->getRoot()->pushButton->isChecked()) {
				if (r < rMin) rMin = r;
				if (r > rMax) rMax = r;
				if (c < cMin) cMin = c;
				if (c > cMax) cMax = c;
				if (root == NULL) root = this->matrix(r, c)->getRoot();
			}
		}
	}
	if (root == NULL)
		return;

	for (int r = rMin; r <= rMax; ++r) {
		for (int c = cMin; c <= cMax; ++c) {
			if (r == rMin && c == cMin)
				continue;
			delete this->matrix(r, c);
			this->matrix.setCell(r, c, new GraphButtonExt(root));
		}
	}
	root->rs = rMax - rMin;
	root->cs = cMax - cMin;
	root->update();
	this->reorderIds();
}

void QButtonGrid::GraphButtonMatrix::separate()
{
	for (int r = 0; r < this->matrix.nRows(); ++r) {
		for (int c = 0; c < this->matrix.nCols(); ++c) {
			if (this->matrix(r, c)->isRoot()) {
				GraphButtonRoot *gb = (GraphButtonRoot *)this->matrix(r, c);
				if (gb->pushButton->isChecked())
					this->separateButton(gb);
			}
		}
	}
}

void QButtonGrid::GraphButtonMatrix::reorderIds()
{
	int id = 1;
	for (int r = 0; r < this->matrix.nRows(); ++r) {
		for (int c = 0; c < this->matrix.nCols(); ++c) {
			if (this->matrix(r, c)->isRoot())
				((GraphButtonRoot *)this->matrix(r, c))->setId(id++);
		}
	}
}

void QButtonGrid::GraphButtonMatrix::select()
{
	int rMin = this->maxRows;
	int rMax = 0;
	int cMin = this->maxCols;
	int cMax = 0;
	bool selecting = true;

	while (selecting) {
		for (int r = 0; r < this->matrix.nRows(); ++r) {
			for (int c = 0; c < this->matrix.nCols(); ++c) {
				if (this->matrix(r, c)->getRoot()->pushButton->isChecked()) {
					if (r < rMin) rMin = r;
					if (r > rMax) rMax = r;
					if (c < cMin) cMin = c;
					if (c > cMax) cMax = c;
				}
			}
		}

		selecting = false;
		for (int r = rMin; r <= rMax; ++r) {
			for (int c = cMin; c <= cMax; ++c) {
				if (!this->matrix(r, c)->getRoot()->pushButton->isChecked()) {
					this->matrix(r, c)->getRoot()->pushButton->setChecked(true);
					selecting = true;
				}
			}
		}
	}
}

void QButtonGrid::GraphButtonMatrix::deselect()
{
	for (int r = 0; r < this->matrix.nRows(); ++r) {
		for (int c = 0; c < this->matrix.nCols(); ++c)
			this->matrix(r, c)->getRoot()->pushButton->setChecked(false);
	}
}

void QButtonGrid::GraphButtonMatrix::separateButton(GraphButtonRoot *gb)
{
	for (int r = gb->r; r <= gb->r + gb->rs; ++r) {
		for (int c = gb->c; c <= gb->c + gb->cs; ++c) {
			if (r == gb->r && c == gb->c)
				continue;
			delete this->matrix(r, c);
			this->matrix.setCell(r, c, new GraphButtonRoot(this->widget, r, c));
			this->matrix(r, c)->getRoot()->pushButton->setChecked(true);
		}
	}
	gb->rs = 0;
	gb->cs = 0;
	gb->update();
	this->reorderIds();
}