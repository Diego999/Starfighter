#ifndef BONUS_H_P_H
#define BONUS_H_P_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Bonus.h"

class BonusHP : public Bonus
{
private:
	int healthPoint;


public:
	void BonusHP(int healthPoint);

};
#endif
