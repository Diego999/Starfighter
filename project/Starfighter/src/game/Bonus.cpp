#include "include/game/Bonus.h"
#include "include/engine/DisplayEngine.h"
#include "include/engine/GameEngine.h"
#include "include/game/Spaceship.h"

#define DELTA_X_B 100
#define NB_SEC 1

Bonus::Bonus(GameEngine *_gameEngine, Spaceship *_spaceShip)
    :Displayable(0,0,new QPixmap(":/images/game/bonus")),
    gameEngine(_gameEngine),spaceship(_spaceShip),directionX(1),direction(1)
{
    /*Generate the position of the AlienSpaceship
      For more informations cf the specification file*/
    int l_xmin = gameEngine->displayEngine()->xminWarzone();
    int l_xmax = gameEngine->displayEngine()->xmaxWarZone();

    int l_x1 = gameEngine->randInt((l_xmax-DELTA_X_B)-(l_xmin+DELTA_X_B))+l_xmin;
    int l_x2 = gameEngine->randInt(2*DELTA_X_B)-DELTA_X_B+l_x1;
    int l_x3 = l_x1;

    int l_y1 = gameEngine->displayEngine()->sceneSize().y();
    int l_y2 = gameEngine->displayEngine()->sceneSize().height()/2.0;
    int l_y3 = gameEngine->displayEngine()->sceneSize().height();

    /*Calculate the trajectory. There are 4 possibilities :
    1) Top->Bottom x2<xg
    2) Top->Bottom x2>=xg
    3) Bottom->Top x2<xg
    4) Bottom->Top x2>=xg
    */
    if(l_x2<l_x1)
    {
        dArgument+=180.0;
        directionX=-1;
        direction=-1;
    }
    if(gameEngine->randInt(2)==1)//1 = bottom,0 = top
    {
        direction*=-1;
        l_y1=gameEngine->displayEngine()->sceneSize().height();
        l_y3=gameEngine->displayEngine()->sceneSize().y();
    }

    dYStop = l_y2;

    dX0 = (l_x3*l_x3*(l_y1-l_y2)+(l_x1*l_x1+(l_y1-l_y2)*(l_y1-l_y3))*(l_y2-l_y3)+l_x2*l_x2*(l_y3-l_y1))
            /(2.0*(l_x3*(l_y1-l_y2)+l_x1*(l_y2-l_y3)+l_x2*(l_y3-l_y1)));

    dY0 = (-l_x2*l_x2*l_x3+l_x1*l_x1*(l_x3-l_x2)+l_x3*(l_y1-l_y2)*(l_y1+l_y2)+l_x1*(l_x2*l_x2-l_x3*l_x3+l_y2*l_y2-l_y3*l_y3)+l_x2*(l_x3*l_x3-l_y1*l_y1+l_y3*l_y3))
            /(2.0*(l_x3*(l_y1-l_y2)+l_x1*(l_y2-l_y3)+l_x2*(l_y3-l_y1)));

    setPos(l_x1,l_y1);

    dModule = sqrt((l_x1-dX0)*(l_x1-dX0)+(l_y1-dY0)*(l_y1-dY0));
    dArgument = atan((dY0-l_y1)/(l_x1-dX0))*180.0/M_PI;

    playSound();

    QTimer* timer = new QTimer(this);
    timer->setInterval(NB_SEC*1000);
    timer->start();

    connect(timer,SIGNAL(timeout()),this,SLOT(playSound()));
}

Bonus::~Bonus()
{

}

void Bonus::playSound()
{
    QSound::play("res/musics/beep.wav");
}

void Bonus::advance(int _step)
{
    Displayable::advance(_step);

    dArgument-=direction*kIntervalArgument;

    setPos(dX0+directionX*dModule*cos(dArgument*M_PI/180.0),
           dY0-dModule*sin(dArgument*M_PI/180.0));
}

QRectF Bonus::boundingRect() const
{
    return QRectF(getPixmap()->rect());
}

QPainterPath Bonus::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Bonus::paint(QPainter *_painter,const QStyleOptionGraphicsItem *_option, QWidget *_widget)
{
    _painter->drawPixmap(0,0,*getPixmap());
    _painter->setPen(QPen(QColor(255,0,0)));
    _painter->drawPath(shape());
}
