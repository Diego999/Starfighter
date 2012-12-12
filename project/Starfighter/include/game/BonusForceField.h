#ifndef BONUS_FORCE_FIELD_H
#define BONUS_FORCE_FIELD_H

#include "include/game/Bonus.h"

class BonusForceField : public Bonus
{
public:
    BonusForceField(int resistanceForceField, GameEngine *ge, Spaceship *ss);
    ~BonusForceField();
    int getResistanceForceField() const;
private:
	int resistanceForceField;
};
#endif
