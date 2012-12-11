#include "include/engine/SpawnEngine.h"
#include "include/game/AlienSpaceship.h"

SpawnEngine::SpawnEngine(int difficulty)
{
    spawnAsteroids = (bool)(difficulty & Asteroids);
    spawnAlienMothership = (bool)(difficulty & AlienMothership);
    spawnSatellites = (bool)(difficulty & Satellites);
    spawnSupernovae = (bool)(difficulty & Supernovae);
}

SpawnEngine::~SpawnEngine()
{

}

void SpawnEngine::timerFired()
{


}
