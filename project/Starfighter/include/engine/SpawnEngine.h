#ifndef SPAWN_ENGINE_H
#define SPAWN_ENGINE_H

#include "include/engine/GameEngine.h"
#include <QTimerEvent>

class SpawnEngine
{
    Q_OBJECT

public:
    SpawnEngine(GameEngine *ge);
	
    void timerEvent(QTimerEvent * event);
	
private:
    GameEngine *gameEngine;

};
#endif
