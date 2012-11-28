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

class ProjectileV : public Projectile
{
public:
    ProjectileV(int _originX, int _originY, Shooter _from, qreal _ampli, qreal _omega);
	
private:
    void advance(int step);
    qreal trajectoryDraw(qreal xx);

    qreal dAmplitude;
    qreal dOmega;
};
#endif
