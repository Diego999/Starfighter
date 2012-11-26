#ifndef PROJECTILE_SIMPLE_H
#define PROJECTILE_SIMPLE_H

#include "Projectile.h"

class ProjectileSimple : public Projectile
{
public:
    void ProjectileSimple(int _originX, int _originY, shooter _from);
private:
    Qt::qreal trajectoryDraw(qreal x);
};
#endif
