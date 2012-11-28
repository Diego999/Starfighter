#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "include/game/Displayable.h"
#include "include/engine/GameEngine.h"
#include "include/enum/Enum.h"

class Obstacle : public Displayable
{
    //Q_OBJECT

public:
    Obstacle(int x, int y);

protected:
	qreal trajectoryDraw(qreal x);


};
#endif
