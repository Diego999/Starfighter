#ifndef SPAWN_ENGINE_H
#define SPAWN_ENGINE_H

#include "GameEngine.h"
#include "QTimerEvent"

class SpawnEngine
{
public:
	SpawnEngine();
	
    void timerEvent(QTimerEvent * event);
	
private:
    //GameEngine gameEngine;

};
#endif
