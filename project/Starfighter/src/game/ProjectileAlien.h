#ifndef PROJECTILE_ALIEN_H
#define PROJECTILE_ALIEN_H

#include "Projectile.h"

class ProjectileAlien : public Projectile
{
    Q_OBJECT
public:
    ProjectileAlien(int _x, int _y, qreal _arg, qreal _mod, Shooter _from);

private:
    qreal mod;
    qreal arg;
    static const qreal modInterval = 0.5;
    static const qreal argInterval = 1.0;

    virtual void advance(int step);

};
#endif
