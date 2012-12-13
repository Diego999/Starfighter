#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "include/game/Displayable.h"

class Obstacle : public virtual Displayable
{
public:
    Obstacle(qreal _dX, qreal _dY);
    virtual ~Obstacle();

};
#endif
