#ifndef BONUS_PROJECTILE_H
#define BONUS_PROJECTILE_H

#include "Bonus.h"
#include "../enum/Enum.h"

class BonusProjectile : public Bonus
{
public:
	void BonusProjectile(TypeProjectiles type, int expiration);
	
private:
	int expiration;

	};
#endif
