#ifndef BONUS_H_P_H
#define BONUS_H_P_H

#include "Bonus.h"

class BonusHP : public Bonus
{
public:
	BonusHP(int healthPoint);
	
private:
	int healthPoint;
};
#endif
