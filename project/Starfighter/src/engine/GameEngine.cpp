#include "include/engine/GameEngine.h"
#include "include/engine/DisplayEngine.h"
#include "include/game/Obstacle.h"
#include "include/game/Spaceship.h"
#include "include/engine/UserControlsEngine.h"
#include "include/utils/Settings.h"
#include <QDebug>

GameEngine::GameEngine():QObject(), isRunning(false)
{
    de = new DisplayEngine(this,0);
    uc = new UserControlsEngine(this);

    timerControle();
    createSpaceship();
}

void GameEngine::createSpaceship()
{
    int width = de->sceneSize().width();
    int height = de->sceneSize().height();

    spaceship[0] = new Spaceship(0,height/2,Player1,this);
    spaceship[1] = new Spaceship(width,height/2,Player2,this);

    de->addShip(spaceship[0]);
    de->addShip(spaceship[1]);
}

void GameEngine::timerEvent(QTimerEvent *event)
{
    de->timerEvent(event);
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
    return qrand() % range;
}

int GameEngine::timeGamevalue(){return timeGame;}

void GameEngine::timerControle(int tps)
{
    if(isRunning)
    {
        qDebug() << isRunning << "Stop Timer 1:" <<idTimer;
        killTimer(idTimer);
        idTimer = -1;
        qDebug() << isRunning<< "Stop Timer 2:" <<idTimer;

    }

    else
    {
        idTimer = startTimer(tps);
        qDebug() << isRunning<< "startTimer:" <<idTimer;
    }
    isRunning = !isRunning;

}
