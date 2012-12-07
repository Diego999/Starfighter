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

class Displayable : public QGraphicsItem
{
    //Q_OBJECT
public:
    Displayable(int _x=0, int _y=0, QPixmap* _pixmap = 0);
    virtual ~Displayable();
    virtual QRectF boundingRect() const=0;
    virtual QPainterPath shape() const=0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) = 0;

protected:
	int x;
	int y;
    QPixmap* pxmPicture;

    virtual void setPos(qreal x, qreal y);
    virtual void advance(int step);
};
#endif
