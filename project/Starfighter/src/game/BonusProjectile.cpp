#include "include/game/BonusProjectile.h"

BonusProjectile::BonusProjectile(TypeProjectiles _type, int _expiration, GameEngine *_gameEngine)
    :Bonus(_gameEngine),
      type(_type),expiration(_expiration)
{
}

BonusProjectile::~BonusProjectile()
{

}
