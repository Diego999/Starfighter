#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

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
    Q_OBJECT

public:
	static double randDouble();
	static int randInt(int range);
	
	GameEngine();
	Obstacle spawn(Obstacle obstacle);
	
	int elapsedTime();
	
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

};
#endif
