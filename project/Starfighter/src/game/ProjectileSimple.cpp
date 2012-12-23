/*==============================================================*
 | Implementation file ProjectileSimple.cpp
 |        implements : ProjectileSimple class
 |
 |
 | summary : Entity class that represents the exactly behavior of a simple projectile.
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

#include "include/game/ProjectileSimple.h"

#include "include/config/Define.h"

ProjectileSimple::ProjectileSimple(qreal _dXOrigin, qreal _dYOrigin, Shooter _from)
    ://Displayable(_dXOrigin,_dYOrigin),
      Projectile(_dXOrigin,_dYOrigin,_from)
{
    dPower = POWER_SIMPLE;
    dSpeed = SPEED_SIMPLE_DEF;
}

void ProjectileSimple::advance(int _step)
{
    Displayable::advance(_step);

    if(from == Player1)
        setPos(pos().x()+dSpeed,pos().y()+trajectoryDraw(dSpeed));
    else//Player2
        setPos(pos().x()-dSpeed,pos().y()+trajectoryDraw(dSpeed));
}
