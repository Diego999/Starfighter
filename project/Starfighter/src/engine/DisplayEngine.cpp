#include "include/engine/DisplayEngine.h"
#include "include/engine/UserControlsEngine.h"

#include "include/game/Displayable.h"
#include "include/game/Projectile.h"
#include "include/game/Spaceship.h"
#include "include/game/Obstacle.h"
#include "include/game/Bonus.h"
#include "include/game/Asteroid.h"

#include "include/utils/Settings.h"

#include "include/enum/Enum.h"

#include <QDebug>
#include "include/game/ProjectileSimple.h"
#include "include/game/Supernova.h"

#include <QTimerEvent>

#define SPACE_BETWEEN         250
#define SPACE_INPLAYER        50
#define BACKGROUND "background/black hole.png"

#include "QtGui"

//DisplayEngine::DisplayEngine(QWidget *parent) : QWidget(parent), isFullScreen(true)
DisplayEngine::DisplayEngine(GameEngine *ge, QWidget *parent): QWidget(parent), gameEngine(ge), isFullScreen(true), isTimer(false)
{

    // get screen dimension
    QDesktopWidget * desktop = QApplication::desktop();

    screenSizeHeight = 900;
    //screenSizeHeight = desktop->height();

    screenSizeWidth = 1440;
    //screenSizeWidth = desktop->width();

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
    view->setOptimizationFlags(QGraphicsView::DontClipPainter
                                 | QGraphicsView::DontSavePainterState
                                 | QGraphicsView::DontAdjustForAntialiasing);
    view->viewport()->setFocusProxy( this );
    view->setFocusPolicy(Qt::NoFocus);

    // Set background
    QPixmap bg( BACKGROUND );
    //scene->setBackgroundBrush(bg);
    scene->setBackgroundBrush(Qt::black);
    this->setFixedSize(screenSizeWidth,screenSizeHeight);

    // Param of the screen
    showFullScreen();
    //setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint);
    view->move(0,0);

    mainScreen->setMargin(0);
    mainScreen->setSpacing(0);

    mainScreen->addWidget(view);
    mainScreen->addWidget(downHUD);
    //scene->addEllipse(500,500,40,40,QPen(QColor(20,20,20)),QBrush(QColor(20,20,20)))->setPos(100,100);
    this->creatHUD();
    this->gameType();

    setLayout(mainScreen);
    //scene->addItem(new Supernova(sceneWidth/2,sceneHeigth/2,gameEngine));
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
}

void DisplayEngine::addBonus(Bonus *_inBonus)
{
    scene->addItem(_inBonus);
    listBonus.append(_inBonus);
}

void DisplayEngine::addAsteroide(Asteroid *_inAsteroide)
{
    scene->addItem(_inAsteroide);
    listAsteroide.append(_inAsteroide);
}

/*void DisplayEngine::paintEvent(QPaintEvent * event)
{

    scene->advance();

}
*/

void DisplayEngine::timerEvent(QTimerEvent * event)
{
    scene->advance();
    //static int i = 0;
    //if(i++<=2)
    //    delete scene->items().last();
}

QRect DisplayEngine::sceneSize() const
{
    return QRect(0,0,scene->width(),scene->height());
}

/**
*   QPoint(0->xmin,xmax->sceneWidth)
*/
QPoint  DisplayEngine::warzoneValueMin() const
{
    int xmin = gameEngine->ship1()->sizePixmap().width()*2;
    int ymin = 0;

    return QPoint(xmin,ymin);
}

QPoint DisplayEngine::warzoneValueMax() const
{
    int xmax = sceneWidth-2*(gameEngine->ship2()->sizePixmap().width());
    int ymax = scene->height();

    return QPoint(xmax,ymax);
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

void DisplayEngine::updateGameData()
{
    int deltaTime = gameEngine->timeGamevalue() - gameEngine->elapsedTime();


    if(deltaTime == 0)
    {
        this->endGame();
    }
}

void DisplayEngine::endGame()
{
    // get point player
    //gameEngine->spaceship;

    QMessageBox::information(mainPart,
                             "Fin de partie",
                             tr("Fin de partie"),
                             QMessageBox::Ok);
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
