#include "ProjectileCross.h"
#include <math.h>

void ProjectileCross::ProjectileCross(int _x, int _y, shooter _from,int _nb)
    :Projectile(_x,_y,_from),nb(_nb)
{
	interval = 8;
}

qreal ProjectileCross::trajectoryDraw(qreal _x)
{
    if(nb == 0)
        return 0;
    else if(nb == -1)
        return -_x/10;
    else
        return _x/10;
}

void ProjectileCross::advance(int step)
{
    Projectile::advance(step);

	x+=interval;
    setPos(x,y-trajectoryDraw(x));
}
