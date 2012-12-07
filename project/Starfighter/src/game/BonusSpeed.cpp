#include "include/game/BonusSpeed.h"


BonusSpeed::BonusSpeed(QPoint P1, QPoint P2, QPoint P3, int _speed, int expiration, GameEngine *ge, Spaceship *ss)
    :Bonus(P1,P2,P3/*,speed*/,ge,ss),speed(_speed),expiration(expiration)
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
