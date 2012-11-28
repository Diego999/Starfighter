#include "include/game/Displayable.h"

Displayable::Displayable(int x, int y, QPixmap* pixmap)
{

}
Displayable::Displayable()
{

}

QRectF Displayable::boundingRect()
{
    return QRectF();
}

QPainterPath Displayable::shape()
{
    return QPainterPath();
}

QPixmap Displayable::pixmap()
{
	return 0;
}

void Displayable::paint(QPainter* painter, QStyleOptionGraphicsItem* option, QWidget* widget)
{
}

void Displayable::advance(int step)
{
}

void Displayable::setPos(qreal x, qreal y)
{
    QGraphicsItem::setPos(x,y);
}

