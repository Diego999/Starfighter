#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "ProjectileSimple.h"


void ProjectileSimple::ProjectileSimple(int _originX, int _originY, Shooter _from)
    :Projectile(_originX,_originY,_from)
{
    interval = 7;
}

qreal ProjectileSimple::trajectoryDraw(qreal _x)
{
    return 0;
}

void ProjectileSimple::advance(int step)
{
    Projectile::advance(step);

    y+=trajectoryDraw(interval);
    setPos(x,y);
    x+=interval;
}
