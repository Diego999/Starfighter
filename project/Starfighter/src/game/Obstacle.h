#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "../engine/Displayable.h"
#include "../engine/GameEngine.h"
#include "../enum/Enum.h"

class Obstacle : public Displayable
{
public:
    Obstacle(int x=0, int y=0);

protected:
	qreal trajectoryDraw(qreal x);
	
private:
    //GameEngine gameEngine;

};
#endif
