#ifndef ASTEROID_H
#define ASTEROID_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Destroyable.h"
#include "Obstacle.h"
#include "Projectile.h"
#include "Qt/qreal.h"

class Asteroid : public Destroyable, public Obstacle, public Projectile
{
private:
	Qt::qreal slope;


public:
	void destroy();

	void Asteroid(int x, int y, int resistance, int healthPoint);

};
#endif
