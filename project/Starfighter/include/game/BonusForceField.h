#ifndef BONUS_FORCE_FIELD_H
#define BONUS_FORCE_FIELD_H

#include "include/game/Bonus.h"

class GameEngine;
class Spaceship;

class BonusForceField : public Bonus
{
public:
    BonusForceField(GameEngine *_gameEngine);
    ~BonusForceField() {}
};
#endif
