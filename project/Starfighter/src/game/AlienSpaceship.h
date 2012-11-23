#ifndef ALIEN_SPACESHIP_H
#define ALIEN_SPACESHIP_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Obstacle.h"
#include "Destroyable.h"
#include "Qt/QPoint.h"

class AlienSpaceship : public Obstacle, public Destroyable
{
private:
	int nbSpirales;


public:
	void AlienSpaceShip(Qt::QPoint P1, Qt::QPoint P2, Qt::QPoint P3, int nbSpirales);

};
#endif
