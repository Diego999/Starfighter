/*==============================================================*
 | Implementation file ProjectileAlien.cpp
 |    implements : ProjectileAlien class
 |
 | Creator : Diego Antognini
 | Creation date : 26/11/2012
 | Copyright: EIAJ, all rights reserved
 |
 | Version of the file : 0.0.1
 |
 *==============================================================*/

#include "include/game/ProjectileCross.h"
#include <math.h>

#define INTERVAL_X 8

ProjectileCross::ProjectileCross(int _originX, int _originY, Shooter _from,int _nb)
    :Projectile(_originX,_originY,_from),nb(_nb)
{
    interval = INTERVAL_X;
}

qreal ProjectileCross::trajectoryDraw(qreal _dX)
{
    if(nb == 0)
        return 0;
    else if(nb == -1)
        return -_dX/10;
    else
        return _dX/10;
}

void ProjectileCross::advance(int _step)
{
    Projectile::advance(_step);

    if(from == Player1)
        x+=interval;
    else//Player2
        x-=interval;
    setPos(x,y-trajectoryDraw(x));
}
