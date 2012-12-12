#ifndef BONUS_SPEED_H
#define BONUS_SPEED_H

#include "include/game/Bonus.h"


class BonusSpeed : public Bonus
{
public:
    BonusSpeed(int speed, int expiration, GameEngine *ge, Spaceship *ss);
    ~BonusSpeed();

    int getSpeed() const;
    int getExpiration() const;
private:
    int speed;
	int expiration;
};
#endif
