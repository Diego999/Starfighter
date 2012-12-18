#include "include/engine/DisplayEngine.h"
#include "include/engine/GameEngine.h"

#include "include/game/Asteroid.h"

#include "include/config/Define.h"

//If _dSlop & _bSmall are defined together. It means that it's a small asteroid
Asteroid::Asteroid(qreal _dX, qreal _dY,Shooter _from, qreal _dResistance, qreal _dHealthPoint,GameEngine *_gameEngine,qreal _dSlope,bool _bSmall)
    :Displayable(_dX,_dY),
      Destroyable(_dHealthPoint,_dResistance),
      Obstacle(_dX,_dY),
      Projectile(_dX,_dY,_from),
      gameEngine(_gameEngine),dSlope(_dSlope),bSmall(_bSmall)
{
    index = 0;
    //If it's a small asteroid, we use dSlope and generate and X-direction
    if(bSmall)
    {
        numberFrameMin = 20000;
        numberFrameMax = 20031;
        currentFrame = numberFrameMin;
        dPower = POWER_SMALL_ASTEROID;
        setPixmap(new QPixmap(QString(":/images/game/asteroids/rock%1").arg(currentFrame)));
        //int l_X = gameEngine->randInt(2);

        dSlope=tan(_dSlope*M_PI/180.0);
        direction = 1;

        if(_dSlope>90 && _dSlope<=270)
        {
            direction = -1;
            dSlope*=-1;
        }
    }
    else
    {
        numberFrameMin = 10000;
        numberFrameMax = 10031;
        currentFrame = numberFrameMin;
        dPower = POWER_ASTEROID;
        setPixmap(new QPixmap(QString(":/images/game/asteroids/rock%1").arg(currentFrame)));
        QRect sceneSize = gameEngine->displayEngine()->sceneSize();
        /*Generate the position of the Asteroid and its trajectory
          For more informations cf the specification file*/
        int l_xmin = sceneSize.topLeft().x();
        int l_xmax = sceneSize.topRight().x();

        int l_ymin = sceneSize.topLeft().y();
        int l_ymax = sceneSize.bottomRight().y();

        int l_m = gameEngine->displayEngine()->xminWarzone();
        int l_n = gameEngine->displayEngine()->xmaxWarZone();

        int l_xc = (l_xmax-l_xmin)/2.0+l_xmin;
        int l_yc = (l_ymax-l_ymin)/2.0+l_ymin;

        int l_xg = gameEngine->randInt(l_n-l_m)+l_m;
        int l_yg = gameEngine->randInt(2);

        //LEFT
        if(l_xg <= l_xc)
        {
            direction = 1;
            qreal l_dXl = (l_xc*l_yc-l_n*l_ymax)/(l_yc-l_ymax);
            qreal l_dXf = gameEngine->randInt(l_dXl-l_xc)+l_xc;

            if(l_yg == 0)//Top Left
                dSlope = -l_ymax/(l_dXf-l_xg);
            else
                dSlope = l_ymax/(l_dXf-l_xg);
        }
        //RIGHT
        else
        {
            direction = -1;
            qreal l_dXl = (l_xc*l_yc-l_m*l_ymax)/(l_yc-l_ymax);
            qreal l_dXf = l_xc-gameEngine->randInt(fabs(l_dXl-l_xc));
            if(l_yg == 0)//Top Left
                dSlope = l_ymax/(l_dXf-l_xg);
            else
                dSlope = -l_ymax/(l_dXf-l_xg);
        }
        if(l_yg == 0)
            setPos(l_xg,l_ymin);
        else
            setPos(l_xg,l_ymax);
    }
}

TypeItem Asteroid::getTypeObject() const
{
    return (bSmall)?tSmallAsteroid:tAsteroid;
}

bool Asteroid::doubleCompare(qreal a, qreal b)
{
    qreal e = 1e-5;
    return fabs(a-b) < e;
}

Asteroid::~Asteroid()
{
    if(!bSmall)
    {
        int l_nb = gameEngine->randInt(MAX_ASTEROID-MIN_ASTEROID+1)+MIN_ASTEROID;

        for(int i = 0;i<l_nb;i++)
        {
            qreal angle = 360.0/l_nb*i;
            angle += 360.0/l_nb/2.0;

            qreal l_x = 0;
            qreal l_y = 0;

            if(cos(angle*M_PI/180.0)>0)
                l_x += getPixmap()->width();

            if(sin(angle*M_PI/180.0)<0)
                l_y += getPixmap()->height();
            else if(Asteroid::doubleCompare(sin(angle*M_PI/180.0),0))
                l_y += getPixmap()->height()/2.0;

            gameEngine->addSmallAsteroid(new Asteroid(pos().x()+l_x,pos().y()+l_y,Other,RESISTANCE_SMALL_ASTEROID,HEALTHPOINT_SMALL_ASTEROID,gameEngine,angle,true));
        }
    }
}

QRectF Asteroid::boundingRect() const
{
    return QRectF(getPixmap()->rect());
}

QPainterPath Asteroid::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Asteroid::paint(QPainter* _painter,const QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    if(index++%2==0)
    {
        if(currentFrame==numberFrameMax)
            currentFrame=numberFrameMin;

        setPixmap(new QPixmap(QString(":/images/game/asteroids/rock%1").arg(++currentFrame)));
    }
    _painter->drawPixmap(0,0,*getPixmap());
//    _painter->setPen(QPen(QColor(255,0,0)));
//    _painter->drawPath(shape());
}

void Asteroid::advance(int _step)
{
    Obstacle::advance(_step);

    setPos(pos().x()+direction*SPEED_ASTEROID,
           pos().y()-trajectoryDraw(SPEED_ASTEROID));
}

qreal Asteroid::trajectoryDraw(qreal _dX)
{
    return dSlope*_dX;
}

