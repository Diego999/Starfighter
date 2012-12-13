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

ProjectileSimple::ProjectileSimple(qreal _dXOrigin, qreal _dYOrigin, Shooter _from)
    :Displayable(_dXOrigin,_dYOrigin),
      Projectile(_dXOrigin,_dYOrigin,_from)
{
    dPower = POWER_SIMPLE;
    dSpeed = SPEED_SIMPLE_DEF;
}

ProjectileSimple::~ProjectileSimple()
{

}

qreal ProjectileSimple::trajectoryDraw(qreal _dX)
{
    return 0*_dX;
}

void ProjectileSimple::advance(int _step)
{
    Projectile::advance(_step);

    if(from == Player1)
        setPos(pos().x()+dSpeed,pos().y()+trajectoryDraw(dSpeed));
    else//Player2
        setPos(pos().x()-dSpeed,pos().y()+trajectoryDraw(dSpeed));
}
