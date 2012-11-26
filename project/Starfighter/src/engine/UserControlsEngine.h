#ifndef USER_CONTROLS_ENGINE_H
#define USER_CONTROLS_ENGINE_H


#include "../enum/Enum.h"
#include "GameEngine.h"
#include "QMap.h"
#include "QKeyEvent"

class UserControlsEngine
{
    Q_OBJECT

public:
    UserControlsEngine();
	
protected:
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

private:
	QMap<int,Action> actions;
    //GameEngine gameEngine;
};
#endif
