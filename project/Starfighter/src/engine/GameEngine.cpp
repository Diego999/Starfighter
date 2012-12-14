#include "include/engine/GameEngine.h"
#include "include/engine/DisplayEngine.h"
#include "include/engine/SpawnEngine.h"
#include "include/game/Obstacle.h"
#include "include/game/Spaceship.h"
#include "include/engine/UserControlsEngine.h"
#include "include/utils/Settings.h"
#include "include/game/Destroyable.h"

#include "include/game/AlienSpaceship.h"
#include "include/game/Asteroid.h"
#include "include/game/BonusForceField.h"
#include "include/game/BonusHP.h"
#include "include/game/BonusProjectile.h"
#include "include/game/BonusSpeed.h"
#include "include/game/Supernova.h"

GameEngine::GameEngine(GameMode gameMode, int duration, SpaceshipType player1Ship, SpaceshipType player2Ship, int difficulty, QObject *parent = 0):QObject(parent), isRunning(false), settings(Settings::getGlobalSettings())
{
    de = new DisplayEngine(this,0);
    uc = new UserControlsEngine(this);
    se = new SpawnEngine(difficulty, this);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    timerControle();
    createSpaceship();
}

void GameEngine::createSpaceship()
{
    int width = de->sceneSize().width();
    int height = de->sceneSize().height();

    spaceship[0] = new Spaceship(0,height/2,Player1,settings.playerOneName(),5,100,100,this);//Change with the parameter of a spaceship
    spaceship[1] = new Spaceship(width,height/2,Player2,settings.playerTwoName(),5,100,100,this);

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
    return (double)qrand() / (double)RAND_MAX;
}

int GameEngine::randInt(int range)
{
	if(range == 0)
		return 0;
	else
		return qrand() % range;
}

int GameEngine::timeGamevalue(){return timeGame;}

void GameEngine::elemenDestroyed(Destroyable* _destroyItem)
{
    if(Spaceship* s = dynamic_cast<Spaceship*>(_destroyItem))
        de->endGame(s);
    else if(Asteroid* a = dynamic_cast<Asteroid*>(_destroyItem))
    {
        if(a->isSmall())
            de->removeSmallAsteroid(a);
        else
            de->removeAsteroid(a);
    }
    else if(AlienSpaceship* a = dynamic_cast<AlienSpaceship*>(_destroyItem))
        de->removeAlienSpaceship(a);
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
