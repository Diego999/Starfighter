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

#define INTERVAL_X 3

ProjectileCross::ProjectileCross(qreal _originX, qreal _originY, Shooter _from,int _nb)
    :Displayable(_originX,_originY),Projectile(_originX,_originY,_from),nb(_nb)
{
    dSpeed = INTERVAL_X;
    power = POWER_C;
}

ProjectileCross::~ProjectileCross()
{

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
        x+=dSpeed;
    else//Player2
        x-=dSpeed;
    setPos(x,originY-trajectoryDraw(originX-x));
}
