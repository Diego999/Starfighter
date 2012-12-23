/*==============================================================*
 | Implementation file Alienspaceship.cpp
 |        implements : Alienspaceship class
 |
 |
 | summary : Entity class that represents an alienspaceship.
 |           For more information, please consult the specification file
 |
 | Creator : Diego Antognini
 | Creation date : 27/11/2012
 | Copyright: EIAJ, all rights reserved
 |
 |
 | Version of the file : 1.0.0
 |
 *==============================================================*/

#include "include/engine/GameEngine.h"
#include "include/engine/DisplayEngine.h"

#include "include/game/AlienSpaceship.h"
#include "include/game/ProjectileAlien.h"

AlienSpaceship::AlienSpaceship(int _nbSpirales,qreal _dHealthPoint,qreal _dResistance,GameEngine* _gameEngine)
    :Displayable(0,0,new QPixmap(PICTURE_ALIENSPACESHIP)),
      Destroyable(_dHealthPoint,_dResistance),
      gameEngine(_gameEngine),//GameEngine
      nbSpirales(_nbSpirales),//Number of spirales that will fired
      isAttacking(false),//If the alienspaceship is attacking (Will block the moving)
      hasAttacked(false),//If the alienspaceship has already fired, in this case, it won't fire again
      directionX(1),//Default X-direction
      directionY(1),//Default Y-direction
      directionArg(1)//Defaut Arg-direction
{
    //Points for the timer Mode
    Displayable::nbPoint = NB_POINT_ALIENSPACESHIP;

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
    if(l_x2>l_x1)
        directionArg=-1;
    else
    {
        directionX=-1;
        directionY=-1;
    }

    if(gameEngine->randInt(2)==1)//1 = bottom,0 = top
    {
        directionArg*=-1;
        l_y1=gameEngine->displayEngine()->sceneSize().height();
        l_y3=gameEngine->displayEngine()->sceneSize().y();
        //Rotate the picture if it's coming by the bottom size
        Displayable::setPixmap(new QPixmap(getPixmap()->transformed(QTransform().rotate(180))));
    }

    //Where the alienspaceship will stop to fire
    dYStop = l_y2;

    //Change Y location if the case where the alienspaceship comes by the top,
    //we should remove the height to have a better apparition
    if(l_y1==gameEngine->displayEngine()->sceneSize().y())
        l_y1-=getPixmap()->height();

    dX0 = (l_x3*l_x3*(l_y1-l_y2)+(l_x1*l_x1+(l_y1-l_y2)*(l_y1-l_y3))*(l_y2-l_y3)+l_x2*l_x2*(l_y3-l_y1))
            /(2.0*(l_x3*(l_y1-l_y2)+l_x1*(l_y2-l_y3)+l_x2*(l_y3-l_y1)));

    dY0 = (-l_x2*l_x2*l_x3+l_x1*l_x1*(l_x3-l_x2)+l_x3*(l_y1-l_y2)*(l_y1+l_y2)+l_x1*(l_x2*l_x2-l_x3*l_x3+l_y2*l_y2-l_y3*l_y3)+l_x2*(l_x3*l_x3-l_y1*l_y1+l_y3*l_y3))
            /(2.0*(l_x3*(l_y1-l_y2)+l_x1*(l_y2-l_y3)+l_x2*(l_y3-l_y1)));

    dModule = sqrt((l_x1-dX0)*(l_x1-dX0)+(l_y1-dY0)*(l_y1-dY0));
    dArgument += atan((dY0-l_y1)/(l_x1-dX0))*180.0/M_PI;

    setPos(l_x1,l_y1);
}

void AlienSpaceship::advance(int _step)
{
    Displayable::advance(_step);

    if(!isAttacking)
    {
        if(!hasAttacked && pos().y()>=(dYStop-MARGIN_Y) && pos().y()<=(dYStop+MARGIN_Y))
            attacking();

        dArgument+=directionArg*kIntervalArgument;

        setPos(dX0+directionX*dModule*cos(dArgument*M_PI/180.0)
               ,dY0-directionY*dModule*sin(dArgument*M_PI/180.0));
    }
}

void AlienSpaceship::attacking()
{
    isAttacking=true;

    //Shoot the projectiles
    for(int i = 0;i<nbSpirales;i++)
        gameEngine->addProjectile(new ProjectileAlien(pos().x(),pos().y(),Alien,360.0/nbSpirales*(i+1),0));

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
}
