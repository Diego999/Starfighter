#include "include/game/BonusProjectile.h"


BonusProjectile::BonusProjectile(TypeProjectiles _type, int _expiration, GameEngine *ge, Spaceship *ss)
    :Bonus(ge,ss),type(_type),expiration(_expiration)
{
}

BonusProjectile::~BonusProjectile()
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
