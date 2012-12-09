/*=====================================================================*
 | Declaration file ProjectileV.h
 |    declares :  ProjectileV class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PROJECTILE_V_H
#define PROJECTILE_V_H

#include "include/game/Projectile.h"

/**
* Class that represents a projectile throwed by a spaceship.
* The simple projectile follows a sinusoidal curve
* @author Diego Antognini
* @version 0.0.1
*/

#define POWER_V 5

class ProjectileV : public Projectile
{
public:
    ProjectileV(qreal _originX, qreal _originY, Shooter _from, qreal _ampli, qreal _omega);
    ~ProjectileV();

private:
    void advance(int _step);
    qreal trajectoryDraw(qreal _dX);

    qreal dAmplitude;
    qreal dOmega;
};
#endif
