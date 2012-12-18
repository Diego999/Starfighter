#ifndef ALIEN_SPACESHIP_H
#define ALIEN_SPACESHIP_H

#include "include/game/Obstacle.h"
#include "include/game/Destroyable.h"

#include "include/enum/Enum.h"

class GameEngine;

#define MARGIN_Y 10
#define DELTA_X 100
#define NB_SEC 1

class AlienSpaceship : public Destroyable,public Obstacle
{
public:
    AlienSpaceship(int _nbSpirales,qreal _dHealthPoint,qreal _dResistance,GameEngine* _gameEngine);
    ~AlienSpaceship();

    void receiveAttack(qreal _dPower) {Destroyable::receiveAttack(_dPower);}
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    TypeItem getTypeObject() const {return tAlien;}
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
