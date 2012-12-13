#include "include/game/Destroyable.h"

Destroyable::Destroyable(qreal _dHealthPoint,qreal _dResistance)
    :QObject(),
      dHealthPoint(_dHealthPoint),dResistance(_dResistance)
{

}

Destroyable::~Destroyable()
{

}

void Destroyable::receiveAttack(qreal _dPower)
{
    dHealthPoint = dHealthPoint-_dPower/dResistance;
    isDead();
}

void Destroyable::isDead()
{
    if(dHealthPoint<=0)
        emit destroyed(this);
}
