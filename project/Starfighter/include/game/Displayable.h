#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "include/enum/Enum.h"

class QPixmap;

class Displayable : public QGraphicsItem
{
public:
    Displayable(qreal _dX, qreal _dY, QPixmap* _pixmap = 0);
    virtual ~Displayable();

    QSize sizePixmap() const {return isPixmap()?pxmPicture->size():QSize();}
    bool isPixmap() const {return !pxmPicture==0;}

    virtual TypeItem getTypeObject() const=0;
    virtual qreal getPower() const {return 0.0;}
    virtual void advance(int _step);
    //virtual void receiveAttack(qreal _dPower) {}

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
