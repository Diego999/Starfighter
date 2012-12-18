#ifndef SPAWN_ENGINE_H
#define SPAWN_ENGINE_H

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
