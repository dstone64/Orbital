#include "GridPoint.h"

GridPoint::GridPoint() : row(0), rowspan(1), col(0), colspan(1)
{
}

GridPoint::GridPoint(int row, int rowspan, int col, int colspan)
{
	this->row = row < 0 ? 0 : row;
	this->rowspan = rowspan < 1 ? 1 : rowspan;
	this->col = col < 0 ? 0 : col;
	this->colspan = colspan < 1 ? 1 : colspan;
}