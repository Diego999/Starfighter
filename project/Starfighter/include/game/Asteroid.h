#ifndef ASTEROID_H
#define ASTEROID_H

#include "include/game/Destroyable.h"
#include "include/game/Obstacle.h"
#include "include/game/Projectile.h"
#include "include/engine/GameEngine.h"
#include "include/enum/Enum.h"

class Asteroid : public Destroyable, public Obstacle, public Projectile
{
public:
    //Slope is define ONLY FOR THE LITTLE ASTEROIDES
    Asteroid(qreal x, qreal y,Shooter from, int resistance, int healthPoint, GameEngine *ge,qreal slope=0,bool small=false);
    ~Asteroid();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* _painter,const QStyleOptionGraphicsItem* _option, QWidget* _widget);

private:
    void advance(int _step);
    qreal trajectoryDraw(qreal _dX);

    int direction;

    GameEngine* ge;
    qreal slope;
    bool smallA;
};
#endif
