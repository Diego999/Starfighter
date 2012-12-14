#include "include/engine/UserControlsEngine.h"
#include "include/utils/Settings.h"

#include "include/game/Spaceship.h"

#include "include/enum/Enum.h"

#include "QtGui"

#define REFRESH                10
#define NOVATIMER              10000    // (ms)


UserControlsEngine::UserControlsEngine(GameEngine *ge): gameEngine(ge), hasShoot(false)
{
    myKey = Settings::getGlobalSettings().playersControls();

    display = gameEngine->displayEngine();

    actions.insert(myKey[Top1],Top1);
    actions.insert(myKey[Bottom1],Bottom1);
    actions.insert(myKey[Shoot1],Shoot1);

    actions.insert(myKey[Top2],Top2);
    actions.insert(myKey[Bottom2],Bottom2);
    actions.insert(myKey[Shoot2],Shoot2);

    novaeCall = new QTimer(this);
    novaeCall->setSingleShot(true);
    novaeCall->start(NOVATIMER);
    startTimer(REFRESH);

    connect(novaeCall,SIGNAL(timeout()),this,SLOT(callSupernovae()));

}

void UserControlsEngine::keyPressEvent(QKeyEvent * event)
{

    Action action = actions[event->key()];

    switch(action)
    {
        case(Top1):
        actionList.append(Top1);
        break;

        case(Bottom1):
        actionList.append(Bottom1);
        break;

        case(Shoot1):
        break;

        case(Top2):
        actionList.append(Top2);
        break;

        case(Bottom2):
        actionList.append(Bottom2);
        break;

        case(Shoot2):
        break;
    }

    if((!event->isAutoRepeat() && (action == Shoot1)))
    {
        gameEngine->ship1()->attack();
        novaeCall->start(NOVATIMER);
    }

    if((!event->isAutoRepeat() && (action == Shoot2)))
    {
        gameEngine->ship2()->attack();
        novaeCall->start(NOVATIMER);
    }

}

void UserControlsEngine::keyReleaseEvent(QKeyEvent * event)
{

    Action action = actions[event->key()];

    switch(action)
    {
        case(Top1):
        actionList.removeAll(Top1);
        break;

        case(Bottom1):
        actionList.removeAll(Bottom1);
        break;

        case(Shoot1):
        break;

        case(Top2):
        actionList.removeAll(Top2);
        break;

        case(Bottom2):
        actionList.removeAll(Bottom2);
        break;

        case(Shoot2):
        break;
    }
}

void UserControlsEngine::timerEvent(QTimerEvent *event)
{
    QList<Action>::iterator values;

    for(values = actionList.begin(); values != actionList.end(); values++)
    {
        {
            switch(*values)
            {
                case(Top1):
                gameEngine->ship1()->top();
                break;

                case(Bottom1):
                gameEngine->ship1()->bottom();
                break;

                case(Shoot1):
                break;

                case(Top2):
                gameEngine->ship2()->top();
                break;

                case(Bottom2):
                gameEngine->ship2()->bottom();
                break;

                case(Shoot2):
                break;
            }
        }
    }
}

void UserControlsEngine::callSupernovae()
{
    Supernova *supernova = new Supernova(display->sceneSize().width() / 2, display->sceneSize().height() / 2, gameEngine);
    display->addSupernova(supernova);
}
