#ifndef BONUS_H_P_H
#define BONUS_H_P_H

#include "include/game/Bonus.h"

class BonusHP : public Bonus
{
    //Q_OBJECT

public:
    BonusHP(QPoint P1, QPoint P2, QPoint P3, /*qreal speed,*/int healthPoint, GameEngine *ge, Spaceship *ss);
    ~BonusHP();
    int getHealthPoint() const;
private:
	int healthPoint;
};
#endif
