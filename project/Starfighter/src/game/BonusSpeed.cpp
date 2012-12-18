#include "include/game/BonusSpeed.h"


BonusSpeed::BonusSpeed(qreal _dSpeed, int _expiration, GameEngine *_gameEngine)
    :Bonus(_gameEngine),
      dSpeed(_dSpeed),expiration(_expiration)
{

}
