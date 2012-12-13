#include "include/game/BonusHP.h"

BonusHP::BonusHP(qreal _dHealthPoint, GameEngine *_gameEngine, Spaceship *_spaceShip)
    :Bonus(_gameEngine,_spaceShip),
      dHealthPoint(_dHealthPoint)
{

}

BonusHP::~BonusHP()
{

}
