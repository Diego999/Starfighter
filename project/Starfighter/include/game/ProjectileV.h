#ifndef PROJECTILE_V_H
#define PROJECTILE_V_H

#include "include/game/Projectile.h"

#define POWER_V 5
#define SPEED_V_DEF 3

class ProjectileV : public Projectile
{
public:
    ProjectileV(qreal _dXOrigin, qreal _dYOrigin, Shooter _from, qreal _ampli, qreal _omega);
    ~ProjectileV();

private:
    void advance(int _step);
    qreal trajectoryDraw(qreal _dX);

    qreal dAmplitude;
    qreal dOmega;
};
#endif
