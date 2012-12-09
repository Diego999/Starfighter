#ifndef ASTEROID_H
#define ASTEROID_H

#include "include/game/Destroyable.h"
#include "include/game/Obstacle.h"
#include "include/game/Projectile.h"
#include "include/engine/GameEngine.h"
#include "include/enum/Enum.h"

class Asteroid : public Destroyable, public Obstacle, public Projectile
{
    //Q_OBJECT
public:
    //Slope is define ONLY FOR THE LITTLE ASTEROIDES
    Asteroid(qreal x, qreal y,Shooter from, int resistance, int healthPoint, GameEngine *ge,qreal slope=0);
    ~Asteroid();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* _painter, QStyleOptionGraphicsItem* _option, QWidget* _widget);

	void destroy();
	
private:
    void advance(int _step);
    qreal trajectoryDraw(qreal _dX);

    int resistance;
    int healthPoint;
    int direction;
    GameEngine* ge;
	qreal slope;
	
};
#endif
