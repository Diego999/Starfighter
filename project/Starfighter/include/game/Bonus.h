#ifndef BONUS_H
#define BONUS_H

#include "include/game/Displayable.h"
#include "include/game/Spaceship.h"
#include "include/engine/GameEngine.h"

class Bonus : public QObject, public Displayable
{
    Q_OBJECT
public:
    Bonus(GameEngine *ge, Spaceship *ss);
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

    qreal yStop;
    qreal dArgument;
    qreal dModule;
    qreal dX0;
    qreal dY0;
    int directionX;
    int direction;
};
#endif
