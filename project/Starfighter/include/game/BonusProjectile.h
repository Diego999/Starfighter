#ifndef BONUS_PROJECTILE_H
#define BONUS_PROJECTILE_H

#include "include/game/Bonus.h"
#include "include/enum/Enum.h"

class BonusProjectile : public Bonus
{
public:
    BonusProjectile(TypeProjectiles type, int expiration, GameEngine *ge, Spaceship *ss);
    ~BonusProjectile();

    TypeProjectiles getType() const;
    int getExpiration() const;
private:
    TypeProjectiles type;
	int expiration;
};
#endif
