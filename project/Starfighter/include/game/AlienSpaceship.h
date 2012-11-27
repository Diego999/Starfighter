#ifndef ALIEN_SPACESHIP_H
#define ALIEN_SPACESHIP_H

#include "include/game/Obstacle.h"
#include "include/game/Destroyable.h"

class AlienSpaceship : public Obstacle, public Destroyable
{
	Q_OBJECT
	
public:
    AlienSpaceship(QPoint P1, QPoint P2, QPoint P3, int nbSpirales);
	
private:
	int nbSpirales;

};
#endif
