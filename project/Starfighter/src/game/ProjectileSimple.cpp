#include "include/game/ProjectileSimple.h"

#include "include/config/Define.h"

ProjectileSimple::ProjectileSimple(qreal _dXOrigin, qreal _dYOrigin, Shooter _from)
    :Displayable(_dXOrigin,_dYOrigin),
      Projectile(_dXOrigin,_dYOrigin,_from)
{
    dPower = POWER_SIMPLE;
    dSpeed = SPEED_SIMPLE_DEF;
}

void ProjectileSimple::advance(int _step)
{
    Projectile::advance(_step);

    if(from == Player1)
        setPos(pos().x()+dSpeed,pos().y()+trajectoryDraw(dSpeed));
    else//Player2
        setPos(pos().x()-dSpeed,pos().y()+trajectoryDraw(dSpeed));
}
