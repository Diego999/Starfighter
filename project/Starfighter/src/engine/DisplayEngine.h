#ifndef DISPLAY_ENGINE_H
#define DISPLAY_ENGINE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Displayable.h"
#include "GameEngine.h"
#include "Qt/QGraphicsScene.h"
#include "Qt/QGraphicsView.h"
#include "Qt/QSize.h"

class DisplayEngine
{
private:
	Qt::QGraphicsScene scene;

	Qt::QGraphicsView view;

	Displayable displayable[];
	GameEngine gameEngine;
	GameEngine gameEngine;

public:
	Qt::QSize sceneSize();

	void DisplayEngine(int width, int height);

};
#endif
