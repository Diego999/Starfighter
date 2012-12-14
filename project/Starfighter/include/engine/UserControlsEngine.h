#ifndef USER_CONTROLS_ENGINE_H
#define USER_CONTROLS_ENGINE_H


#include "include/enum/Enum.h"
#include "include/engine/GameEngine.h"
#include "include/engine/DisplayEngine.h"
#include "include/game/Supernova.h"

#include "QKeyEvent"

class UserControlsEngine : public QObject
{
    Q_OBJECT

public:
    UserControlsEngine(GameEngine *ge);
    ~UserControlsEngine();

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

    void timerEvent(QTimerEvent *event);



public slots:
    void callSupernovae();

private:
    QMap<int,Action>        actions;
    QMap<Action,Qt::Key>    myKey;
    GameEngine *            gameEngine;
    DisplayEngine *         display;
    QList<Action>           actionList;
    QTimer *                novaeCall;

    bool hasShoot;


};
#endif
