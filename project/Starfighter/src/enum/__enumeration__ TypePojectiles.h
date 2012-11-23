#ifndef <<ENUMERATION>> _TYPE_POJECTILES_H
#define <<ENUMERATION>> _TYPE_POJECTILES_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Obstacle.h"
#include "Spaceship.h"
#include "BonusProjectile.h"

class __enumeration__ TypePojectiles
{
private:
	Obstacle obstacle;
	Spaceship spaceship;
	BonusProjectile bonusProjectile;
public:
	int ProjectileSimple;

	int ProjectileCross;

	int ProjectileV;

	int ProjectileAlien;

	int Nothing;

};
#endif
