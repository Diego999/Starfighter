#ifndef BONUS_H
#define BONUS_H

#include "include/game/Displayable.h"
#include "include/game/Spaceship.h"
#include "include/engine/GameEngine.h"

class Bonus : public Displayable
{
    //Q_OBJECT
public:
    Bonus(QPoint P1, QPoint P2, QPoint P3, qreal speed, GameEngine *ge, Spaceship *ss);
    Bonus();
	void trajectoryDraw(qreal x, qreal y);
	
protected:
	qreal speed;
	qreal interval;
	
private:
    Spaceship *spaceship;
    GameEngine *gameEngine;
};
#endif
