#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Displayable.h"


Qt::QRectF Displayable::boundingRect()
{
	return 0;
}

Qt::QPainterPath Displayable::shape()
{
	return 0;
}

Qt::QPixMap Displayable::pixmap()
{
	return 0;
}

void Displayable::paint(Qt::QPainter* painter, Qt::QStyleOptionGraphicsItem* option, Qt::QWidget* widget)
{
}

void Displayable::advance(int step)
{
}

void Displayable::Displayable(int x, int y, Qt::QPixMap* pixmap = 0)
{
}
