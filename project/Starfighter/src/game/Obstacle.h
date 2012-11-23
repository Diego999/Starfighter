#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Displayable.h"
#include "GameEngine.h"
#include "__enumeration__ TypePojectiles.h"
#include "Qt/qreal.h"

class Obstacle : public Displayable
{
private:
	GameEngine gameEngine;
	__enumeration__ TypePojectiles __enumeration__ TypePojectiles;

protected:
	Qt::qreal trajectoryDraw(Qt::qreal x);

public:
	void Obstacle(int x, int y);

};
#endif
