#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

class DisplayEngine;
class SpawnEngine;
class UserControlsEngine;
class Projectile;
class Obstacle;
class Bonus;
class Spaceship;
class Settings;

#include <QObject>
#include <QTimerEvent>

class GameEngine : public QObject
{
    Q_OBJECT

public:	
    GameEngine();

    void spawn(Obstacle* obstacle);
    void createSpaceship();
	int elapsedTime();
    double randDouble();
    int randInt(int range);
    int timeGamevalue();

    void timerControle();

    Spaceship * ship1() const {return spaceship[0];}
    Spaceship * ship2() const {return spaceship[1];}

    DisplayEngine* displayEngine() const { return de;}
    UserControlsEngine* userControlsEngine() const {return uc;}

    void timerEvent(QTimerEvent *);

private:
    DisplayEngine *de;
    SpawnEngine *spawnEngine;
    UserControlsEngine *uc;
    Projectile *projectile[];
    Obstacle *obstacle[];
    Bonus *bonus;
    Spaceship *spaceship[2];
    Settings *settings;
    int timeGame;

    int idTimer;

};
#endif
