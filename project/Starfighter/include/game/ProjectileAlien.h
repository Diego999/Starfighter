#ifndef PROJECTILE_ALIEN_H
#define PROJECTILE_ALIEN_H

#include "include/game/Projectile.h"

#define POWER_ALIEN 50

class ProjectileAlien : public Projectile
{
public:
    ProjectileAlien(qreal _dXOrigin, qreal _dYOrigin,Shooter _from, qreal _dArgument, qreal _dModule);
    ~ProjectileAlien();

private:
    void advance(int step);
    qreal trajectoryDraw(qreal _dX);

    static const qreal kIntervalModule = 2.0;
    static const qreal kIntervalArgument = 1.0;

    qreal dArgument;
    qreal dModule;
};
#endif
