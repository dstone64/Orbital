#pragma once

#include <QMetaType>

class GridPoint
{
public:
	GridPoint();
	GridPoint(int row, int rowspan, int col, int colspan);
	GridPoint(const GridPoint&) = default;
	~GridPoint() = default;

	int row;
	int rowspan;
	int col;
	int colspan;
};

Q_DECLARE_METATYPE(GridPoint);