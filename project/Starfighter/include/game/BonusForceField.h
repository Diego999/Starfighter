#ifndef BONUS_FORCE_FIELD_H
#define BONUS_FORCE_FIELD_H

#include "include/game/Bonus.h"

class GameEngine;
class Spaceship;

class BonusForceField : public Bonus
{
public:
    BonusForceField(qreal _dResistanceForceField, GameEngine *_gameEngine, Spaceship *_spaceShip);
    ~BonusForceField();
    qreal getResistanceForceField() const {return dResistanceForceField;}
private:
    qreal dResistanceForceField;
};
#endif
