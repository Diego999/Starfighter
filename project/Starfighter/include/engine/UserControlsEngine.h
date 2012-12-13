#ifndef USER_CONTROLS_ENGINE_H
#define USER_CONTROLS_ENGINE_H


#include "include/enum/Enum.h"
#include "include/engine/GameEngine.h"

#include "QKeyEvent"

class UserControlsEngine : public QObject
{
    Q_OBJECT

public:
    UserControlsEngine(GameEngine *ge);

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

    void timerEvent(QTimerEvent *event);



private:
    QMap<int,Action>        actions;
    QMap<Action,Qt::Key>    myKey;
    GameEngine *            gameEngine;
    QList<Action>           actionList;


};
#endif
