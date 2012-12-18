#include "include/game/ProjectileV.h"

#include "include/config/Define.h"

ProjectileV::ProjectileV(qreal _dXOrigin, qreal _dYOrigin,Shooter _from, qreal _ampli, qreal _omega)
    :Displayable(_dXOrigin,_dYOrigin),
      Projectile(_dXOrigin,_dYOrigin,_from),
      dAmplitude(_ampli),dOmega(_omega)
{
    dPower = POWER_V;
    dSpeed = SPEED_V_DEF;
}

qreal ProjectileV::trajectoryDraw(qreal _dX)
{
    qreal l_dX = _dX*M_PI/180.0;
    return dAmplitude*sin(dOmega*l_dX);
}

void ProjectileV::advance(int _step)
{
    Projectile::advance(_step);

    if(from == Player1)
        setPos(pos().x()+dSpeed,dYOrigin-trajectoryDraw(dXOrigin-pos().x()));
    else//Player2
        setPos(pos().x()-dSpeed,dYOrigin-trajectoryDraw(dXOrigin-pos().x()));

}
