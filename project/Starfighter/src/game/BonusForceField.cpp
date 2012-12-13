#include "include/game/BonusForceField.h"

BonusForceField::BonusForceField(qreal _dResistanceForceField, GameEngine *_gameEngine, Spaceship *_spaceShip)
    :Bonus(_gameEngine,_spaceShip),
      dResistanceForceField(_dResistanceForceField)
{
}

BonusForceField::~BonusForceField()
{

}
