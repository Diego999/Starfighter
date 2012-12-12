#include "include/game/AlienSpaceship.h"
#include "include/engine/DisplayEngine.h"
#include "include/game/ProjectileAlien.h"

#define MARGIN_Y 10
#define DELTA_X 100
#define NB_SEC 1

AlienSpaceship::AlienSpaceship(int _nbSpirales,qreal _healthPoint,qreal _resistance,GameEngine* _ge)
    :Displayable(0,0),
      Destroyable(_healthPoint,_resistance),
      Obstacle(0,0),
      gameEngine(_ge),nbSpirales(_nbSpirales),yStop(gameEngine->displayEngine()->sceneSize().y()),isAttacking(false),hasAttacked(false),directionX(1),direction(1)
{
    int xmin = gameEngine->displayEngine()->xminWarzone();
    int xmax = gameEngine->displayEngine()->xmaxWarZone();

    int x1 = gameEngine->randInt((xmax-DELTA_X)-(xmin+DELTA_X))+xmin;
    int x2 = gameEngine->randInt(2*DELTA_X)-DELTA_X+x1;
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
    pxmPicture = new QPixmap(":/images/game/spaceship");
    QTimer::singleShot(NB_SEC*1000,this,SLOT(playSoun));
}

AlienSpaceship::~AlienSpaceship()
{

}

void AlienSpaceship::advance(int _step)
{
    Obstacle::advance(_step);

    if(!isAttacking)
    {
        if(!hasAttacked && y>=(yStop-MARGIN_Y) && y<=(yStop+MARGIN_Y))
            attacking();

        dArgument-=direction*kIntervalArgument;

        x = dX0+directionX*dModule*cos(dArgument*M_PI/180.0);
        y = dY0-dModule*sin(dArgument*M_PI/180.0);
        setPos(x,y);
    }
}

void AlienSpaceship::attacking()
{
    isAttacking=true;

    for(int i = 0;i<nbSpirales;i++)
        gameEngine->displayEngine()->addProjectile(new ProjectileAlien(x,y,Other,360.0/nbSpirales*(i+1),0));

    hasAttacked=true;
    isAttacking=false;
}

QRectF AlienSpaceship::boundingRect() const
{
    return QRectF(pxmPicture->rect());
}

QPainterPath AlienSpaceship::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void AlienSpaceship::paint(QPainter *_painter,const QStyleOptionGraphicsItem *_option, QWidget *_widget)
{
    _painter->drawPixmap(0,0,*pxmPicture);
    _painter->setPen(QPen(QColor(255,0,0)));
    _painter->drawPath(shape());
}
