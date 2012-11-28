#ifndef PROJECTILE_SIMPLE_H
#define PROJECTILE_SIMPLE_H

#include "include/game/Projectile.h"

class ProjectileSimple : public Projectile
{
    //Q_OBJECT

public:
    ProjectileSimple(int _originX, int _originY, Shooter _from);
private:
    void advance(int step);
    qreal trajectoryDraw(qreal x);
};
#endif
