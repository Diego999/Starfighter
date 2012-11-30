/*==============================================================*
 | Implementation file ProjectileSimple.cpp
 |    implements : ProjectileSimple class
 |
 | Creator : Diego Antognini
 | Creation date : 26/11/2012
 | Copyright: EIAJ, all rights reserved
 |
 | Version of the file : 0.0.1
 |
 *==============================================================*/

#include "include/game/ProjectileSimple.h"

#define INTERVAL_X 7

ProjectileSimple::ProjectileSimple(int _originX, int _originY, Shooter _from)
    :Projectile(_originX,_originY,_from)
{
    interval = INTERVAL_X;
}

qreal ProjectileSimple::trajectoryDraw(qreal _dX)
{
    return 0;
}

void ProjectileSimple::advance(int _step)
{
    Projectile::advance(_step);

    y+=trajectoryDraw(interval);
    x+=interval;
    setPos(x,y);
}
