#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "DisplayEngine.h"

class Displayable : public DisplayEngine
{
public:
	Displayable(int x, int y, Qt::QPixMap* pixmap = 0);
	void paint(Qt::QPainter* painter, Qt::QStyleOptionGraphicsItem* option, Qt::QWidget* widget);
	
	QRectF boundingRect();
	QPainterPath shape();
	QPixMap pixmap();

protected:
	int x;
	int y;
	QPixMap pixmap;

	void advance(int step);

private:
	DisplayEngine displayEngine;
	Trajectoire trajectoire;
};
#endif
