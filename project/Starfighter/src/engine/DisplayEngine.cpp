#include "include/engine/DisplayEngine.h"

#include "include/game/Displayable.h"
#include "include/game/Projectile.h"
#include "include/utils/Settings.h"

#include "include/enum/Enum.h"

#include <QTimerEvent>

#define SPACE_BETWEEN         250
#define SPACE_INPLAYER        50
#define BACKGROUND "background/black hole.png"

#include "QtGui"

//DisplayEngine::DisplayEngine(QWidget *parent) : QWidget(parent)
DisplayEngine::DisplayEngine(QWidget *parent, GameEngine *ge): QWidget(parent), gameEngine(ge), isFullScreen(true)
{

    QVBoxLayout * mainScreen = new QVBoxLayout(this);

    downHUD = new QWidget();
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,100,100);
    view = new QGraphicsView(scene);

    // Set background
    QPixmap bg( BACKGROUND );
    //scene->setBackgroundBrush(bg);
    scene->setBackgroundBrush(Qt::black);

    // Param of the screen
    //mainPart->showFullScreen();
    showMaximized();
    setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint);

    mainScreen->addWidget(view);
    mainScreen->addWidget(downHUD);

    this->creatHUD();
    this->gameType();

    startTimer(100);

    //view->show();
    setLayout(mainScreen);

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
    player1Name->setText("Name: player1");
    //player1Name->setText(tr("Name : %1").arg(set.playerOneName()));
    playerOneNamu->addWidget(player1Name);


    QVBoxLayout * statuePlayerOne = new QVBoxLayout();

    QHBoxLayout * heathP1 = new QHBoxLayout();
    QLabel * lHP1 = new QLabel("HP:\t");
    HP1= new QProgressBar();
    HP1->setRange(0,100);

    heathP1->addWidget(lHP1);
    heathP1->addWidget(HP1);

    QHBoxLayout * shildP1 = new QHBoxLayout();
    QLabel * lShild1 = new QLabel("Shield:\t");
    shield1= new QProgressBar();
    shield1->setRange(0,100);

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
    player2Name->setText("Name: player2");
    //player2Name->setText(tr("Name : %1").arg(set.playerTwoName()));
    playerTwoNamu->addWidget(player2Name);

    QVBoxLayout * statuePlayerTwo = new QVBoxLayout();

    QHBoxLayout * heathP2 = new QHBoxLayout();
    QLabel * lHP2 = new QLabel("HP:\t");
    HP2= new QProgressBar();
    HP2->setRange(0,100);

    heathP2->addWidget(lHP2);
    heathP2->addWidget(HP2);

    QHBoxLayout * shildP2 = new QHBoxLayout();
    QLabel * lShild2 = new QLabel("Shield:\t");
    shield2= new QProgressBar();
    shield2->setRange(0,100);

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

    // place the HUD
    QDesktopWidget * desktop = QApplication::desktop();

    screenSizeHeight = desktop->height();
    screenSizeWidth = desktop->width();

    downHUD->move(0,screenSizeHeight-125);

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

/*
void DisplayEngine::paintEvent(QPaintEvent * event)
{

    scene->advance();

}

void DisplayEngine::timerEvent(QTimerEvent * event)
{

    //this->update();
    scene->advance();

}
*/
QRect DisplayEngine::sceneSize()
{
    return QRect(0,0,scene->width(),scene->height());
}

void DisplayEngine::gameType()
{
    // si juste alors active le timer
    //if(gameEngine->)
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

void DisplayEngine::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F12)
    {
        this->switchFullScreen();
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
        setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint);
    }

    isFullScreen = !isFullScreen;
}
