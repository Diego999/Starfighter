#ifndef PROJECTILE_ALIEN_H
#define PROJECTILE_ALIEN_H

#include "Projectile.h"

class ProjectileAlien : public Projectile
{
    Q_OBJECT
public:
    ProjectileAlien(int _x, int _y, qreal _arg, qreal _mod);

private:
    qreal mod;
    qreal arg;
    static const qreal modInterval;
    static const qreal argInterval;

    virtual void advance(int step);

};
#endif
