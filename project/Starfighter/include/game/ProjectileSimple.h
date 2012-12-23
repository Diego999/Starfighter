/*=====================================================================*
 | Declaration file ProjectileSimple.h
 |      declares :  ProjectileSimple class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PROJECTILE_SIMPLE_H
#define PROJECTILE_SIMPLE_H

#include "include/game/Projectile.h"

class ProjectileSimple : public Projectile
{
public:
    ProjectileSimple(qreal _dXOrigin, qreal _dYOrigin, Shooter _from);
    ~ProjectileSimple() {}

private:
    void advance(int _step);
    qreal trajectoryDraw(qreal _dX) {return 0;}
};
#endif
