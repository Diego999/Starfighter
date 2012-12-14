#include "include/game/AlienSpaceship.h"
#include "include/engine/DisplayEngine.h"
#include "include/game/ProjectileAlien.h"

AlienSpaceship::AlienSpaceship(int _nbSpirales,qreal _dHealthPoint,qreal _dResistance,GameEngine* _gameEngine)
    :Displayable(0,0),
      Destroyable(_dHealthPoint,_dResistance),
      Obstacle(0,0),
      gameEngine(_gameEngine),nbSpirales(_nbSpirales),dYStop(gameEngine->displayEngine()->sceneSize().y()),isAttacking(false),hasAttacked(false),directionX(1),direction(1)
{
    /*Generate the position of the AlienSpaceship
      For more informations cf the specification file*/
    int l_Xmin = gameEngine->displayEngine()->xminWarzone();
    int l_Xmax = gameEngine->displayEngine()->xmaxWarZone();

    int l_x1 = gameEngine->randInt((l_Xmax-DELTA_X)-(l_Xmin+DELTA_X))+l_Xmin;
    int l_x2 = gameEngine->randInt(2*DELTA_X)-DELTA_X+l_x1;
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

    setPixmap(new QPixmap(":/images/game/spaceship"));
}

AlienSpaceship::~AlienSpaceship()
{

}

void AlienSpaceship::advance(int _step)
{
    Obstacle::advance(_step);

    if(!isAttacking)
    {
        if(!hasAttacked && pos().y()>=(dYStop-MARGIN_Y) && pos().y()<=(dYStop+MARGIN_Y))
            attacking();

        dArgument-=direction*kIntervalArgument;

        setPos(dX0+directionX*dModule*cos(dArgument*M_PI/180.0)
               ,dY0-dModule*sin(dArgument*M_PI/180.0));
    }
}

void AlienSpaceship::attacking()
{
    isAttacking=true;

    for(int i = 0;i<nbSpirales;i++)
        gameEngine->displayEngine()->addProjectile(new ProjectileAlien(pos().x(),pos().y(),Other,360.0/nbSpirales*(i+1),0));

    hasAttacked=true;
    isAttacking=false;
}

QRectF AlienSpaceship::boundingRect() const
{
    return QRectF(getPixmap()->rect());
}

QPainterPath AlienSpaceship::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void AlienSpaceship::paint(QPainter *_painter,const QStyleOptionGraphicsItem *_option, QWidget *_widget)
{
    _painter->drawPixmap(0,0,*getPixmap());
    _painter->setPen(QPen(QColor(255,0,0)));
    _painter->drawPath(shape());
}
