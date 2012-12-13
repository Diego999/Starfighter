#include "include/game/BonusProjectile.h"

BonusProjectile::BonusProjectile(TypeProjectiles _type, int _expiration, GameEngine *_gameEngine, Spaceship *_spaceShip)
    :Bonus(_gameEngine,_spaceShip),
      type(_type),expiration(_expiration)
{
}

BonusProjectile::~BonusProjectile()
{

}
