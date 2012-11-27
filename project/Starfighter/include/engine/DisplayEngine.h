#ifndef DISPLAY_ENGINE_H
#define DISPLAY_ENGINE_H

#include "include/game/Displayable.h"
#include "include/engine/GameEngine.h"
#include <QGraphicsView>
#include <QGraphicsScene>

class DisplayEngine
{
    Q_OBJECT
public:
    DisplayEngine(int width, int height, GameEngine *ge);
	
	QSize sceneSize();
	
private:
    QGraphicsScene *scene;
    QGraphicsView *view;

    Displayable* displayable[];
    GameEngine *gameEngine;
};
#endif
