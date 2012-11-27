#ifndef BONUS_FORCE_FIELD_H
#define BONUS_FORCE_FIELD_H

#include "include/game/Bonus.h"

class BonusForceField : public Bonus
{
	Q_OBJECT

public:
	BonusForceField(int resistanceForceField);
	
private:
	int resistanceForceField;
};
#endif
