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

#include <math.h>
#include "include/game/ProjectileAlien.h"

ProjectileAlien::ProjectileAlien(int _originX, int _originY, qreal _dArgument, qreal _dModule, Shooter _from)
    :Displayable(_originX,_originY),Projectile(_originX,_originY,_from),dArgument(_dArgument),dModule(_dModule)
{

}

qreal ProjectileAlien::trajectoryDraw(qreal _dX)
{
    return 0;
}

void ProjectileAlien::advance(int _step)
{
    Projectile::advance(_step);
    dModule+=ProjectileAlien::kIntervalModule;
    dArgument+=ProjectileAlien::kIntervalArgument;

    x = originX+dModule*cos(dArgument*M_PI/180.0);
    y = originY-dModule*sin(dArgument*M_PI/180.0);

    setPos(x,y);
}
