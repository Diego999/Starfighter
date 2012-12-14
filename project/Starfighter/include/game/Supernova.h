#ifndef SUPERNOVA_H
#define SUPERNOVA_H

#include "include/game/Obstacle.h"

class GameEngine;

#define NB_SPIRAL 180

class Supernova : public Obstacle
{
public:
    Supernova(qreal _dX, qreal _dY,GameEngine *_gameEngine);
    ~Supernova();

    TypeItem getTypeObject() const {return tSupernova;}
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    static const int nbSpirales = NB_SPIRAL;

    GameEngine* gameEngine;
};
#endif
