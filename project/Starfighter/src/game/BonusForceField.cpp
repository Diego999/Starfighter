#include "include/game/BonusForceField.h"


BonusForceField::BonusForceField(int resistanceForceField, GameEngine *ge, Spaceship *ss)
    :Bonus(ge,ss),resistanceForceField(resistanceForceField)
{
}

BonusForceField::~BonusForceField()
{

}

int BonusForceField::getResistanceForceField() const
{
    return resistanceForceField;
}
