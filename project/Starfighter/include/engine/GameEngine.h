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

class GameEngine : public QObject
{
    Q_OBJECT

public:	
    GameEngine();

    void spawn(Obstacle* obstacle);
	int elapsedTime();
    double randDouble();
    int randInt(int range);
    int timeGamevalue();

    Spaceship * ship1() const {return spaceship[0];}
    Spaceship * ship2() const {return spaceship[1];}

    DisplayEngine* displayEngine() const { return de;}

private:
    DisplayEngine *de;
    SpawnEngine *spawnEngine;
    UserControlsEngine *userControlsEngine;
    Projectile *projectile[];
    Obstacle *obstacle[];
    Bonus *bonus;
    Spaceship *spaceship[2];
    Settings *settings;
    int timeGame;

};
#endif
