#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Destroyable.h"
#include "../engine/Displayable.h"
#include "Bonus.h"
#include "../engine/GameEngine.h"
#include "../enum/Enum.h"

class Spaceship : public Destroyable, public Displayable
{
public:
	Spaceship();
	void attack(int puissance);
	void top(int step);
	void bottom(int step);

private:
	QString playerName;
	qreal speed;

	int resistanceForceField;

    //Bonus bonus[3];
    //GameEngine gameEngine;
};
#endif
