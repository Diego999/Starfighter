#include "include/game/BonusSpeed.h"


BonusSpeed::BonusSpeed(qreal _dSpeed, int _expiration, GameEngine *_gameEngine, Spaceship *_spaceShip)
    :Bonus(_gameEngine,_spaceShip),
      dSpeed(_dSpeed),expiration(_expiration)
{

}

BonusSpeed::~BonusSpeed()
{

}
