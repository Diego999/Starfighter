#ifndef SUPERNOVA_H
#define SUPERNOVA_H

#include "include/game/Obstacle.h"

class GameEngine;

class Supernova : public Obstacle
{
public:
    Supernova(qreal _dX, qreal _dY,GameEngine *_gameEngine);
    ~Supernova();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget=0);

private:
	static const int nbSpirales = 360;

    GameEngine* gameEngine;
};
#endif
