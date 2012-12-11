#ifndef SPAWN_ENGINE_H
#define SPAWN_ENGINE_H

#include "include/engine/GameEngine.h"
class SpawnEngine : public QObject
{
    Q_OBJECT

public:
    SpawnEngine(int difficulty);
    ~SpawnEngine();

private slots:
    void timerFired();

signals:
    void obstacleShouldSpawn(Obstacle *);

private:
    bool spawnAsteroids;
    bool spawnAlienMothership;
    bool spawnSatellites;
    bool spawnSupernovae;
};
#endif
