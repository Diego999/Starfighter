#ifndef PROJECTILE_CROSS_H
#define PROJECTILE_CROSS_H

#include "Projectile.h"

class ProjectileCross : public Projectile
{
public:
    ProjectileCross(int _originX, int _originY,shooter _from,int _nb);

private:
    int nb;

    void advance(int step);
    qreal trajectoryDraw(qreal _x);
};
#endif