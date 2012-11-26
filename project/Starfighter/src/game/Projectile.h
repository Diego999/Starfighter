#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Enum.h"
#include "../engine/Displayable.h"

class Projectile : public Displayable
{
    Q_OBJECT
public:
    Projectile(int _originX, int _originY,shooter _from);

protected:
	int power;
	int originX;
	int originY;

    qreal speed;
    qreal direction;
    QColor color;

	int interval;
	shooter from;

    virtual void advance(int step);
    virtual qreal trajectoryDraw(qreal x)=0;
};
#endif
