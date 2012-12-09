/*=====================================================================*
 | Declaration file ProjectileSimple.h
 |    declares :  ProjectileSimple class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PROJECTILE_SIMPLE_H
#define PROJECTILE_SIMPLE_H

#include "include/game/Projectile.h"

/**
* Class that represents a projectile throwed by a spaceship.
* The simple projectile follows a horizontal line.
* @author Diego Antognini
* @version 0.0.1
*/

#define POWER_S 1

class ProjectileSimple : public Projectile
{
public:
    ProjectileSimple(qreal _originX, qreal _originY, Shooter _from);
    ~ProjectileSimple();

private:
    void advance(int _step);
    qreal trajectoryDraw(qreal _dX);
};
#endif
