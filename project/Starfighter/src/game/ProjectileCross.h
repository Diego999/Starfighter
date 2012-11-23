#ifndef PROJECTILE_CROSS_H
#define PROJECTILE_CROSS_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Projectile.h"

class ProjectileCross : public Projectile
{
private:
	int nb;


public:
	void ProjectileCross(int x, int y, int nb);

};
#endif
