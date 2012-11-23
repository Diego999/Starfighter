#ifndef BONUS_FORCE_FIELD_H
#define BONUS_FORCE_FIELD_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Bonus.h"

class BonusForceField : public Bonus
{
private:
	int resistanceForceField;


public:
	void BonusForceField(int resistanceForceField);

};
#endif
