/*=====================================================================*
 | Declaration file Asteroid.h
 |      declares :  Asteroid class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef ASTEROID_H
#define ASTEROID_H

#include "include/game/Destroyable.h"
#include "include/game/Projectile.h"

#include "include/enum/Enum.h"
#include "include/config/Define.h"

class GameEngine;

class Asteroid : public Destroyable, public Projectile
{
    Q_OBJECT
public:
    //Slope is define ONLY FOR THE LITTLE ASTEROIDES
    Asteroid(qreal _dX, qreal _dY,Shooter _from, qreal _dResistance, qreal _dHealthPoint, GameEngine *_gameEngine,qreal _dSlope=0,qreal _dAngle=0,bool _bSmall=false);
    ~Asteroid();

    bool isSmall() const {return bSmall;}
    bool isInvicible() const {return bInvicible;}
    TypeItem getTypeObject() const {return (bSmall)?tSmallAsteroid:tAsteroid;}
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private slots:
    void removeInvicibility() {bInvicible=false;}

private:
    static bool isDeltaAngleEnough(int _angles[],int _size,int _angle);
    static bool doubleCompare(qreal _dA,qreal _dB);
    static const qreal kIntervalModule = SPEED_SMALL_ASTEROID;

    void advance(int _step);
    qreal trajectoryDraw(qreal _dX);

    GameEngine* gameEngine;

    int currentFrame;
    int numberFrameMin;
    int numberFrameMax;
    int index;

    int directionX;
    qreal dSlope;
    qreal dModule;
    qreal dAngle;

    bool bSmall;
    bool bInvicible;
};
#endif
