#ifndef BONUS_H
#define BONUS_H

#include "include/game/Displayable.h"

class GameEngine;

#define DELTA_X_B 100
#define NB_SEC 1

class Bonus : public QObject, public Displayable
{
    Q_OBJECT
public:
    Bonus(GameEngine *_gameEngine);
    virtual ~Bonus() {}

    TypeItem getTypeObject() const {return tBonus;}
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int _step);

private slots:
    void playSound();

private:
    GameEngine *gameEngine;

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
