#include "include/game/BonusHP.h"

BonusHP::BonusHP(int healthPoint, GameEngine *ge, Spaceship *ss)
    :Bonus(ge,ss),healthPoint(healthPoint)
{

}

BonusHP::~BonusHP()
{

}

int BonusHP::getHealthPoint() const
{
    return healthPoint;
}
