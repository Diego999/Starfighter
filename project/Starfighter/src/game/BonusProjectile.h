#ifndef BONUS_PROJECTILE_H
#define BONUS_PROJECTILE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Bonus.h"
#include "__enumeration__ TypePojectiles.h"
#include "TypeProjectiles.h"

class BonusProjectile : public Bonus
{
private:
	int expiration;

	__enumeration__ TypePojectiles __enumeration__ TypePojectiles;

public:
	void BonusProjectile(TypeProjectiles type, int expiration);

};
#endif
