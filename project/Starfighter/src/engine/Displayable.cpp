#include "Displayable.h"

Displayable::Displayable(int x, int y, Qt::QPixMap* pixmap = 0)
{

}

QRectF Displayable::boundingRect()
{
	return 0;
}

QPainterPath Displayable::shape()
{
	return 0;
}

QPixMap Displayable::pixmap()
{
	return 0;
}

void Displayable::paint(Qt::QPainter* painter, Qt::QStyleOptionGraphicsItem* option, Qt::QWidget* widget)
{
}

void Displayable::advance(int step)
{
}


