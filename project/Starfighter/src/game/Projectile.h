#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Displayable.h"
#include "GameEngine.h"
#include "__enumeration__ Shooter.h"
#include "shooter.h"
#include "Qt/qreal.h"
#include "Qt/QColor.h"

class Projectile : public Displayable
{
private:
	GameEngine gameEngine;
	__enumeration__ Shooter __enumeration__ Shooter;

protected:
	int power;

	int originX;

	int originY;

	Qt::qreal speed;

	Qt::qreal direction;

	Qt::QColor color;

	int interval;

	shooter from;


protected:
	virtual Qt::qreal trajectoryDraw(Qt::qreal x)=0;

public:
	void Projectile(int originX, int originY);

};
#endif
