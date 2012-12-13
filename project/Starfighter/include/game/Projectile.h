#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "include/enum/Enum.h"
#include "include/game/Displayable.h"

class QColor;

class Projectile : public virtual Displayable
{
public:
    Projectile(qreal _XOrigin, qreal _YOrigin,Shooter _from);
    virtual ~Projectile();

    qreal getPower() const {return dPower;}
    Shooter getTypeObject() const {return from;}

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem *_option, QWidget *_widget=0);

    virtual void advance(int _step);

protected:
    virtual qreal trajectoryDraw(qreal _dX)=0;

    qreal dPower;
    qreal dXOrigin;
    qreal dYOrigin;

    qreal dSpeed;
    QColor* color;

    Shooter from;
};
#endif
