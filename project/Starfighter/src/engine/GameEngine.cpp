#include "include/engine/GameEngine.h"
#include "include/engine/DisplayEngine.h"
#include "include/engine/SpawnEngine.h"
#include "include/game/Obstacle.h"
#include "include/game/Spaceship.h"
#include "include/engine/UserControlsEngine.h"
#include "include/utils/Settings.h"
#include "include/game/Destroyable.h"

GameEngine::GameEngine(GameMode gameMode, int duration, SpaceshipType player1Ship, SpaceshipType player2Ship, int difficulty, QObject *parent = 0):QObject(parent), isRunning(false)
{
    se = new SpawnEngine(difficulty);
    de = new DisplayEngine(this,0);
    uc = new UserControlsEngine(this);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    timerControle();
    createSpaceship();

    //TODO
    //connect signal from DESTROYABLE to something
}

void GameEngine::createSpaceship()
{
    int width = de->sceneSize().width();
    int height = de->sceneSize().height();

    spaceship[0] = new Spaceship(0,height/2,Player1,"Diego",5,100,100,50,this);//Change with the parameter of a spaceship
    spaceship[1] = new Spaceship(width,height/2,Player2,"Bianca",5,100,100,50,this);

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

void GameEngine::elemenDestroyed(Destroyable* destroyItem)
{

}

void GameEngine::timerControle(int tps)
{
    if(isRunning)
    {
        //qDebug() << isRunning << "Stop Timer 1:" <<idTimer;
        killTimer(idTimer);
        idTimer = -1;
        //qDebug() << isRunning<< "Stop Timer 2:" <<idTimer;
        emit signalPause(true);

    }

    else
    {
        idTimer = startTimer(tps);
        //qDebug() << isRunning<< "startTimer:" <<idTimer;
        emit signalPause(false);
    }
    isRunning = !isRunning;

}
