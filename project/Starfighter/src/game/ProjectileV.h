#ifndef PROJECTILE_V_H
#define PROJECTILE_V_H

#include "Projectile.h"

class ProjectileV : public Projectile
{
public:
	ProjectileV(int _x, int _y, qreal _ampli, qreal _omega);
	
private:
	qreal omega;
	qreal ampli;
	
	void advance(int step);
    qreal trajectoryDraw(qreal xx);
};
#endif
