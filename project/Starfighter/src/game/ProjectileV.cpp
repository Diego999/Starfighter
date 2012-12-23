/*==============================================================*
 | Implementation file ProjectileV.cpp
 |        implements : ProjectileV class
 |
 |
 | summary : Entity class that represents the exactly behavior of a V projectile.
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

#include "include/game/ProjectileV.h"

#include "include/config/Define.h"

ProjectileV::ProjectileV(qreal _dXOrigin, qreal _dYOrigin,Shooter _from, qreal _ampli, qreal _omega)
    ://Displayable(_dXOrigin,_dYOrigin),
      Projectile(_dXOrigin,_dYOrigin,_from),
      dAmplitude(_ampli),//Amplitude
      dOmega(_omega)//Omega
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
    Displayable::advance(_step);

    if(from == Player1)
        setPos(pos().x()+dSpeed,dYOrigin-trajectoryDraw(dXOrigin-pos().x()));
    else//Player2
        setPos(pos().x()-dSpeed,dYOrigin-trajectoryDraw(dXOrigin-pos().x()));

}
