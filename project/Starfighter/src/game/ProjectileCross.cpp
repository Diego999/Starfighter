/*==============================================================*
 | Implementation file ProjectileCross.cpp
 |        implements : ProjectileCross class
 |
 |
 | summary : Entity class that represents the exactly behavior of a cross projectile.
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

#include "include/game/ProjectileCross.h"

#include "include/config/Define.h"

ProjectileCross::ProjectileCross(qreal _dXOrigin, qreal _dYOrigin, Shooter _from,int _nb)
    ://Displayable(_dXOrigin,_dYOrigin),
      Projectile(_dXOrigin,_dYOrigin,_from),
      currentNb(_nb)//Number of the current projectile
{
    dSpeed = SPEED_CROSS_DEF;
    dPower = POWER_CROSS;
}

qreal ProjectileCross::trajectoryDraw(qreal _dX)
{
    if(currentNb == 0)
        return 0;
    else if(currentNb == -1)
        return -_dX/10;
    else
        return _dX/10;
}

void ProjectileCross::advance(int _step)
{
    Displayable::advance(_step);

    if(from == Player1)
        setPos(pos().x()+dSpeed,
               dYOrigin-trajectoryDraw(dXOrigin-pos().x()));
    else//Player2
        setPos(pos().x()-dSpeed,
               dYOrigin-trajectoryDraw(dXOrigin-pos().x()));

}
