#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Displayable.h"
#include "GameEngine.h"
#include "../enum/Enum.h"

class Obstacle : public Displayable
{
public:
	Obstacle(int x, int y);

protected:
	qreal trajectoryDraw(qreal x);
	
private:
	GameEngine gameEngine;

};
#endif
