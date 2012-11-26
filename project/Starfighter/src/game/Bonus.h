#ifndef BONUS_H
#define BONUS_H

#include "../engine/Displayable.h"
#include "Spaceship.h"
#include "../engine/GameEngine.h"

class Bonus : public Displayable
{
	Q_OBJECT
public:
	Bonus(QPoint P1, QPoint P2, QPoint P3, qreal speed);
    Bonus();
	void trajectoryDraw(qreal x, qreal y);
	
protected:
	qreal speed;
	qreal interval;
	
private:
    //Spaceship spaceship;
    //GameEngine gameEngine;
};
#endif
