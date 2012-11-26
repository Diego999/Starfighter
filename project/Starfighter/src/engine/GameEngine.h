#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "DisplayEngine.h"
#include "SpawnEngine.h"
#include "UserControlsEngine.h"
#include "../game/Projectile.h"
#include "../game/Obstacle.h"
#include "../game/Bonus.h"
#include "../game/Spaceship.h"
#include "../menu/Settings.h"

class GameEngine
{
    Q_OBJECT

public:
	static double randDouble();
	static int randInt(int range);
	
    GameEngine();
    //Obstacle* spawn(Obstacle* obstacle);
	
	int elapsedTime();
	
private:
    //DisplayEngine displayEngine;
    //SpawnEngine spawnEngine;
    //UserControlsEngine userControlsEngine;
    Projectile* projectile;
    //Obstacle* obstacle;
    //Bonus* bonus;
    //Spaceship spaceship[2];
	Settings settings;

};
#endif
