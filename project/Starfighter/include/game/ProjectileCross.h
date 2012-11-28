/*=====================================================================*
 | Declaration file ProjectileCross.h
 |    declares :  ProjectileCross class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PROJECTILE_CROSS_H
#define PROJECTILE_CROSS_H

#include "include/game/Projectile.h"

/**
* Class that represents a cross-projectile throwed by a spaceship.
* A cross-projectile is a superposition of simple projectile with different angles
* @author Diego Antognini
* @version 0.0.1
*/

class ProjectileCross : public Projectile
{
public:
    ProjectileCross(int _originX, int _originY,Shooter _from,int _nb);

private:
    void advance(int _step);
    qreal trajectoryDraw(qreal _dX);

    int nb;
};
#endif
