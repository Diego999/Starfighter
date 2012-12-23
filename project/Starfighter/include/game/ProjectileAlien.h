/*=====================================================================*
 | Declaration file ProjectileAlien.h
 |      declares :  ProjectileAlien class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PROJECTILE_ALIEN_H
#define PROJECTILE_ALIEN_H

#include "include/game/Projectile.h"

class ProjectileAlien : public Projectile
{
public:
    ProjectileAlien(qreal _dXOrigin, qreal _dYOrigin,Shooter _from, qreal _dArgument, qreal _dModule);
    ~ProjectileAlien() {}

private:
    static const qreal kIntervalModule = 2.0;
    static const qreal kIntervalArgument = 0.00;

    void advance(int step);
    qreal trajectoryDraw(qreal _dX) {return 0;}

    qreal dArgument;
    qreal dModule;
};
#endif
