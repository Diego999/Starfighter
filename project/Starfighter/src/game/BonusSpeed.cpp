#include "include/game/BonusSpeed.h"


BonusSpeed::BonusSpeed(QPoint P1, QPoint P2, QPoint P3, qreal speed, int expiration, GameEngine *ge, Spaceship *ss)
    :Bonus(P1,P2,P3,speed,ge,ss),expiration(expiration)
{
}
