#ifndef ASTEROID_H
#define ASTEROID_H

#include "include/game/Destroyable.h"
#include "include/game/Obstacle.h"
#include "include/game/Projectile.h"

class Asteroid : public Destroyable, public Obstacle, public Projectile
{
public:
	Asteroid(int x, int y, int resistance, int healthPoint);

	void destroy();
	
private:
	qreal slope;
	
};
#endif
