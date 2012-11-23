#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Destroyable.h"
#include "Displayable.h"
#include "Bonus.h"
#include "GameEngine.h"
#include "__enumeration__ TypePojectiles.h"
#include "Qt/QString.h"
#include "Qt/qreal.h"

class Spaceship : public Destroyable, public Displayable
{
private:
	Qt::QString playerName;

	Qt::qreal speed;

	int resistanceForceField;

	Bonus bonus[3];
	GameEngine gameEngine;
	__enumeration__ TypePojectiles __enumeration__ TypePojectiles;

public:
	void attack(int puissance);

	void top(int step);

	void bottom(int step);

};
#endif
