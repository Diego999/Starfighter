#include "include/engine/GameEngine.h"

GameEngine::GameEngine()
{

}

int GameEngine::elapsedTime()
{
	return 0;
}

Obstacle* GameEngine::spawn(Obstacle* obstacle)
{
    return new Obstacle(0,0);
}

double GameEngine::randDouble()
{
	return 0;
}

int GameEngine::randInt(int range)
{
	return 0;
}
