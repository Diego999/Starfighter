#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "DisplayEngine.h"
#include "SpawnEngine.h"
#include "UserControlsEngine.h"
#include "Projectile.h"
#include "Obstacle.h"
#include "Bonus.h"
#include "Spaceship.h"
#include "Settings.h"

class GameEngine
{
private:
	DisplayEngine displayEngine;
	SpawnEngine spawnEngine;
	UserControlsEngine userControlsEngine;
	DisplayEngine displayEngine;
	Projectile projectile[];
	Obstacle obstacle[];
	Bonus bonus[];
	Spaceship spaceship[2];
	Settings settings;

public:
	int elapsedTime();

	Obstacle spawn(Obstacle obstacle);

	static double randDouble();

	static int randInt(int range);

	void GameEngine();

};
#endif
