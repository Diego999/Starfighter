#include "include/game/BonusSpeed.h"


BonusSpeed::BonusSpeed(int _speed, int expiration, GameEngine *ge, Spaceship *ss)
    :Bonus(ge,ss),speed(_speed),expiration(expiration)
{

}

BonusSpeed::~BonusSpeed()
{

}

int BonusSpeed::getSpeed() const
{
    return speed;
}
int BonusSpeed::getExpiration() const
{
    return expiration;
}
