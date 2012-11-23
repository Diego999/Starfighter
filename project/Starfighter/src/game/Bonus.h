#ifndef BONUS_H
#define BONUS_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Displayable.h"
#include "Spaceship.h"
#include "GameEngine.h"
#include "Qt/qreal.h"
#include "Qt/QPoint.h"

class Bonus : public Displayable
{
private:
	Spaceship spaceship;
	GameEngine gameEngine;
	Bonus bonus;
	Bonus bonus;

protected:
	Qt::qreal speed;

	Qt::qreal interval;


public:
	void trajectoryDraw(Qt::qreal x, Qt::qreal y);

	Bonus(Qt::QPoint P1, Qt::QPoint P2, Qt::QPoint P3, Qt::qreal speed);

};
#endif
