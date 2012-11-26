#include "math.h"
#include "ProjectileAlien.h"

ProjectileAlien::ProjectileAlien(int _x, int _y, qreal _arg, qreal _mod, Shooter _from)
    :Projectile(_x,_y,_from),arg(_arg),mod(_mod)
{

}

void ProjectileAlien::advance(int step)
{
    Projectile::advance(step);
    mod+=ProjectileAlien::modInterval;
    arg+=ProjectileAlien::argInterval;

    x = originX+mod*cos(arg*M_PI/180.0);
    y = originY-mod*sin(arg*M_PI/180.0);

    setPos(x,y);
}
