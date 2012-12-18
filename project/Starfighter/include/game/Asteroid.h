#ifndef ASTEROID_H
#define ASTEROID_H

#include "include/game/Destroyable.h"
#include "include/game/Obstacle.h"
#include "include/game/Projectile.h"

#include "include/enum/Enum.h"

class GameEngine;

#define SPEED_ASTEROID 1
#define MAX_ASTEROID 5
#define MIN_ASTEROID 3
#define POWER_ASTEROID 10
#define POWER_SMALL_ASTEROID 5
#define RESISTANCE_SMALL_ASTEROID 1
#define HEALTHPOINT_SMALL_ASTEROID 50

class Asteroid : public Destroyable, public Obstacle, public Projectile
{
public:
    //Slope is define ONLY FOR THE LITTLE ASTEROIDES
    Asteroid(qreal _dX, qreal _dY,Shooter _from, qreal _dResistance, qreal _dHealthPoint, GameEngine *_gameEngine,qreal _dSlope=0,bool _bSmall=false);
    ~Asteroid();

    bool isSmall() const {return bSmall;}
    TypeItem getTypeObject() const;
    void receiveAttack(qreal _dPower) {Destroyable::receiveAttack(_dPower);}
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void advance(int _step);
    qreal trajectoryDraw(qreal _dX);

    int currentFrame;
    int numberFrameMin;
    int numberFrameMax;
    int index;

    int direction;

    GameEngine* gameEngine;
    qreal dSlope;
    bool bSmall;
};
#endif
