#include "include/game/BonusForceField.h"


BonusForceField::BonusForceField(QPoint P1, QPoint P2, QPoint P3, qreal speed,int resistanceForceField, GameEngine *ge, Spaceship *ss)
    :Bonus(P1,P2,P3,speed,ge,ss),resistanceForceField(resistanceForceField)
{
}
