#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "include/game/Displayable.h"
#include "include/engine/GameEngine.h"
#include "include/enum/Enum.h"

class Obstacle : public Displayable
{
    Q_OBJECT

public:
    Obstacle(int x=0, int y=0, GameEngine *ge);

protected:
	qreal trajectoryDraw(qreal x);
	
private:
    GameEngine *gameEngine;

};
#endif
