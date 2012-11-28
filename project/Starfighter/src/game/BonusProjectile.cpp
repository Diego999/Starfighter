#include "include/game/BonusProjectile.h"


BonusProjectile::BonusProjectile(QPoint P1, QPoint P2, QPoint P3, qreal speed,TypeProjectiles type, int expiration, GameEngine *ge, Spaceship *ss)
    :Bonus(P1,P2,P3,speed,ge,ss),type(type),expiration(expiration)
{
}
