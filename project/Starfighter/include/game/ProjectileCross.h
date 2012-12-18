#ifndef PROJECTILE_CROSS_H
#define PROJECTILE_CROSS_H

#include "include/game/Projectile.h"

#define POWER_CROSS 1000
#define SPEED_CROSS_DEF 10

class ProjectileCross : public Projectile
{
public:
    ProjectileCross(qreal _dXOrigin, qreal _dYOrigin,Shooter _from,int _nb);
    ~ProjectileCross() {}

private:
    void advance(int _step);
    qreal trajectoryDraw(qreal _dX);

    int nb;
};
#endif
