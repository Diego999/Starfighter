#ifndef BONUS_H
#define BONUS_H

#include "Displayable.h"
#include "Spaceship.h"
#include "GameEngine.h"

class Bonus : public Displayable
{
	Q_OBJECT
public:
	Bonus(QPoint P1, QPoint P2, QPoint P3, qreal speed);

	void trajectoryDraw(qreal x, qreal y);
	
protected:
	qreal speed;
	qreal interval;
	
private:
	Spaceship spaceship;
	GameEngine gameEngine;
	Bonus bonus;
};
#endif
