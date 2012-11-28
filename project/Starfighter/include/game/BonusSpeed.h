#ifndef BONUS_SPEED_H
#define BONUS_SPEED_H

#include "include/game/Bonus.h"


class BonusSpeed : public Bonus
{
    //Q_OBJECT

public:
    BonusSpeed(QPoint P1, QPoint P2, QPoint P3, qreal speed, int expiration, GameEngine *ge, Spaceship *ss);
	
private:
	int expiration;
};
#endif
