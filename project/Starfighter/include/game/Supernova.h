#ifndef SUPERNOVA_H
#define SUPERNOVA_H

#include "include/game/Obstacle.h"
#include "include/game/Displayable.h"
#include "include/engine/GameEngine.h"

class Supernova : public Obstacle
{
    //Q_OBJECT
public:
    Supernova(int x, int y,GameEngine* ge);
    ~Supernova();
private:
	static const int nbSpirales = 360;

    GameEngine* gameEngine;
};
#endif
