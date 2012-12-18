#include "include/engine/DisplayEngine.h"
#include "include/engine/UserControlsEngine.h"
#include "include/engine/GameEngine.h"

#include "include/game/Displayable.h"
#include "include/game/Spaceship.h"

#include "include/utils/Settings.h"
#include "include/config/Define.h"

DisplayEngine::DisplayEngine(GameEngine *ge, QWidget *parent)
    :QWidget(parent),
      gameEngine(ge), isFullScreen(true), isTimer(false)
{
    // get screen dimension
    QDesktopWidget * desktop = QApplication::desktop();

    int screenSizeHeight = desktop->screenGeometry(this).height();
    int screenSizeWidth = desktop->screenGeometry(this).width();

    int sceneWidth = screenSizeWidth;
    int sceneHeigth = screenSizeHeight*0.85;

    QVBoxLayout * mainScreen = new QVBoxLayout(this);
    //QGridLayout * mainScreen = new QGridLayout(this);

    downHUD = new QWidget(this);

    // configuration of QGraphicsScene and QGraphicsview
    scene = new QGraphicsScene(0,0,sceneWidth,sceneHeigth,this);
    view = new QGraphicsView(scene,this);

    view->setFixedSize(sceneWidth,sceneHeigth);

    view->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers),this));

    //Better performance if we don't use random access in the scene.
    //It's the case because we use QList for Item process
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);

    view->viewport()->setFocusProxy( this );
    view->setFocusPolicy(Qt::NoFocus);

    // Set background
    QPixmap bg( BACKGROUND );//TODO
    //scene->setBackgroundBrush(bg);
    scene->setBackgroundBrush(Qt::black);
    this->setFixedSize(screenSizeWidth,screenSizeHeight);

    this->setWindowModality(Qt::ApplicationModal);
    // Param of the screen
    //showFullScreen();
    switchFullScreen();
    //setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint);
    view->move(0,0);

    mainScreen->setMargin(0);
    mainScreen->setSpacing(0);

    mainScreen->addWidget(view);
    mainScreen->addWidget(downHUD);

    //pixSpeed = new QPixmap("");
    //pixProj = new QPixmap("");
    //pixHP = new QPixmap("");

    affiche = new QTime();
    affiche->setHMS(0,0,0,0);

    setLayout(mainScreen);

    this->creatHUD();
}

DisplayEngine::~DisplayEngine()
{
    scene->clear();
    //Must clear the list in GameEngine

    delete bonusPlayerOne;
    delete bonusPlayerTwo;
    delete affiche;
    //All Layout,QLabel,QLCDNumber,QProgressbar delete with parent of QWidget

    //GameEnfine call ~DisplayEngine
}

void DisplayEngine::creatHUD()
{

    imSpeed1 = new QLabel(this);
    //imSpeed1->setPixmap(*pixSpeed);
    lBSpeed1 = new QLabel(this);

    imHP1 = new QLabel(this);
    //imHP1->setPixmap(*pixHP);
    lBHP1 = new QLabel(this);

    imProj1 = new QLabel(this);
    //imProj1->setPixmap(*pixProj);
    lBProjectile1 = new QLabel(this);

    imSpeed2 = new QLabel(this);
    //imSpeed2->setPixmap(*pixSpeed);
    lBSpeed2 = new QLabel(this);

    imHP2 = new QLabel(this);
    //imHP2->setPixmap(*pixHP);
    lBHP2 = new QLabel(this);

    imProj2 = new QLabel(this);
    //imProj2->setPixmap(*pixProj);
    lBProjectile2 = new QLabel(this);


    QHBoxLayout * downPart = new QHBoxLayout(downHUD);

    /**
      * Player no1 part
      */
    QHBoxLayout * playerOneNamu = new QHBoxLayout();
    QLabel * player1Name = new QLabel(downHUD);
    //player1Name->setText("Name: player1");
    player1Name->setText(tr("Name : %1").arg(Settings::getGlobalSettings().playerOneName()));
    playerOneNamu->addWidget(player1Name);


    QVBoxLayout * statuePlayerOne = new QVBoxLayout();

    QHBoxLayout * heathP1 = new QHBoxLayout();
    QLabel * lHP1 = new QLabel(tr("HP:\t"),downHUD);
    HP1= new QProgressBar(downHUD);
    HP1->setRange(0,100);
    HP1->setValue(100);

    heathP1->addWidget(lHP1);
    heathP1->addWidget(HP1);

    QHBoxLayout * shildP1 = new QHBoxLayout();
    QLabel * lShild1 = new QLabel(tr("Shield:\t"),downHUD);
    shield1= new QProgressBar(downHUD);
    shield1->setRange(0,100);
    shield1->setValue(100);

    shildP1->addWidget(lShild1);
    shildP1->addWidget(shield1);

    // Add all layout status
    statuePlayerOne->addLayout(heathP1);
    statuePlayerOne->addLayout(shildP1);

    bonusPlayerOne = new QGridLayout();

    bonusPlayerOne->addWidget(imSpeed1,0,0,Qt::AlignHCenter);
    bonusPlayerOne->addWidget(lBSpeed1,0,1,Qt::AlignHCenter);

    bonusPlayerOne->addWidget(imHP1,3,0,Qt::AlignHCenter);
    bonusPlayerOne->addWidget(lBHP1,3,1,Qt::AlignHCenter);

    bonusPlayerOne->addWidget(imProj1,5,0,Qt::AlignHCenter);
    bonusPlayerOne->addWidget(lBProjectile1,5,1,Qt::AlignHCenter);

    /**
      * Timer and point counter
      */
    QVBoxLayout * timeAndScore   = new QVBoxLayout();
    QHBoxLayout * score = new QHBoxLayout();
    timer = new QLCDNumber(downHUD);
    timer->setDigitCount(5);

    scoreP1 = new QLCDNumber(downHUD);
    scoreP2 = new QLCDNumber(downHUD);

    scoreP1->setDigitCount(2);
    scoreP2->setDigitCount(2);
    score->addWidget(scoreP1);
    score->addWidget(new QLabel(tr(":")));
    score->addWidget(scoreP2);

    timeAndScore->addWidget(timer);
    timeAndScore->addLayout(score);

    /**
      * Player no2 part
      */
    QHBoxLayout * playerTwoNamu = new QHBoxLayout();
    QLabel * player2Name = new QLabel(downHUD);
    //player2Name->setText("Name: player2");
    player2Name->setText(tr("Name : %1").arg(Settings::getGlobalSettings().playerTwoName()));
    playerTwoNamu->addWidget(player2Name);

    QVBoxLayout * statuePlayerTwo = new QVBoxLayout();

    QHBoxLayout * heathP2 = new QHBoxLayout();
    QLabel * lHP2 = new QLabel(tr("HP:\t"),downHUD);
    HP2= new QProgressBar(downHUD);
    HP2->setRange(0,100);
    HP2->setValue(100);

    heathP2->addWidget(lHP2);
    heathP2->addWidget(HP2);

    QHBoxLayout * shildP2 = new QHBoxLayout();
    QLabel * lShild2 = new QLabel(tr("Shield:\t"),downHUD);
    shield2= new QProgressBar(downHUD);
    shield2->setRange(0,100);
    shield2->setValue(100);

    shildP2->addWidget(lShild2);
    shildP2->addWidget(shield2);

    // Add all layout status
    statuePlayerTwo->addLayout(heathP2);
    statuePlayerTwo->addLayout(shildP2);

    bonusPlayerTwo = new QGridLayout();
    lBSpeed2 = new QLabel(downHUD);
    lBHP2 = new QLabel(downHUD);
    lBProjectile2 = new QLabel(downHUD);

    bonusPlayerTwo->addWidget(imSpeed2,0,0,Qt::AlignHCenter);
    bonusPlayerTwo->addWidget(lBSpeed2,0,1,Qt::AlignHCenter);

    bonusPlayerTwo->addWidget(imHP2,3,0,Qt::AlignHCenter);
    bonusPlayerTwo->addWidget(lBHP2,3,1,Qt::AlignHCenter);

    bonusPlayerTwo->addWidget(imProj2,5,0,Qt::AlignHCenter);
    bonusPlayerTwo->addWidget(lBProjectile2,5,1,Qt::AlignHCenter);

    //QPixmap * icon2 = new QPixmap("./image/game/bonus");
    //bonusPlayerTwo->addWidget(icon2);

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
    return scene->width()-2*(gameEngine->ship2()->sizePixmap().width());
}

void DisplayEngine::addItemScene(Displayable* item)
{
    scene->addItem(item);
}

void DisplayEngine::removeItemScene(Displayable *item)
{
    scene->removeItem(item);
}

void DisplayEngine::enableTimerData()
{
    timer->setEnabled(true);
    scoreP1->setEnabled(true);
    scoreP2->setEnabled(true);
}

void DisplayEngine::updateScreen()
{
    scene->advance();
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

void DisplayEngine::setBonus1(TypeBonus in,int value)
{

    if(value != 0)
        switch(in)
        {
            case TypeBonusHP:
            //imHP1->setPixmap(pixHP);
            lBSpeed1->setNum(value);

            case TypeBonusProjectile :
            //imProj1->setPixmap(pixProj);
            lBProjectile1->setText("");

            case TypeBonusSpeed :
            //imSpeed1->setPixmap(pixSpeed);
            lBSpeed1->setText("");
        }
    else
        switch(in)
        {
            case TypeBonusHP:
            //imHP1->setText("");
            lBSpeed1->setText("");
            break;

            case TypeBonusProjectile :
            //imProj1->setText("");
            lBProjectile1->setText("");

            case TypeBonusSpeed :
            //imSpeed1->setText("");
            lBSpeed1->setText("");
        }
}

void DisplayEngine::setBonus2(TypeBonus in,int value)
{
    if(value != 0)
        switch(in)
        {
            case TypeBonusHP:
            //imHP2->setPixmap(pixHP);
            lBSpeed2->setNum(value);

            case TypeBonusProjectile :
            //imProj2->setPixmap(pixProj);
            lBProjectile2->setText("");

            case TypeBonusSpeed :
            //imSpeed2->setPixmap(pixSpeed);
            lBSpeed2->setText("");
        }
    else
        switch(in)
        {
            case TypeBonusHP:
            //imHP2->setText("");
            lBSpeed2->setText("");
            break;

            case TypeBonusProjectile :
            //imProj2->setText("");
            lBProjectile2->setText("");

            case TypeBonusSpeed :
            //imSpeed2->setText("");
            lBSpeed2->setText("");
        }
}

void DisplayEngine::updateGameData()
{
    this->setProgressHP1(gameEngine->ship1()->getHealthPoint());
    this->setProgressHP2(gameEngine->ship2()->getHealthPoint());

    this->setProgressShield1(gameEngine->ship1()->getHealthForceField());
    this->setProgressShield2(gameEngine->ship2()->getHealthForceField());
}

void DisplayEngine::updateGameDataTimer()
{
    int deltaTime = gameEngine->timeGamevalue() - gameEngine->elapsedTime();

    timer->display(affiche->toString("mm:ss"));

    if(deltaTime <= 0)
        gameEngine->endGameTimer();
}

void DisplayEngine::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_F12:
        this->switchFullScreen();
        break;

        case Qt::Key_Escape:
        gameEngine->escapeGame();
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
        // Param of the screen
        showFullScreen();
    else
        showMaximized();

    isFullScreen = !isFullScreen;
}
