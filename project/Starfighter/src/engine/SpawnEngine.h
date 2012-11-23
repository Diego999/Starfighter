#ifndef SPAWN_ENGINE_H
#define SPAWN_ENGINE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "GameEngine.h"
#include "Qt/QTimerEvent .h"

class SpawnEngine
{
private:
	GameEngine gameEngine;

public:
	void timerEvent(Qt::QTimerEvent * event);

	void SpawnEngine();

};
#endif
