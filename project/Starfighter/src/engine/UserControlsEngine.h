#ifndef USER_CONTROLS_ENGINE_H
#define USER_CONTROLS_ENGINE_H


#include "../enum/Enum.h"
#include "GameEngine.h"
#include "Qt/QMap.h"
#include "Qt/QKeyEvent.h"

class UserControlsEngine
{
    Q_OBJECT

public:
	void UserControlsEngine();
	
protected:
	void keyPressEvent(Qt::QKeyEvent * event);
	void keyReleaseEvent(Qt::QKeyEvent * event);

private:
	QMap<int,Action> actions;
	GameEngine gameEngine;
};
#endif
