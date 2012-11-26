#ifndef DISPLAY_ENGINE_H
#define DISPLAY_ENGINE_H

#include "Displayable.h"
#include "GameEngine.h"

class DisplayEngine
{
    Q_OBJECT
public:
	DisplayEngine(int width, int height);
	
	QSize sceneSize();
	
private:
	QGraphicsScene scene;

	QGraphicsView view;

	Displayable displayable[];
	GameEngine gameEngine;
	GameEngine gameEngine;
};
#endif
