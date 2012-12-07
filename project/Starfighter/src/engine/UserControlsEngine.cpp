#include "include/engine/UserControlsEngine.h"
#include "include/enum/Enum.h"
#include <QtGui>

UserControlsEngine::UserControlsEngine(GameEngine *ge): gameEngine(ge)
{
    //myKey = gameEngine;

    myKey[Top1];
    myKey[Bottom1];
    myKey[Shoot1];

    myKey[Top2];
    myKey[Bottom2];
    myKey[Shoot2];

    myKey[Escape];

    actions.insert(Qt::Key_W,Top1);
    actions.insert(Qt::Key_S,Bottom1);
    actions.insert(Qt::Key_E,Shoot1);

    actions.insert(Qt::Key_8,Top2);
    actions.insert(Qt::Key_2,Bottom2);
    actions.insert(Qt::Key_Enter,Shoot2);

    actions.insert(Qt::Key_Escape,Escape);

}

void UserControlsEngine::keyPressEvent(QKeyEvent * event)
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
        //gameEngine;
        break;
    }
}

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
