/*==============================================================*
 | Implementation file ProjectileV.cpp
 |    implements : ProjectileV class
 |
 | Creator : Diego Antognini
 | Creation date : 26/11/2012
 | Copyright: EIAJ, all rights reserved
 |
 | Version of the file : 0.0.1
 |
 *==============================================================*/

#include "include/game/ProjectileV.h"
#include <math.h>
#include <QDebug>

#define INTERVAL_X 3

ProjectileV::ProjectileV(int _originX, int _originY,Shooter _from, qreal _ampli, qreal _omega)
    :Displayable(_originX,_originY),Projectile(_originX,_originY,_from),dAmplitude(_ampli),dOmega(_omega)
{
    dSpeed = INTERVAL_X;
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
        x+=dSpeed;
    else//Player2
        x-=dSpeed;
    setPos(x,originY-trajectoryDraw(originX-x));
}
