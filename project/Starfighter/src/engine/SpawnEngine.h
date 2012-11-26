#ifndef SPAWN_ENGINE_H
#define SPAWN_ENGINE_H

#include "GameEngine.h"
#include "Qt/QTimerEvent .h"

class SpawnEngine
{
public:
	SpawnEngine();
	
	void timerEvent(Qt::QTimerEvent * event);
	
private:
	GameEngine gameEngine;

};
#endif
