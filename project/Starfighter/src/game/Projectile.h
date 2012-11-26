#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../enum/Enum.h"
#include "../engine/Displayable.h"

class Projectile : public Displayable
{
    Q_OBJECT
public:
    Projectile(int _originX, int _originY,Shooter _from);
    Projectile();
protected:
	int power;
	int originX;
	int originY;

    qreal speed;
    qreal direction;
    QColor color;

	int interval;
    Shooter from;

    virtual void advance(int step);
    virtual qreal trajectoryDraw(qreal x)=0;
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};
#endif
