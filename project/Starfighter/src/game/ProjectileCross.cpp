#include "include/game/ProjectileCross.h"

#include "include/config/Define.h"

ProjectileCross::ProjectileCross(qreal _dXOrigin, qreal _dYOrigin, Shooter _from,int _nb)
    :Displayable(_dXOrigin,_dYOrigin),
      Projectile(_dXOrigin,_dYOrigin,_from),
      nb(_nb)
{
    dSpeed = SPEED_CROSS_DEF;
    dPower = POWER_CROSS;
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
        setPos(pos().x()+dSpeed,
               dYOrigin-trajectoryDraw(dXOrigin-pos().x()));
    else//Player2
        setPos(pos().x()-dSpeed,
               dYOrigin-trajectoryDraw(dXOrigin-pos().x()));

}
