#include "include/game/Bonus.h"
#include "include/engine/DisplayEngine.h"
#include "include/engine/GameEngine.h"
#include "include/game/Spaceship.h"

#define DELTA_X_B 100
#define NB_SEC 1

Bonus::Bonus(GameEngine *ge, Spaceship *ss):Displayable(x,y),gameEngine(ge),spaceship(ss),directionX(1),direction(1)
{
    int xmin = gameEngine->displayEngine()->xminWarzone();
    int xmax = gameEngine->displayEngine()->xmaxWarZone();

    int x1 = gameEngine->randInt((xmax-DELTA_X_B)-(xmin+DELTA_X_B))+xmin;
    int x2 = gameEngine->randInt(2*DELTA_X_B)-DELTA_X_B+x1;
    int x3 = x1;

    int y1 = gameEngine->displayEngine()->sceneSize().y();
    int y2 = gameEngine->displayEngine()->sceneSize().height()/2.0;
    int y3 = gameEngine->displayEngine()->sceneSize().height();

    if(x2<x1)
    {
        dArgument+=180.0;
        directionX=-1;
        direction=-1;
    }
    if(gameEngine->randInt(2)==1)//1 = bottom,0 = top
    {
        direction*=-1;
        y1=gameEngine->displayEngine()->sceneSize().height();
        y3=gameEngine->displayEngine()->sceneSize().y();
    }

    yStop = y2;

    dX0 = (x3*x3*(y1-y2)+(x1*x1+(y1-y2)*(y1-y3))*(y2-y3)+x2*x2*(y3-y1))
            /(2.0*(x3*(y1-y2)+x1*(y2-y3)+x2*(y3-y1)));

    dY0 = (-x2*x2*x3+x1*x1*(x3-x2)+x3*(y1-y2)*(y1+y2)+x1*(x2*x2-x3*x3+y2*y2-y3*y3)+x2*(x3*x3-y1*y1+y3*y3))
            /(2.0*(x3*(y1-y2)+x1*(y2-y3)+x2*(y3-y1)));

    x=x1;
    y=y1;
    dModule = sqrt((x1-dX0)*(x1-dX0)+(y1-dY0)*(y1-dY0));
    dArgument = atan((dY0-y1)/(x1-dX0))*180.0/M_PI;

    pxmPicture = new QPixmap(":/images/game/bonus");

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

    x = dX0+directionX*dModule*cos(dArgument*M_PI/180.0);
    y = dY0-dModule*sin(dArgument*M_PI/180.0);
    setPos(x,y);
}

QRectF Bonus::boundingRect() const
{
    return QRectF(pxmPicture->rect());
}

QPainterPath Bonus::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Bonus::paint(QPainter *_painter,const QStyleOptionGraphicsItem *_option, QWidget *_widget)
{
    _painter->drawPixmap(0,0,*pxmPicture);
    _painter->setPen(QPen(QColor(255,0,0)));
    _painter->drawPath(shape());
}
