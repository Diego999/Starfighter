/*==============================================================*
 | Implementation file Asteroid.cpp
 |        implements : Asteroid class
 |
 |
 | summary : Entity class that represents an asteroid & small asteroid.
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

#include "include/engine/DisplayEngine.h"
#include "include/engine/GameEngine.h"

#include "include/game/Asteroid.h"

#include "include/config/Define.h"

//If _dSlop & _bSmall are defined together. It means that it's a small asteroid
Asteroid::Asteroid(qreal _dX, qreal _dY,Shooter _from, qreal _dResistance, qreal _dHealthPoint,GameEngine *_gameEngine,qreal _dSlope,qreal _dAngle,bool _bSmall)
    ://Displayable(_dX,_dY),
      Destroyable(_dHealthPoint,_dResistance),
      Projectile(_dX,_dY,_from),
      gameEngine(_gameEngine),//GameEngine
      index(0),//Index to count the number of frame since the last picture change
      directionX(1),//Default X-direction
      dSlope(fabs(_dSlope)),//Slope of the parent asteroid (only for small asteroid)
      dModule(0),//Defaut module (only for small asteroid)
      dAngle(_dAngle),//Angle of start to define the direction where to go, when a parent asteroid is destroyed (only for small asteroid)
      bSmall(_bSmall),//If it's a small asteroid
      bInvicible(false)//If it's invicible (use for small asteroid, when a parent asteroid is destroyed,
                       //we need a little time where they aren't destroyable, otherwise they'll be destroyed
{
    nbPoint = NB_POINT_ASTEROID;

    //If it's a small asteroid, we use dSlope and generate and X-direction
    if(bSmall)
    {
        nbPoint = NB_POINT_SMALL_ASTEROID;
        bInvicible=true;
        QTimer::singleShot(INVIBILITY_TIME_SMALL_ASTEROID,this,SLOT(removeInvicibility()));

        numberFrameMin = NB_PICTURE_SMALL_ASTEROID_MIN;
        numberFrameMax = NB_PICTURE_SMALL_ASTEROID_MAX;
        currentFrame = numberFrameMin;

        dPower = POWER_SMALL_ASTEROID;
        setPixmap(new QPixmap(QString(PICTURE_SMALL_ASTEROID).arg(currentFrame)));
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
            directionX = -1;
            qreal l_dXl = (l_xc*l_yc-l_m*l_ymax)/(l_yc-l_ymax);
            qreal l_dXf = l_xc-gameEngine->randInt(fabs(l_dXl-l_xc));
            if(l_yg == 0)//Top Left
                dSlope = l_ymax/(l_dXf-l_xg);
            else
                dSlope = -l_ymax/(l_dXf-l_xg);
        }

        if(l_yg == 0)
            //we should remove the height to have a better apparition
            setPos(l_xg,l_ymin-getPixmap()->height());
        else
            setPos(l_xg,l_ymax);
    }
}

bool Asteroid::doubleCompare(qreal _dA, qreal _dB)
{
    qreal l_e = 1e-5;
    return fabs(_dA-_dB) < l_e;
}

bool Asteroid::isDeltaAngleEnough(int _angles[], int _size, int _angle)
{
    int l_delta = DELTA_ANGLE;

    for(int i = 0;i<_size;i++)
        if(fabs(_angles[i]-_angle)<l_delta)
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
                                                      Other,RESISTANCE_SMALL_ASTEROID,HEALTHPOINT_SMALL_ASTEROID,gameEngine,dSlope,angle,true));
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
    //Number of frame before changing the picture
    if(index++%NUMBER_FRAME_BEFORE_CHANGING_PIC==0)
    {
        if(currentFrame==numberFrameMax)
            currentFrame=numberFrameMin;

        if(bSmall)
            setPixmap(new QPixmap(QString(PICTURE_SMALL_ASTEROID).arg(++currentFrame)));
        else
            setPixmap(new QPixmap(QString(PICTURE_ASTEROID).arg(++currentFrame)));
    }
    _painter->drawPixmap(0,0,*getPixmap());
}

void Asteroid::advance(int _step)
{
    Displayable::advance(_step);

    if(!bSmall)
        setPos(pos().x()+directionX*SPEED_ASTEROID,
            pos().y()-trajectoryDraw(SPEED_ASTEROID));
    else
    {
        dModule+=kIntervalModule;
        setPos(dXOrigin+dModule*cos(dAngle*M_PI/180.0),
               dYOrigin-dModule*sin(dAngle*M_PI/180.0));
    }
}

qreal Asteroid::trajectoryDraw(qreal _dX)
{
    return dSlope*_dX;
}

