#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "include/game/Destroyable.h"
#include "include/game/Displayable.h"
#include "include/game/Bonus.h"
#include "include/engine/GameEngine.h"
#include "include/enum/Enum.h"

class Spaceship : public Destroyable, public Displayable
{
    //Q_OBJECT

public:
    Spaceship(int x,int y,GameEngine *ge);
	void attack(int puissance);
	void top(int step);
	void bottom(int step);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* _painter, QStyleOptionGraphicsItem* _option, QWidget* _widget);

private:
	QString playerName;
	qreal speed;

	int resistanceForceField;

    Bonus *bonus[3];
    GameEngine *gameEngine;
};
#endif
