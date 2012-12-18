#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "include/enum/Enum.h"

class DisplayEngine;
class SpawnEngine;
class UserControlsEngine;
class Projectile;
class Supernova;
class Spaceship;
class Asteroid;
class Bonus;
class AlienSpaceship;
class Destroyable;
class Displayable;
class Settings;
class QMutex;

class GameEngine : public QObject
{
    Q_OBJECT

public:	
    GameEngine(GameMode gameMode, int duration, SpaceshipType player1Ship, SpaceshipType player2Ship, int difficulty, QObject*);
    ~GameEngine();

    static double randDouble();
    static int randInt(int range);

    void createSpaceship();
	int elapsedTime();    
    int timeGamevalue() const {return timeGame;}
    void timerControle(int tps = 15);

    Spaceship * ship1() const {return listSpaceship[0];}
    Spaceship * ship2() const {return listSpaceship[1];}

    DisplayEngine* displayEngine() const { return de;}
    UserControlsEngine* userControlsEngine() const {return uc;}
    SpawnEngine* spawnEngine() const {return se;}

    void timerEvent(QTimerEvent *);

    void addProjectile(Projectile *_inProjectile);
    void addSupernova(Supernova *_inSupernova);
    void addShip(Spaceship *_inSpaceship);
    void removeShip(Spaceship *_inSpaceship);
    void addAsteroid(Asteroid *_inAsteroide);
    void removeAsteroid(Asteroid *_inAsteroide);
    void addSmallAsteroid(Asteroid *_inAsteroide);
    void removeSmallAsteroid(Asteroid *_inAsteroide);
    void addBonus(Bonus *_inBonus);
    void addAlienSpaceship(AlienSpaceship *_inAlienSpaceship);
    void removeAlienSpaceship(AlienSpaceship *_inAlienSpaceship);

    void endGameDeathMatch(Spaceship* _ship=0);
    void endGameTimer();
    void escapeGame();

signals:
    void endGame();
    void signalPause(bool); // true = isPause

public slots:
    void elemenDestroyed(Destroyable* destroyItem);

private:
    void gameType();

    void checkOutsideScene(QList<Displayable*> &list);
    void checkPlayerOutsideScene(QList<Spaceship*> &list);
    void clearList(QList<Displayable*> &list);
    bool checkCollisionItemAndList(const int i_list1,QList<Displayable*> &list1,QList<Displayable*> &list2);
    bool checkCollisionSpaceshipAndList(const int i_list1,QList<Displayable*> &list);
    void runTestCollision(QList<Displayable*> &list);

    DisplayEngine *de;
    SpawnEngine *se;
    UserControlsEngine *uc;
    Settings& settings;

    QMutex* mutex;

    bool isRunning;
    int idTimer;
    bool isTimer;
    int timeGame;//Really useful ?

    // For elapsedTime()
    QElapsedTimer elapsedTimer;
    qint64 timeAlreadyCounted;

    QList<Displayable*>  listProjectile;
    QList<Displayable*>  listAsteroide;
    QList<Displayable*>  listSmallAsteroide;
    QList<Displayable*>  listBonus;
    QList<Spaceship*>    listSpaceship;
    QList<Displayable*>  listAlienSpaceship;
    QList<Displayable*>  listSupernova;


};
#endif
