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

#define INTERVAL_X 3

ProjectileSimple::ProjectileSimple(qreal _originX, qreal _originY, Shooter _from)
    :Displayable(_originX,_originY),Projectile(_originX,_originY,_from)
{
    power = POWER_S;
    dSpeed = INTERVAL_X;
}

ProjectileSimple::~ProjectileSimple()
{

}

qreal ProjectileSimple::trajectoryDraw(qreal _dX)
{
    return 0;
}

void ProjectileSimple::advance(int _step)
{
    Projectile::advance(_step);

    y+=trajectoryDraw(dSpeed);
    if(from == Player1)
        x+=dSpeed;
    else//Player2
        x-=dSpeed;
    setPos(x,y);
}
