#ifndef BONUS_FORCE_FIELD_H
#define BONUS_FORCE_FIELD_H

#include "include/game/Bonus.h"

class BonusForceField : public Bonus
{
    //Q_OBJECT

public:
    BonusForceField(QPoint P1, QPoint P2, QPoint P3, qreal speed,int resistanceForceField, GameEngine *ge, Spaceship *ss);
	
private:
	int resistanceForceField;
};
#endif
