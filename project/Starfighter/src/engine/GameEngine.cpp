#include "include/engine/GameEngine.h"
#include "include/engine/DisplayEngine.h"
#include "include/engine/SpawnEngine.h"
#include "include/engine/UserControlsEngine.h"

#include "include/game/Spaceship.h"
#include "include/game/Destroyable.h"
#include "include/game/AlienSpaceship.h"
#include "include/game/Asteroid.h"
#include "include/game/BonusForceField.h"
#include "include/game/BonusHP.h"
#include "include/game/BonusProjectile.h"
#include "include/game/BonusSpeed.h"
#include "include/game/Supernova.h"

#include "include/utils/Settings.h"

GameEngine::GameEngine(GameMode gameMode, int duration, SpaceshipType player1Ship, SpaceshipType player2Ship, int difficulty, QObject *parent = 0)
    :QObject(parent),
      settings(Settings::getGlobalSettings()),isRunning(false),idTimer(-1),isTimer(false),timeGame(0),timeAlreadyCounted(0)
{
    de = new DisplayEngine(this,0);
    uc = new UserControlsEngine(this);
    se = new SpawnEngine(difficulty, this);

    mutex = new QMutex();

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    timerControle();
    createSpaceship();

    elapsedTimer.start();
}

GameEngine::~GameEngine()
{
    delete de;
    delete uc;
    delete se;
}

double GameEngine::randDouble()
{
    return (double)qrand() / (double)RAND_MAX;
}

int GameEngine::randInt(int range)
{
    if(range == 0)
        return 0;
    else
        return qrand() % range;
}

void GameEngine::createSpaceship()
{
    int width = de->sceneSize().width();
    int height = de->sceneSize().height();

    addShip(new Spaceship(0,height/2,Player1,settings.playerOneName(),5,100,100,this));//Change with the parameter of a spaceship
    addShip(new Spaceship(width,height/2,Player2,settings.playerTwoName(),5,100,100,this));
}

void GameEngine::timerEvent(QTimerEvent *event)
{
    de->updateScreen();
    if(isTimer)
        de->updateGameDataTimer();

    checkPlayerOutsideScene(listSpaceship);

    checkOutsideScene(listProjectile);
    checkOutsideScene(listAsteroide);
    checkOutsideScene(listSmallAsteroide);
    checkOutsideScene(listBonus);
    checkOutsideScene(listAlienSpaceship);

    for(int i = 0;i<listSpaceship.size();i++)
    {
        checkCollisionSpaceshipAndList(i,listProjectile);
        checkCollisionSpaceshipAndList(i,listAsteroide);
        checkCollisionSpaceshipAndList(i,listSmallAsteroide);
    }
    de->updateGameData();
    //Explode all the supernova
    for(int i = 0;i<listSupernova.size();i++)
    {
        delete listSupernova[i];
        listSupernova[i]=0;
    }
    listSupernova.clear();

    runTestCollision(listProjectile);
    clearList(listProjectile);

    runTestCollision(listAsteroide);
    runTestCollision(listSmallAsteroide);
}

int GameEngine::elapsedTime()
{
    if(elapsedTimer.isValid())
        return timeAlreadyCounted + elapsedTimer.elapsed();
    else
        return timeAlreadyCounted;
}

void GameEngine::endGameTimer()
{
    //int score1;
    //int score2;
}

void GameEngine::endGameDeathMatch(Spaceship* _ship)
{
    // get point player
    //gameEngine->spaceship;
    if(_ship==0)
    {
        QMessageBox::information(de,
                                 tr("End of the game"),
                                 tr("End of the game"),
                                 QMessageBox::Ok);
    }
    else
    {
        de->updateGameData();
        QString playerName;
        if(_ship==ship1())
            playerName = QString(ship2()->getPlayerName());
        else if(_ship==ship2())
            playerName = QString(ship1()->getPlayerName());
        QMessageBox::information(de,
                                 tr("End of the game"),
                                 QString(tr("%1 has won !")).arg(playerName),
                                 QMessageBox::Ok);
    }
}

void GameEngine::escapeGame()
{
    timerControle();

    QMessageBox messageExit;

    messageExit.setWindowTitle(tr("End of the game"));
    messageExit.setText(tr("Do you want to stop the current game ?"));
    messageExit.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageExit.setDefaultButton(QMessageBox::No);


    if(messageExit.exec() == QMessageBox::Yes)
        emit endGame();
    timerControle();
}

void GameEngine::elemenDestroyed(Destroyable* _destroyItem)
{
    if(Spaceship* s = dynamic_cast<Spaceship*>(_destroyItem))
    {
        timerControle();
        endGameDeathMatch(s);
        emit endGame();
    }
    else if(Asteroid* a = dynamic_cast<Asteroid*>(_destroyItem))
    {
        if(a->isSmall())
            removeSmallAsteroid(a);
        else
            removeAsteroid(a);
    }
    else if(AlienSpaceship* a = dynamic_cast<AlienSpaceship*>(_destroyItem))
        removeAlienSpaceship(a);
}

void GameEngine::timerControle(int tps)
{
    if(isRunning)
    {
        //qDebug() << isRunning << "Stop Timer 1:" <<idTimer;
        killTimer(idTimer);
        idTimer = -1;

        timeAlreadyCounted += elapsedTimer.elapsed();
        elapsedTimer.invalidate();

        //qDebug() << isRunning<< "Stop Timer 2:" <<idTimer;
        emit signalPause(true);
    }

    else
    {
        idTimer = startTimer(tps);
        //qDebug() << isRunning<< "startTimer:" <<idTimer;

        elapsedTimer.start();

        emit signalPause(false);
    }
    isRunning = !isRunning;
}

void GameEngine::gameType()
{
    if(isTimer)
        de->enableTimerData();
}

void GameEngine::addProjectile(Projectile * _inProjectile)
{
    de->addItemScene(_inProjectile);
    listProjectile.append(_inProjectile);
}

void GameEngine::addShip(Spaceship *_inSpaceship)
{

    de->addItemScene(_inSpaceship);
    listSpaceship.append(_inSpaceship);
    connect(_inSpaceship,SIGNAL(destroyed(Destroyable*)),this,SLOT(elemenDestroyed(Destroyable*)));
}

void GameEngine::removeShip(Spaceship *_inSpaceship)
{
    int l_index = listSpaceship.indexOf(_inSpaceship);
    if(l_index!=-1)
    {
        delete listSpaceship[l_index];
        listSpaceship[l_index]=0;
    }
}

void GameEngine::addBonus(Bonus *_inBonus)
{
    de->addItemScene(_inBonus);
    listBonus.append(_inBonus);
}

void GameEngine::addAsteroid(Asteroid *_inAsteroid)
{
    de->addItemScene(_inAsteroid);
    listAsteroide.append(_inAsteroid);
    connect(_inAsteroid,SIGNAL(destroyed(Destroyable*)),this,SLOT(elemenDestroyed(Destroyable*)));
}

void GameEngine::addSmallAsteroid(Asteroid *_inAsteroid)
{
    de->addItemScene(_inAsteroid);
    listSmallAsteroide.append(_inAsteroid);
    connect(_inAsteroid,SIGNAL(destroyed(Destroyable*)),this,SLOT(elemenDestroyed(Destroyable*)));
}

void GameEngine::addAlienSpaceship(AlienSpaceship *_inAlienSpaceship)
{
    de->addItemScene(_inAlienSpaceship);
    listAlienSpaceship.append(_inAlienSpaceship);
    connect(_inAlienSpaceship,SIGNAL(destroyed(Destroyable*)),this,SLOT(elemenDestroyed(Destroyable*)));
}

void GameEngine::addSupernova(Supernova *_inSupernova)
{
    listSupernova.append(_inSupernova);
}

void GameEngine::removeAlienSpaceship(AlienSpaceship *_inAlienSpaceship)
{
    int l_index = listAlienSpaceship.indexOf(_inAlienSpaceship);
    if(l_index!=-1)
    {
        delete listAlienSpaceship[l_index];
        listAlienSpaceship[l_index]=0;
    }
}

void GameEngine::removeAsteroid(Asteroid *_inAsteroide)
{
    int l_index = listAsteroide.indexOf(_inAsteroide);
    if(l_index!=-1)
    {
        delete listAsteroide[l_index];
        listAsteroide[l_index]=0;
    }
}

void GameEngine::removeSmallAsteroid(Asteroid *_inAsteroide)
{
    int l_index = listSmallAsteroide.indexOf(_inAsteroide);
    if(l_index!=-1)
    {
        delete listSmallAsteroide[l_index];
        listSmallAsteroide[l_index]=0;
    }
}

void GameEngine::clearList(QList<Displayable*> &list)
{
    for(int i = 0;i<list.size();i++)
      if(list[i]==0)
          list.removeAt(i--);
}

void GameEngine::checkOutsideScene(QList<Displayable*> &list)
{
    for(int i = 0;i<list.size();i++)
    {
        int l_w = 0;
        int l_h = 0;

        if(list[i]==0)
            continue;
        QMutexLocker l(mutex);
        if(list[i]->isPixmap())
        {
            l_w = list[i]->sizePixmap().width();
            l_h = list[i]->sizePixmap().height();
        }

        if(list[i]->pos().x()-l_w > de->sceneSize().width() || list[i]->pos().x()+l_w < 0
        || list[i]->pos().y() > de->sceneSize().height() || list[i]->pos().y()+l_h < 0)
            {
                delete list[i];
                list[i] = 0;
            }
    }

    clearList(list);
}

void GameEngine::checkPlayerOutsideScene(QList<Spaceship*> &list)
{
    for(int i = 0;i < list.size();i++)
        if(list[i]->pos().y()+list[i]->sizePixmap().height() > de->sceneSize().height())
            list[i]->top();
        else if(list[i]->pos().y() < 0)
            list[i]->bottom();
}

bool GameEngine::checkCollisionItemAndList(const int i_list1,QList<Displayable*> &list1,QList<Displayable*> &list2)
{

    if(list2.size()==0 || list1.size()==0)
        return false;
    if(list2[0] == 0 || list1[i_list1]==0)
        return false;

    QMutexLocker l(mutex);
    if(list2[0]->getTypeObject() == tAlien && (list1[i_list1]->getTypeObject() == tProj))
        if(Projectile* p = dynamic_cast<Projectile*>(list1[i_list1]))
            if(p->getFrom()==Alien)
                return false;

    for(int j = 0;j<list2.size();j++)
    {
        if(list2[j]==0)
            continue;
        if(list1[i_list1] != list2[j] && list1[i_list1]->collidesWithItem(list2[j],Qt::IntersectsItemShape))
        {
            if(list1[i_list1]->getTypeObject() == tProj)
            {
                if(Destroyable* d = dynamic_cast<Destroyable*>(list2[j]))
                {
                    d->receiveAttack(list1[i_list1]->getPower());
                    delete list1[i_list1];
                    list1[i_list1] = 0;

                    return false;
                }
                else if(Bonus* b = dynamic_cast<Bonus*>(list2[j]))
                {
                    Projectile* p = dynamic_cast<Projectile*>(list1[i_list1]);

                    //We don't delete the pointer here, it'll be deleted in the class spaceship
                    //We only remove the item from the list
                    list2[j] = 0;
                    de->removeItemScene(b);

                    if(p->getFrom() == Player1)
                        ship1()->addBonus(b);
                    else if(p->getFrom() == Player2)
                        ship2()->addBonus(b);

                    delete list1[i_list1];
                    list1[i_list1]=0;

                    return true;
                }
            }
            else if(list1[i_list1]->getTypeObject() == tAlien)
            {
                if(Destroyable* d = dynamic_cast<Destroyable*>(list1[i_list1]))
                {
                    d->receiveAttack(list2[j]->getPower());
                    delete list2[j];
                    list2[j] = 0;

                    return false;
                }
            }

            delete list1[i_list1];
            list1[i_list1] = 0;

            if(list1!=list2)
            {
                delete list2[j];
                list2[j] = 0;
            }
            return true;
        }
    }

    return false;
}

bool GameEngine::checkCollisionSpaceshipAndList(const int i,QList<Displayable*> &list)
{
    if(list.size()==0 || listSpaceship.size()==0)
        return false;

    for(int j = 0;j<list.size();j++)
    {
        QMutexLocker* l = new QMutexLocker(mutex);
        if(list[j]==0)
        {
            delete l;
            return false;
        }

        if(listSpaceship[i]->collidesWithItem(list[j],Qt::IntersectsItemShape))
        {
            listSpaceship[i]->receiveAttack(list[j]->getPower());
            if(l->mutex()!=0)
            {
                delete list[j];
                list[j] = 0;
                clearList(list);
                delete l;
            }

            return true;
        }
        else
            delete l;
    }

    return false;
}

void GameEngine::runTestCollision(QList<Displayable*> &list)
{
    for(int i = 0;i<list.size();i++)
    {
        if(checkCollisionItemAndList(i,list,listAsteroide)
        || checkCollisionItemAndList(i,list,listSmallAsteroide)
        || checkCollisionItemAndList(i,list,listBonus)
        || checkCollisionItemAndList(i,list,listAlienSpaceship))
            continue;
    }
    clearList(listAsteroide);
    clearList(listSmallAsteroide);
    clearList(listBonus);
    clearList(listAlienSpaceship);
}
