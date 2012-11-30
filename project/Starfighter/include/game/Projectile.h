/*=====================================================================*
 | Declaration file Projectile.h
 |    declares :  Projectile class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "include/enum/Enum.h"
#include "include/game/Displayable.h"

/**
* Class that represents a projectile throwed by a spaceship or an alien-spaceship
* @author Diego Antognini
* @version 0.0.1
*/

class Projectile : public Displayable
{
public:
    Projectile(int _originX, int _originY,Shooter _from);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem *, QWidget *);

protected:
    virtual void advance(int _step);
    virtual qreal trajectoryDraw(qreal _dX)=0;

    int power;
	int originX;
	int originY;

    qreal dSpeed;
    QColor color;

	int interval;
    Shooter from;
};
#endif
