#ifndef PROJECTILE_ALIEN_H
#define PROJECTILE_ALIEN_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Projectile.h"
#include "Qt/qreal.h"

class ProjectileAlien : public Projectile
{
private:
	Qt::qreal r;

	Qt::qreal a;


public:
	void ProjectileAlien(int x, int y, Qt::qreal a, Qt::qreal r);

};
#endif
