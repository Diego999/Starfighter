#ifndef DESTROYABLE_H
#define DESTROYABLE_H

#include "include/enum/Enum.h"

class Destroyable : public QObject
{
    Q_OBJECT
public:
    Destroyable(qreal _dHealthPoint,qreal _dResistance);
    virtual ~Destroyable() {}

    virtual void receiveAttack(qreal _dPower,int point,Shooter forShip);
    void isDead();

signals:
    void destroyed(Destroyable* _destroyItem,int nbPoint,Shooter forShip);
protected:
    qreal dHealthPoint;
    qreal dResistance;
    int pointToGive;
    Shooter forShip;

};
#endif
