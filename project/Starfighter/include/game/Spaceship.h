#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "include/game/Destroyable.h"
#include "include/game/Displayable.h"
#include "include/game/Bonus.h"
#include "include/engine/GameEngine.h"
#include "include/enum/Enum.h"

class Spaceship : public Destroyable, public Displayable
{
    //Q_OBJECT

public:
    Spaceship(GameEngine *ge);
	void attack(int puissance);
	void top(int step);
	void bottom(int step);

private:
	QString playerName;
	qreal speed;

	int resistanceForceField;

    Bonus *bonus[3];
    GameEngine *gameEngine;
};
#endif
