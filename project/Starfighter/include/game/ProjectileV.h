#ifndef PROJECTILE_V_H
#define PROJECTILE_V_H

#include "include/game/Projectile.h"

class ProjectileV : public Projectile
{
    Q_OBJECT

public:
	ProjectileV(int _x, int _y, qreal _ampli, qreal _omega);
	
private:
	qreal omega;
	qreal ampli;
	
	void advance(int step);
    qreal trajectoryDraw(qreal xx);
};
#endif
