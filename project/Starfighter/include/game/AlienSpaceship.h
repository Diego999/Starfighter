#ifndef ALIEN_SPACESHIP_H
#define ALIEN_SPACESHIP_H

#include "include/game/Obstacle.h"
#include "include/game/Destroyable.h"

class AlienSpaceship : public Obstacle, public Destroyable
{
    //Q_OBJECT
	
public:
    AlienSpaceship(QPoint P1, QPoint P2, QPoint P3, int nbSpirales);
	
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* _painter, QStyleOptionGraphicsItem* _option, QWidget* _widget);
private:
    void advance(int step);

    static const qreal kIntervalArgument = 1.0;

	int nbSpirales;

    qreal dArgument;
    qreal dModule;
    qreal dX0;
    qreal dY0;
    qreal dTheta;
};
#endif
