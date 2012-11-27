#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "include/engine/DisplayEngine.h"
#include "include/engine/SpawnEngine.h"
#include "include/engine/UserControlsEngine.h"
#include "include/game/Projectile.h"
#include "include/game/Obstacle.h"
#include "include/game/Bonus.h"
#include "include/game/Spaceship.h"
#include "include/utils/Settings.h"

class GameEngine
{
    Q_OBJECT

public:
	static double randDouble();
	static int randInt(int range);
	
    GameEngine();
    Obstacle* spawn(Obstacle* obstacle);
	
	int elapsedTime();
	
private:
    DisplayEngine *displayEngine;
    SpawnEngine *spawnEngine;
    UserControlsEngine *userControlsEngine;
    Projectile *projectile[];
    Obstacle *obstacle[];
    Bonus *bonus;
    Spaceship *spaceship[2];
    Settings *settings;

};
#endif
