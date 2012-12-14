#include "include/engine/DisplayEngine.h"
#include "include/engine/UserControlsEngine.h"

#include "include/game/Displayable.h"
#include "include/game/Projectile.h"
#include "include/game/Spaceship.h"
#include "include/game/Obstacle.h"
#include "include/game/Bonus.h"
#include "include/game/Asteroid.h"
#include "include/game/AlienSpaceship.h"
#include "include/game/Supernova.h"

#include "include/utils/Settings.h"

#include "include/enum/Enum.h"

#include <QList>
#include <QMutex>

#define SPACE_BETWEEN         250
#define SPACE_INPLAYER        50
#define BACKGROUND "background/black hole.png"

//DisplayEngine::DisplayEngine(QWidget *parent) : QWidget(parent), isFullScreen(true)
DisplayEngine::DisplayEngine(GameEngine *ge, QWidget *parent): QWidget(parent), gameEngine(ge), isFullScreen(true), isTimer(false)
{

    // get screen dimension
    QDesktopWidget * desktop = QApplication::desktop();

    //screenSizeHeight = 900;
    screenSizeHeight = desktop->height();

    //screenSizeWidth = 1440;
    screenSizeWidth = desktop->width();

    sceneWidth = screenSizeWidth;
    sceneHeigth = screenSizeHeight*0.85;
    //double sceneHeigth = screenSizeHeight;

    QVBoxLayout * mainScreen = new QVBoxLayout(this);
    //QGridLayout * mainScreen = new QGridLayout(this);

    downHUD = new QWidget(this);

    // configuration of QGraphicsScene and QGraphicsview
    scene = new QGraphicsScene(0,0,sceneWidth,sceneHeigth,this);
    view = new QGraphicsView(scene,this);

    view->setFixedSize(sceneWidth,sceneHeigth);

    view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    view->viewport()->setFocusProxy( this );
    view->setFocusPolicy(Qt::NoFocus);

    // Set background
    QPixmap bg( BACKGROUND );
    //scene->setBackgroundBrush(bg);
    scene->setBackgroundBrush(Qt::black);
    this->setFixedSize(screenSizeWidth,screenSizeHeight);

    this->setWindowModality(Qt::ApplicationModal);
    // Param of the screen
    showFullScreen();
    //setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint);
    view->move(0,0);

    mainScreen->setMargin(0);
    mainScreen->setSpacing(0);

    mainScreen->addWidget(view);
    mainScreen->addWidget(downHUD);

    affiche = new QTime();
    affiche->setHMS(0,0,0,0);

    this->creatHUD();
    this->gameType();

    setLayout(mainScreen);
    mutex = new QMutex();
}

DisplayEngine::~DisplayEngine()
{
    delete mainPart;
}

void DisplayEngine::creatHUD()
{

    QHBoxLayout * downPart = new QHBoxLayout(downHUD);

    /**
      * Player no1 part
      */
    QHBoxLayout * playerOneNamu = new QHBoxLayout();
    QLabel * player1Name = new QLabel();
    //player1Name->setText("Name: player1");
    player1Name->setText(tr("Name : %1").arg(Settings::getGlobalSettings().playerOneName()));
    playerOneNamu->addWidget(player1Name);


    QVBoxLayout * statuePlayerOne = new QVBoxLayout();

    QHBoxLayout * heathP1 = new QHBoxLayout();
    QLabel * lHP1 = new QLabel("HP:\t");
    HP1= new QProgressBar();
    HP1->setRange(0,100);
    HP1->setValue(100);

    heathP1->addWidget(lHP1);
    heathP1->addWidget(HP1);

    QHBoxLayout * shildP1 = new QHBoxLayout();
    QLabel * lShild1 = new QLabel("Shield:\t");
    shield1= new QProgressBar();
    shield1->setRange(0,100);
    shield1->setValue(100);

    shildP1->addWidget(lShild1);
    shildP1->addWidget(shield1);

    // Add all layout status
    statuePlayerOne->addLayout(heathP1);
    statuePlayerOne->addLayout(shildP1);

    QHBoxLayout * bonusPlayerOne = new QHBoxLayout();

    /**
      * Timer and point counter
      */
    QVBoxLayout * timeAndScore   = new QVBoxLayout();
    QHBoxLayout * score = new QHBoxLayout();
    timer = new QLCDNumber();
    timer->setDigitCount(5);

    scoreP1 = new QLCDNumber();
    scoreP2 = new QLCDNumber();

    scoreP1->setDigitCount(2);
    scoreP2->setDigitCount(2);
    score->addWidget(scoreP1);
    score->addWidget(new QLabel(":"));
    score->addWidget(scoreP2);

    timeAndScore->addWidget(timer);
    timeAndScore->addLayout(score);

    /**
      * Player no2 part
      */
    QHBoxLayout * playerTwoNamu = new QHBoxLayout();
    QLabel * player2Name = new QLabel();
    //player2Name->setText("Name: player2");
    player2Name->setText(tr("Name : %1").arg(Settings::getGlobalSettings().playerTwoName()));
    playerTwoNamu->addWidget(player2Name);

    QVBoxLayout * statuePlayerTwo = new QVBoxLayout();

    QHBoxLayout * heathP2 = new QHBoxLayout();
    QLabel * lHP2 = new QLabel("HP:\t");
    HP2= new QProgressBar();
    HP2->setRange(0,100);
    HP2->setValue(100);

    heathP2->addWidget(lHP2);
    heathP2->addWidget(HP2);

    QHBoxLayout * shildP2 = new QHBoxLayout();
    QLabel * lShild2 = new QLabel("Shield:\t");
    shield2= new QProgressBar();
    shield2->setRange(0,100);
    shield2->setValue(100);

    shildP2->addWidget(lShild2);
    shildP2->addWidget(shield2);

    // Add all layout status
    statuePlayerTwo->addLayout(heathP2);
    statuePlayerTwo->addLayout(shildP2);

    QHBoxLayout * bonusPlayerTwo = new QHBoxLayout();

    downPart->addLayout(playerOneNamu);
    downPart->addSpacing(SPACE_INPLAYER);
    downPart->addLayout(statuePlayerOne);
    downPart->addSpacing(SPACE_INPLAYER);
    downPart->addLayout(bonusPlayerOne);
    downPart->addSpacing(SPACE_BETWEEN);
    downPart->addLayout(timeAndScore);
    downPart->addSpacing(SPACE_BETWEEN);
    downPart->addLayout(playerTwoNamu);
    downPart->addSpacing(SPACE_INPLAYER);
    downPart->addLayout(statuePlayerTwo);
    downPart->addSpacing(SPACE_INPLAYER);
    downPart->addLayout(bonusPlayerTwo);

    //scene->setSceneRect(0,0,screenSizeWidth,screenSizeHeight);
    //downHUD->move(0,screenSizeHeight-125);
}

void DisplayEngine::updateScreen()
{
    scene->advance();
}

void DisplayEngine::addProjectile(Projectile * _inProjectile)
{
    scene->addItem(_inProjectile);
    listProjectile.append(_inProjectile);
}

void DisplayEngine::addShip(Spaceship *_inSpaceship)
{
    scene->addItem(_inSpaceship);
    listSpaceship.append(_inSpaceship);
    connect(_inSpaceship,SIGNAL(destroyed(Destroyable*)),gameEngine,SLOT(elemenDestroyed(Destroyable*)));
}

void DisplayEngine::removeShip(Spaceship *_inSpaceship)
{
    int l_index = listSpaceship.indexOf(_inSpaceship);
    if(l_index!=-1)
    {
        delete listSpaceship[l_index];
        listSpaceship[l_index]=0;
    }
}

void DisplayEngine::addBonus(Bonus *_inBonus)
{
    scene->addItem(_inBonus);
    listBonus.append(_inBonus);
}

void DisplayEngine::addAsteroid(Asteroid *_inAsteroid)
{
    scene->addItem(_inAsteroid);
    listAsteroide.append(_inAsteroid);
    connect(_inAsteroid,SIGNAL(destroyed(Destroyable*)),gameEngine,SLOT(elemenDestroyed(Destroyable*)));
}

void DisplayEngine::addSmallAsteroid(Asteroid *_inAsteroid)
{
    scene->addItem(_inAsteroid);
    listSmallAsteroide.append(_inAsteroid);
    connect(_inAsteroid,SIGNAL(destroyed(Destroyable*)),gameEngine,SLOT(elemenDestroyed(Destroyable*)));
}

void DisplayEngine::addAlienSpaceship(AlienSpaceship *_inAlienSpaceship)
{
    scene->addItem(_inAlienSpaceship);
    listAlienSpaceship.append(_inAlienSpaceship);
    connect(_inAlienSpaceship,SIGNAL(destroyed(Destroyable*)),gameEngine,SLOT(elemenDestroyed(Destroyable*)));
}

void DisplayEngine::addSupernova(Supernova *_inSupernova)
{
    //scene->addItem(_inSupernova);
    listSupernova.append(_inSupernova);
}

void DisplayEngine::removeAlienSpaceship(AlienSpaceship *_inAlienSpaceship)
{
    int l_index = listAlienSpaceship.indexOf(_inAlienSpaceship);
    if(l_index!=-1)
    {
        delete listAlienSpaceship[l_index];
        listAlienSpaceship[l_index]=0;  
    }
}

void DisplayEngine::removeAsteroid(Asteroid *_inAsteroide)
{
    int l_index = listAsteroide.indexOf(_inAsteroide);
    if(l_index!=-1)
    {   
        delete listAsteroide[l_index];
        listAsteroide[l_index]=0;
    }
}

void DisplayEngine::removeSmallAsteroid(Asteroid *_inAsteroide)
{
    int l_index = listSmallAsteroide.indexOf(_inAsteroide);
    if(l_index!=-1)
    {  
        delete listSmallAsteroide[l_index];
        listSmallAsteroide[l_index]=0;
    }
}

/*void DisplayEngine::paintEvent(QPaintEvent * event)
{

    scene->advance();

}
*/

void DisplayEngine::clearList(QList<Displayable*> &list)
{
    for(int i = 0;i<list.size();i++)
      if(list[i]==0)
          list.removeAt(i--);
}

void DisplayEngine::checkOutsideScene(QList<Displayable*> &list)
{

    //list[] -> O(1)

    for(int i = 0;i<list.size();i++)
    {
        int l_w = 0;
        int l_h = 0;

        if(list[i]==0)
            continue;
        mutex->lock();
        if(list[i]->isPixmap())
        {
            l_w = list[i]->sizePixmap().width();
            l_h = list[i]->sizePixmap().height();
        }

        if(list[i]->pos().x()-l_w > screenSizeWidth || list[i]->pos().x()+l_w < 0
        || list[i]->pos().y() > screenSizeHeight || list[i]->pos().y()+l_h < 0)
            {
                delete list[i];
                list[i] = 0;
            }
        mutex->unlock();
    }

    clearList(list);
}

void DisplayEngine::checkPlayerOutsideScene(QList<Spaceship*> &list)
{
    mutex->lock();
    for(int i = 0;i < list.size();i++)
        if(list[i]->pos().y()+list[i]->sizePixmap().height() > screenSizeHeight)
            list[i]->top();
        else if(list[i]->pos().y() < 0)
            list[i]->bottom();
    mutex->unlock();
}

bool DisplayEngine::checkCollisionItemAndList(const int i_list1,QList<Displayable*> &list1,QList<Displayable*> &list2)
{

    if(list2.size()==0 || list1.size()==0)
        return false;
    if(list2[0] == 0 || list1[i_list1]==0)
        return false;

    mutex->lock();
    if(list2[0]->getTypeObject() == tAlien && (list1[i_list1]->getTypeObject() == tProj))
        if(Projectile* p = dynamic_cast<Projectile*>(list1[i_list1]))
            if(p->getFrom()==Other)
            {
                mutex->unlock();
                return false;
            }
    mutex->unlock();

    for(int j = 0;j<list2.size();j++)
    {
        if(list2[j]==0)
            continue;
        mutex->lock();
        if(list1[i_list1] != list2[j] && list1[i_list1]->collidesWithItem(list2[j],Qt::IntersectsItemShape))
        {
            if(list1[i_list1]->getTypeObject() == tProj)
            {
                if(Destroyable* d = dynamic_cast<Destroyable*>(list2[j]))
                {
                    d->receiveAttack(list1[i_list1]->getPower());
                    delete list1[i_list1];
                    list1[i_list1] = 0;

                    mutex->unlock();
                    return false;
                }
            }
            else if(list1[i_list1]->getTypeObject() == tAlien)
            {
                if(Destroyable* d = dynamic_cast<Destroyable*>(list1[i_list1]))
                {
                    d->receiveAttack(list2[j]->getPower());
                    delete list2[j];
                    list2[j] = 0;

                    mutex->unlock();
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
            mutex->unlock();
            return true;
        }
        mutex->unlock();
    }

    return false;
}

bool DisplayEngine::checkCollisionSpaceshipAndList(const int i,QList<Displayable*> &list)
{
    if(list.size()==0 || listSpaceship.size()==0)
        return false;

    for(int j = 0;j<list.size();j++)
    {
        mutex->lock();
        if(list[j]==0)
        {
            mutex->unlock();
            return false;
        }

        if(listSpaceship[i]->collidesWithItem(list[j],Qt::IntersectsItemShape))
        {
            listSpaceship[i]->receiveAttack(list[j]->getPower());
            delete list[j];
            list[j] = 0;
            clearList(list);
            mutex->unlock();
            return true;
        }
        mutex->unlock();
    }

    return false;
}

void DisplayEngine::runTestCollision(QList<Displayable*> &list)
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

void DisplayEngine::timerEvent(QTimerEvent * event)
{
    scene->advance();

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

    if(isTimer)
    {
        this->updateGameData();
    }
}

QRect DisplayEngine::sceneSize() const
{
    return QRect(0,0,scene->width(),scene->height());
}

qreal DisplayEngine::xminWarzone() const
{
    return gameEngine->ship1()->sizePixmap().width()*2;
}

qreal DisplayEngine::xmaxWarZone() const
{
    return sceneWidth-2*(gameEngine->ship2()->sizePixmap().width());
}

void DisplayEngine::recoveryTime()
{
    //gameEngine->

}

void DisplayEngine::gameType()
{
    // si juste alors active le timer
    //if(gameEngine->)
    if(isTimer)
    {
        //startTimer(500);
        timer->setEnabled(true);
        scoreP1->setEnabled(true);
        scoreP2->setEnabled(true);
    }
}

void DisplayEngine::setProgressHP1(int _value)
{
    HP1->setValue(_value);
}

void DisplayEngine::setProgressHP2(int _value)
{
    HP2->setValue(_value);
}

void DisplayEngine::setProgressShield1(int _value)
{
    shield1->setValue(_value);
}

void DisplayEngine::setProgressShield2(int _value)
{
    shield2->setValue(_value);
}

void DisplayEngine::setGameScore1(int _value)
{
    scoreP1->display(_value);
}

void DisplayEngine::setGameScore2(int _value)
{
    scoreP2->display(_value);
}

void DisplayEngine::updateGameData()
{
    int deltaTime = gameEngine->timeGamevalue() - gameEngine->elapsedTime();

    timer->display(affiche->toString("mm:ss"));

    if(deltaTime <= 0)
    {
        this->endGameTimer();
    }
}

void DisplayEngine::endGameTimer()
{
    int score1;
    int score2;
}

void DisplayEngine::endGame(Spaceship* _ship)
{
    // get point player
    //gameEngine->spaceship;
    if(_ship==0)
    {
        QMessageBox::information(this,
                                 "Fin de partie",
                                 tr("Fin de partie"),
                                 QMessageBox::Ok);
    }
    else
    {
        QString playerName;
        if(_ship==gameEngine->ship1())
            playerName = QString(gameEngine->ship1()->getPlayerName());
        else if(_ship==gameEngine->ship2())
            playerName = QString(gameEngine->ship2()->getPlayerName());
        QMessageBox::information(this,
                                 "Fin de partie",
                                 QString(tr("Le joueur %1 a gagn� !")).arg(playerName),
                                 QMessageBox::Ok);
        gameEngine->timerControle();
    }
}

void DisplayEngine::escapeGame()
{
    gameEngine->timerControle();

    QMessageBox messageExit;

    messageExit.setWindowTitle("Fin de partie");
    messageExit.setText(tr("Voulez-vous arr�ter la partie?"));
    messageExit.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    messageExit.setDefaultButton(QMessageBox::No);


    if(messageExit.exec() == QMessageBox::Yes)
    {
        this->close();
    }
     gameEngine->timerControle();
}

void DisplayEngine::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_F12:
        this->switchFullScreen();
        break;

        case Qt::Key_Escape:
        this->escapeGame();
        break;

        default:
        gameEngine->userControlsEngine()->keyPressEvent(event);
        break;
    }

}

void DisplayEngine::keyReleaseEvent(QKeyEvent * event)
{
    gameEngine->userControlsEngine()->keyReleaseEvent(event);
}

void DisplayEngine::switchFullScreen()
{
    if(isFullScreen)
    {
        // Param of the screen
        showFullScreen();
    }

    else
    {
        showMaximized();
    }

    isFullScreen = !isFullScreen;
}
