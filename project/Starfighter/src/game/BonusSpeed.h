#ifndef BONUS_SPEED_H
#define BONUS_SPEED_H

#include "Bonus.h"


class BonusSpeed : public Bonus
{
public:
    BonusSpeed(int speed);
	
private:
	int speed;
	int expiration;
};
#endif
