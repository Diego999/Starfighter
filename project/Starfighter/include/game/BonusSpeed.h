#ifndef BONUS_SPEED_H
#define BONUS_SPEED_H

#include "include/game/Bonus.h"


class BonusSpeed : public Bonus
{
    //Q_OBJECT

public:
    BonusSpeed(int speed);
	
private:
	int speed;
	int expiration;
};
#endif
