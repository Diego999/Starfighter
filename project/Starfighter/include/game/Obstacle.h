#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "include/game/Displayable.h"
#include "include/enum/Enum.h"

class Obstacle : public virtual Displayable
{
    //Q_OBJECT

public:
    Obstacle(int x, int y);
    virtual ~Obstacle();

};
#endif
