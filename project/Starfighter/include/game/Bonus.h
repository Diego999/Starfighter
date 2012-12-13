#ifndef BONUS_H
#define BONUS_H

#include "include/game/Displayable.h"

class GameEngine;
class Spaceship;

class Bonus : public QObject, public Displayable
{
    Q_OBJECT
public:
    Bonus(GameEngine *_gameEngine, Spaceship *_spaceShip);
    virtual ~Bonus();

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* _painter,const QStyleOptionGraphicsItem* _option, QWidget* _widget);
    void advance(int _step);

private slots:
    void playSound();

private:
    GameEngine *gameEngine;
    Spaceship *spaceship;

    static const qreal kIntervalArgument = 0.10;

    qreal dYStop;
    qreal dArgument;
    qreal dModule;
    qreal dX0;
    qreal dY0;
    int directionX;
    int direction;
};
#endif
