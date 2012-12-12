#ifndef BONUS_H_P_H
#define BONUS_H_P_H

#include "include/game/Bonus.h"

class BonusHP : public Bonus
{
public:
    BonusHP(int healthPoint, GameEngine *ge, Spaceship *ss);
    ~BonusHP();
    int getHealthPoint() const;
private:
	int healthPoint;
};
#endif
