#ifndef BONUS_H_P_H
#define BONUS_H_P_H

#include "include/game/Bonus.h"

class BonusHP : public Bonus
{
    Q_OBJECT

public:
	BonusHP(int healthPoint);
	
private:
	int healthPoint;
};
#endif
