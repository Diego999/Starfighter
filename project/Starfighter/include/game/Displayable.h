#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include <QPixmap>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QRectF>
#include <QPainterPath>
#include <QGraphicsItem>

class Displayable : QGraphicsItem
{
    //Q_OBJECT
public:
    Displayable(int x, int y, QPixmap* pixmap = 0);
    void paint(QPainter* painter, QStyleOptionGraphicsItem* option, QWidget* widget);
	
    virtual QRectF boundingRect();
    virtual QPainterPath shape();
    virtual QPixmap pixmap();

protected:
	int x;
	int y;
    QPixmap pixmapACHANGER;
    void setPos(qreal x, qreal y);
	void advance(int step);
};
#endif
