#ifndef PROJECTILE_ALIEN_H
#define PROJECTILE_ALIEN_H

#include "include/game/Projectile.h"

class ProjectileAlien : public Projectile
{
    //Q_OBJECT
public:
    ProjectileAlien(int _x, int _y, qreal _arg, qreal _mod, Shooter _from);

private:
    qreal arg;
    qreal mod;
    static const qreal modInterval = 0.5;
    static const qreal argInterval = 1.0;

    void advance(int step);

};
#endif
