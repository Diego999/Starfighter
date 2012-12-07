#include "include/engine/GameEngine.h"
#include "include/engine/DisplayEngine.h"
#include "include/game/Obstacle.h"
#include "include/game/Spaceship.h"

GameEngine::GameEngine():QObject()
{
    de = new DisplayEngine(this,0);
    de->show();

    createSpaceship();
    startTimer(10);
}

void GameEngine::createSpaceship()
{
    int width = de->sceneSize().width();
    int height = de->sceneSize().height();

    spaceship[0] = new Spaceship(0,height/2,Player1,this);
    spaceship[1] = new Spaceship(width,height/2,Player2,this);
}

void GameEngine::timerEvent(QTimerEvent *)
{
    de->updateScreen();
}

int GameEngine::elapsedTime()
{
	return 0;
}

void GameEngine::spawn(Obstacle* obstacle)
{

}

double GameEngine::randDouble()
{
	return 0;
}

int GameEngine::randInt(int range)
{
	return 0;
}

int GameEngine::timeGamevalue(){return timeGame;}
