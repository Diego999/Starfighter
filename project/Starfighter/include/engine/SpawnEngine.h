#ifndef SPAWN_ENGINE_H
#define SPAWN_ENGINE_H

#define SPAWN_INTERVAL 400

#define RESISTANCE_ASTEROID 20
#define RESISTANCE_ALIEN 20
#define ALIEN_SWIRL_MIN 10
#define ALIEN_SWIRL_MAX 20
#define BONUS_HEALTH_MIN 30
#define BONUS_HEALTH_MAX MAX_SPACESHIP_PV
#define BONUS_PROJECTILE_DURATION 10000
#define BONUS_TYPE_PROJECTILES_MIN 2
#define BONUS_TYPE_PROJECTILES_MAX 4
#define BONUS_SPEED_MIN 8
#define BONUS_SPEED_MAX 20
#define BONUS_SPEED_DURATION 10000

class GameEngine;
class DisplayEngine;

class SpawnEngine : public QObject
{
    Q_OBJECT

public:
    SpawnEngine(int difficulty, GameEngine*);
    ~SpawnEngine();

public slots:
    void pause(bool);

private slots:
    void timerFired();

private:
    GameEngine *ge;
    DisplayEngine *de;
    bool spawnAsteroids;
    bool spawnAlienMothership;
    bool spawnSatellites;
    bool spawnSupernovae;
    QTimer *timer;

    const static int kProbAsteroid = 100;
    const static int kProbAlien = 50;
    const static int kProbSat = 20;
    const static int kProbSupernova = 1;

    int totalProba;
    int intervalAsteroid;
    int intervalAlien;
    int intervalSat;
    int intervalSupernova;

    static int irand(int min, int max);

    static double proba(double t);
};
#endif
