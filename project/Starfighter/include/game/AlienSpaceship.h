#ifndef ALIEN_SPACESHIP_H
#define ALIEN_SPACESHIP_H

#include "include/game/Obstacle.h"
#include "include/game/Destroyable.h"
#include "include/game/Displayable.h"
#include "include/engine/GameEngine.h"
#include "include/enum/Enum.h"

class AlienSpaceship : public Destroyable,public Obstacle
{
public:
    AlienSpaceship(int _nbSpirales,qreal _healthPoint,qreal _resistance,GameEngine* _ge);
    ~AlienSpaceship();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget);
    Shooter getTypeObject() const {return Alien;}
private:
    void advance(int step);
    static const qreal kIntervalArgument = 0.010;
    void attacking();

	int nbSpirales;

    GameEngine* gameEngine;

    qreal yStop;
    bool isAttacking;
    bool hasAttacked;
    qreal dArgument;
    qreal dModule;
    qreal dX0;
    qreal dY0;
    int directionX;
    int direction;
};
#endif
