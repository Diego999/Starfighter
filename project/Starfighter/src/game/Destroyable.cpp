#include "include/game/Destroyable.h"

Destroyable::Destroyable(qreal _dHealthPoint,qreal _dResistance)
    :QObject(),
      dHealthPoint(_dHealthPoint),dResistance(_dResistance)
{

}

void Destroyable::receiveAttack(qreal _dPower, int point, Shooter forShip)
{
    this->pointToGive = point;
    this->forShip = forShip;
    dHealthPoint -= _dPower/dResistance;
    isDead();
}

void Destroyable::isDead()
{
    if(dHealthPoint<=0)
        emit destroyed(this,pointToGive,forShip);
}
