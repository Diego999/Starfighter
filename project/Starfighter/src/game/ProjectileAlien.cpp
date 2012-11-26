#include "math.h"
#include "ProjectileAlien.h"

qreal ProjectileAlien::argInterval = 0.5;
qreal ProjectileAlien::modInterval = 1.0;

ProjectileAlien::ProjectileAlien(int _x, int _y, qreal _arg, qreal _mod, shooter _from)
    :Projectile(_x,_y,_from),arg(_arg),mod(_mod)
{

}

void ProjectileAlien::advance(int step)
{
    Projectile::advance(step);
    r+=ProjectileAlien::modInterval;
    a+=ProjectileAlien::argInterval;

    x = originX+r*cos();
    y = originY-r*sin(a*M_PI/180.0);

    setPos(x,y);
}
