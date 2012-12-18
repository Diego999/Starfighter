#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "include/enum/Enum.h"

class DisplayEngine;
class SpawnEngine;
class UserControlsEngine;
class Projectile;
class Obstacle;
class Bonus;
class Spaceship;
class Settings;
class Destroyable;

class GameEngine : public QObject
{
    Q_OBJECT

public:	
    GameEngine(GameMode gameMode, int duration, SpaceshipType player1Ship, SpaceshipType player2Ship, int difficulty, QObject*);
    ~GameEngine();

    void spawn(Obstacle* obstacle);
    void createSpaceship();
	int elapsedTime();
    static double randDouble();
    static int randInt(int range);
    int timeGamevalue();

    void timerControle(int tps = 15);

    Spaceship * ship1() const {return spaceship[0];}
    Spaceship * ship2() const {return spaceship[1];}

    DisplayEngine* displayEngine() const { return de;}
    UserControlsEngine* userControlsEngine() const {return uc;}
    SpawnEngine* spawnEngine() const {return se;}

    void timerEvent(QTimerEvent *);
public slots:
    void elemenDestroyed(Destroyable* destroyItem);
private:
    DisplayEngine *de;
    SpawnEngine *se;
    UserControlsEngine *uc;
    //Projectile *projectile[];
    //Obstacle *obstacle[];
    //Bonus *bonus;
    Spaceship *spaceship[2];
    Settings& settings;
    int timeGame;

    // For elapsedTime()
    QElapsedTimer elapsedTimer;
    qint64 timeAlreadyCounted;

    bool isRunning;
    int idTimer;


signals:
    void endGame();
    void signalPause(bool); // true = isPause

};
#endif
