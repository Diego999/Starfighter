#include "include/game/BonusHP.h"

BonusHP::BonusHP(QPoint P1, QPoint P2, QPoint P3, /*qreal speed,*/int healthPoint, GameEngine *ge, Spaceship *ss)
    :Bonus(P1,P2,P3,/*speed,*/ge,ss),healthPoint(healthPoint)
{
}

int BonusHP::getHealthPoint() const
{
    return healthPoint;
}
