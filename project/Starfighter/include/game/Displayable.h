#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include <QPixmap>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QRectF>
#include <QPainterPath>
#include <QGraphicsItem>

#define RADIUS_PROJECTILE 10

class Displayable : QGraphicsItem
{
    //Q_OBJECT
public:
    Displayable(int _x, int _y, QPixmap* _pixmap = 0);

    virtual QRectF boundingRect()=0;
    virtual QPainterPath shape()=0;
    virtual void paint(QPainter* _painter, QStyleOptionGraphicsItem* _option, QWidget* _widget)=0;

protected:
	int x;
	int y;
    QPixmap* pxmPicture;

    virtual void setPos(qreal x, qreal y);
    virtual void advance(int step);
};
#endif
