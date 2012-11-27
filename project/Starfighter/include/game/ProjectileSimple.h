#ifndef PROJECTILE_SIMPLE_H
#define PROJECTILE_SIMPLE_H

#include "include/game/Projectile.h"

class ProjectileSimple : public Projectile
{
    Q_OBJECT

public:
    void ProjectileSimple(int _originX, int _originY, Shooter _from);
private:
    qreal trajectoryDraw(qreal x);
};
#endif
