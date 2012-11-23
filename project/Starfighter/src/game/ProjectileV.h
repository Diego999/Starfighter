#ifndef PROJECTILE_V_H
#define PROJECTILE_V_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Projectile.h"
#include "Qt/qreal.h"

class ProjectileV : public Projectile
{
private:
	Qt::qreal omega;

	Qt::qreal a;


public:
	void ProjectileV(int x, int y, Qt::qreal a, Qt::qreal omega);

};
#endif
