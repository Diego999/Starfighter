#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "include/enum/Enum.h"

#define RADIUS_PROJECTILE 10

class QPixmap;

class Displayable : public QGraphicsItem
{
public:
    Displayable(qreal _dX, qreal _dY, QPixmap* _pixmap = 0);
    virtual ~Displayable();

    QSize sizePixmap() const {return isPixmap()?pxmPicture->size():QSize();}
    bool isPixmap() const {return !pxmPicture==0;}

    virtual Shooter getTypeObject() const {return Other;}
    virtual void advance(int _step);

    virtual QRectF boundingRect() const=0;
    virtual QPainterPath shape() const=0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

    QPixmap* getPixmap() const {return pxmPicture;}
    void setPos(qreal _dX, qreal _dY);
    void setPixmap(QPixmap* _pxmPixmap);
private:
    qreal dX;
    qreal dY;
    QPixmap* pxmPicture;
};
#endif
