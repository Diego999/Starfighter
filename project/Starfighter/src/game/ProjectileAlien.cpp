/*==============================================================*
 | Implementation file ProjectileAlien.cpp
 |        implements : ProjectileAlien class
 |
 |
 | summary : Entity class that represents the exactly behavior of an alien projectile.
 |           For more information, please consult the specification file
 |
 | Creator : Diego Antognini
 | Creation date : 27/11/2012
 | Copyright: EIAJ, all rights reserved
 |
 |
 | Version of the file : 1.0.0
 |
 *==============================================================*/

#include "include/game/ProjectileAlien.h"

#include "include/config/Define.h"

ProjectileAlien::ProjectileAlien(qreal _dXOrigin, qreal _dYOrigin,Shooter _from, qreal _dArgument, qreal _dModule)
    ://Displayable(_dXOrigin,_dYOrigin),
      Projectile(_dXOrigin,_dYOrigin,_from),
      dArgument(_dArgument),//Argument
      dModule(_dModule)//Module
{
    dPower = POWER_ALIEN;
}

void ProjectileAlien::advance(int _step)
{
    Displayable::advance(_step);

    dModule+=ProjectileAlien::kIntervalModule;
    dArgument+=ProjectileAlien::kIntervalArgument;

    setPos(dXOrigin+dModule*cos(dArgument*M_PI/180.0),
           dYOrigin-dModule*sin(dArgument*M_PI/180.0));
}
