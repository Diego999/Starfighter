#include "include/engine/DisplayEngine.h"
#include "include/utils/Settings.h"
#include "include/enum/Enum.h"
#include <QTimer>

#define ESPACEMENT_OBJ 20
#define BACKGROUND "background/black hole.png"

#include "QtGui"

DisplayEngine::DisplayEngine(int width, int height, GameEngine *ge) : gameEngine(ge)
{

    mainPart = new QWidget();
    mainPart->showFullScreen();

    //Settings set;
    //view = new QGraphicsView(mainPart);

    scene = new QGraphicsScene(mainPart);
    QPixmap bg( BACKGROUND );
    scene->setBackgroundBrush(bg);

    QWidget * downShow = new QWidget(mainPart);
    QHBoxLayout * downPart = new QHBoxLayout(downShow);


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
    QLCDNumber * timer = new QLCDNumber();
    timer->setDigitCount(5);

    QLCDNumber * scoreP1 = new QLCDNumber();
    QLCDNumber * scoreP2 = new QLCDNumber();

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
    downPart->addSpacing(ESPACEMENT_OBJ);
    downPart->addLayout(statuePlayerOne);
    downPart->addSpacing(ESPACEMENT_OBJ);
    downPart->addLayout(bonusPlayerOne);
    downPart->addSpacing(ESPACEMENT_OBJ);
    downPart->addLayout(timeAndScore);
    downPart->addSpacing(ESPACEMENT_OBJ);
    downPart->addLayout(playerTwoNamu);
    downPart->addSpacing(ESPACEMENT_OBJ);
    downPart->addLayout(statuePlayerTwo);
    downPart->addSpacing(ESPACEMENT_OBJ);
    downPart->addLayout(bonusPlayerTwo);

    downShow->move(0,height-65);

    //view->(&scene);

}

DisplayEngine::~DisplayEngine()
{
    delete mainPart;
}

QRect DisplayEngine::sceneSize()
{
    return QRect(0,0,scene->width(),scene->height());
}

void DisplayEngine::gameType()
{
    //if(gameEngine->)
    {
        timer->setDisabled(true);
        scoreP1->setDisabled(true);
        scoreP2->setDisabled(true);
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
