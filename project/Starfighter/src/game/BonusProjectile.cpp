#include "include/game/BonusProjectile.h"


BonusProjectile::BonusProjectile(QPoint P1, QPoint P2, QPoint P3, /*qreal speed,*/TypeProjectiles _type, int _expiration, GameEngine *ge, Spaceship *ss)
    :Bonus(P1,P2,P3,ge,ss),type(_type),expiration(_expiration)
{
}

TypeProjectiles BonusProjectile::getType() const
{
    return type;
}

int BonusProjectile::getExpiration() const
{
    return expiration;
}
