#ifndef ALIEN_SPACESHIP_H
#define ALIEN_SPACESHIP_H

#include "include/game/Obstacle.h"
#include "include/game/Destroyable.h"
#include "include/enum/Enum.h"

class GameEngine;

class AlienSpaceship : public Destroyable,public Obstacle
{
public:
    AlienSpaceship(int _nbSpirales,qreal _dHealthPoint,qreal _dResistance,GameEngine* _gameEngine);
    ~AlienSpaceship();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* _painter, const QStyleOptionGraphicsItem* _option, QWidget* _widget);
    Shooter getTypeObject() const {return Alien;}
private:
    void advance(int step);
    static const qreal kIntervalArgument = 0.010;
    void attacking();

    GameEngine* gameEngine;

	int nbSpirales;
    qreal dYStop;
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
