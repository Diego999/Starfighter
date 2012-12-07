#include "include/engine/UserControlsEngine.h"
#include "include/utils/Settings.h"

#include "include/game/Spaceship.h"

#include "include/enum/Enum.h"
#include <QtGui>


UserControlsEngine::UserControlsEngine(GameEngine *ge): gameEngine(ge)
{
    myKey = Settings::getGlobalSettings().playersControls();

    actions.insert(myKey[Top1],Top1);
    actions.insert(myKey[Bottom1],Bottom1);
    actions.insert(myKey[Shoot1],Shoot1);

    actions.insert(myKey[Top2],Top2);
    actions.insert(myKey[Bottom2],Bottom2);
    actions.insert(myKey[Escape],Shoot2);

    actions.insert(Qt::Key_Escape,Escape);

}

void UserControlsEngine::keyPressEvent(QKeyEvent * event)
{
    Action action = actions[event->key()];

    switch(action)
    {
        case(Top1):
        gameEngine->ship1()->top();
        break;

        case(Bottom1):
        gameEngine->ship1()->bottom();
        break;

        case(Shoot1):
        gameEngine->ship1()->attack();
        break;

        case(Top2):
        gameEngine->ship2()->top();
        break;

        case(Bottom2):
        gameEngine->ship2()->bottom();
        break;

        case(Shoot2):
        gameEngine->ship2()->attack();
        break;

        case(Escape):
        //gameEngine;
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
