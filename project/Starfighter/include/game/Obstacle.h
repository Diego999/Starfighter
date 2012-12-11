#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "include/game/Displayable.h"
#include "include/enum/Enum.h"

class Obstacle : public virtual Displayable
{
public:
    Obstacle(qreal x, qreal y);
    virtual ~Obstacle();

};
#endif
