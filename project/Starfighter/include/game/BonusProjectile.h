#ifndef BONUS_PROJECTILE_H
#define BONUS_PROJECTILE_H

#include "include/game/Bonus.h"
#include "include/enum/Enum.h"

class BonusProjectile : public Bonus
{
    //Q_OBJECT

public:
    BonusProjectile(QPoint P1, QPoint P2, QPoint P3, /*qreal speed,*/TypeProjectiles type, int expiration, GameEngine *ge, Spaceship *ss);
    TypeProjectiles getType() const;
    int getExpiration() const;
private:
    TypeProjectiles type;
	int expiration;
};
#endif
