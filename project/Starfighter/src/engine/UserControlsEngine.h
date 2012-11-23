#ifndef USER_CONTROLS_ENGINE_H
#define USER_CONTROLS_ENGINE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Action.h"
#include "GameEngine.h"
#include "__enumeration__ Shooter.h"
#include "__enumeration__ Action.h"
#include "Qt/QMap.h"
#include "Qt/QKeyEvent.h"

class UserControlsEngine
{
    Q_OBJECT

private:
	Qt::QMap<int,Action> actions;

	GameEngine gameEngine;
	__enumeration__ Shooter __enumeration__ Shooter;
	__enumeration__ Action __enumeration__ Action;

protected:
	void keyPressEvent(Qt::QKeyEvent * event);

	void keyReleaseEvent(Qt::QKeyEvent * event);

public:
	void UserControlsEngine();

};
#endif
