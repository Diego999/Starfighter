#ifndef PROJECTILE_CROSS_H
#define PROJECTILE_CROSS_H

#include "include/game/Projectile.h"

class ProjectileCross : public Projectile
{
    //Q_OBJECT
public:
    ProjectileCross(int _originX, int _originY,Shooter _from,int _nb);

private:
    int nb;

    void advance(int step);
    qreal trajectoryDraw(qreal _x);
};
#endif
