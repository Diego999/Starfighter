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

#include "include/game/ProjectileAlien.h"

ProjectileAlien::ProjectileAlien(qreal _dXOrigin, qreal _dYOrigin,Shooter _from, qreal _dArgument, qreal _dModule)
    :Displayable(_dXOrigin,_dYOrigin),
      Projectile(_dXOrigin,_dYOrigin,_from),
      dArgument(_dArgument),dModule(_dModule)
{
    dPower = POWER_ALIEN;
}

ProjectileAlien::~ProjectileAlien()
{

}

qreal ProjectileAlien::trajectoryDraw(qreal _dX)
{
    return 0*_dX;
}

void ProjectileAlien::advance(int _step)
{
    Projectile::advance(_step);
    dModule+=ProjectileAlien::kIntervalModule;
    dArgument+=ProjectileAlien::kIntervalArgument;

    setPos(dXOrigin+dModule*cos(dArgument*M_PI/180.0),
           dYOrigin-dModule*sin(dArgument*M_PI/180.0));
}
