#include "include/game/ProjectileV.h"
#include <math.h>

void ProjectileV::ProjectileV(int _x, int _y,Shooter _from, qreal _ampli, qreal _omega)
	:Projectile(_x,_y,_from),ampli(_ampli),mod(_omega)
{
	interval = 4;
}

qreal ProjectileV::trajectoryDraw(qreal x)
{
    qreal _x = x**M_PI/180.0;
    return ampli*sin(omega*_x);
}

void ProjectileV::advance(int step)
{
    Projectile::advance(step);

    x+=interval;
    setPos(x,y-trajectoryDraw(x));
}
