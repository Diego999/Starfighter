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
      gameEngine(_gameEngine),dSlope(_dSlope),bSmall(_bSmall),bInvicible(false),dModule(0)
{
    nbPoint = NB_POINT_ASTEROID;
    index = 0;
    //If it's a small asteroid, we use dSlope and generate and X-direction
    if(bSmall)
    {
        nbPoint = NB_POINT_SMALL_ASTEROID;
        bInvicible=true;
        QTimer::singleShot(300,this,SLOT(removeInvicibility()));

        numberFrameMin = NB_PICTURE_SMALL_ASTEROID_MIN;
        numberFrameMax = NB_PICTURE_SMALL_ASTEROID_MAX;
        currentFrame = numberFrameMin;
        dPower = POWER_SMALL_ASTEROID;
        setPixmap(new QPixmap(QString(PICTURE_SMALL_ASTEROID).arg(currentFrame)));
        //int l_X = gameEngine->randInt(2);

        //dSlope=tan(_dSlope*M_PI/180.0);
        dSlope=_dSlope;
        direction = 1;

        /*if(_dSlope>90 && _dSlope<=270)
        {
            direction = -1;
            dSlope*=-1;
        }*/
    }
    else
    {
        numberFrameMin = NB_PICTURE_ASTEROID_MIN;
        numberFrameMax = NB_PICTURE_ASTEROID_MAX;
        currentFrame = numberFrameMin;
        dPower = POWER_ASTEROID;
        setPixmap(new QPixmap(QString(PICTURE_ASTEROID).arg(currentFrame)));
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

void Asteroid::removeInvicibility()
{
    bInvicible = false;
}

bool Asteroid::doubleCompare(qreal a, qreal b)
{
    qreal e = 1e-5;
    return fabs(a-b) < e;
}

bool Asteroid::isDeltaAngleEnough(int angles[], int size, int angle)
{
    int l_delta = 30;

    for(int i = 0;i<size;i++)
        if(fabs(angles[i]-angle)<l_delta)
            return false;

    return true;
}

Asteroid::~Asteroid()
{
    if(!bSmall)
    {
        int l_nb = gameEngine->randInt(MAX_ASTEROID-MIN_ASTEROID+1)+MIN_ASTEROID;
        int* l_angles = new int[l_nb];

        for(int i = 0;i<l_nb;i++)
        {
            qreal angle = 0;
            do
            {
                angle = gameEngine->randInt(360);
            }while(!isDeltaAngleEnough(l_angles,l_nb,angle));

            l_angles[i] = angle;

            gameEngine->addSmallAsteroid(new Asteroid(pos().x()+getPixmap()->width()/2.0,pos().y()+getPixmap()->height()/2.0,
                                                      Other,RESISTANCE_SMALL_ASTEROID,HEALTHPOINT_SMALL_ASTEROID,gameEngine,angle,true));
        }
        delete l_angles;
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

    if(!bSmall)
        setPos(pos().x()+direction*SPEED_ASTEROID,
            pos().y()-trajectoryDraw(SPEED_ASTEROID));
    else
    {
        dModule+=kIntervalModule;
        setPos(dXOrigin+dModule*cos(dSlope*M_PI/180.0),
               dYOrigin-dModule*sin(dSlope*M_PI/180.0));
    }
}

qreal Asteroid::trajectoryDraw(qreal _dX)
{
    return dSlope*_dX;
}

