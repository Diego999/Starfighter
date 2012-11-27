#ifndef BONUS_PROJECTILE_H
#define BONUS_PROJECTILE_H

#include "include/game/Bonus.h"
#include "include/enum/Enum.h"

class BonusProjectile : public Bonus
{
    Q_OBJECT

public:
    BonusProjectile(TypeProjectiles type, int expiration);
	
private:
	int expiration;

	};
#endif
