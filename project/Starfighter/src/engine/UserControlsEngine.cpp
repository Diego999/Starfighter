#include "include/engine/UserControlsEngine.h"
#include "include/utils/Settings.h"

#include "include/game/Spaceship.h"

#include "include/enum/Enum.h"
#include <QtGui>
#include <QDebug>

UserControlsEngine::UserControlsEngine(GameEngine *ge): gameEngine(ge)
{
    myKey = Settings::getGlobalSettings().playersControls();

    actions.insert(myKey[Top1],Top1);
    actions.insert(myKey[Bottom1],Bottom1);
    actions.insert(myKey[Shoot1],Shoot1);

    actions.insert(myKey[Top2],Top2);
    actions.insert(myKey[Bottom2],Bottom2);
    actions.insert(myKey[Escape],Shoot2);
}

void UserControlsEngine::keyPressEvent(QKeyEvent * event)
{
    Action action = actions[event->key()];

    qDebug() << event->key();
    switch(action)
    {
        case(Top1):
        qDebug() << "T1";
        gameEngine->ship1()->top();
        break;

        case(Bottom1):
        qDebug() << "B1";
        gameEngine->ship1()->bottom();
        break;

        case(Shoot1):
        qDebug() << "S1";
        gameEngine->ship1()->attack();
        break;

        case(Top2):
        qDebug() << "T2";
        gameEngine->ship2()->top();
        break;

        case(Bottom2):
        qDebug() << "B2";
        gameEngine->ship2()->bottom();
        break;

        case(Shoot2):
        qDebug() << "S2";
        gameEngine->ship2()->attack();
        break;
    }
}

/*
void UserControlsEngine::keyReleaseEvent(QKeyEvent * event)
{

    Action action = actions[event->key()];

    switch(action)
    {
        case(Top1):
        //gameEngine;
        break;

        case(Bottom1):
        //gameEngine;
        break;

        case(Shoot1):
        //gameEngine;
        break;

        case(Top2):
        //gameEngine;
        break;

        case(Bottom2):
        //gameEngine;
        break;

        case(Shoot2):
        //gameEngine;
        break;

        case(Escape):
        break;
    }

}
*/
