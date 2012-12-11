#include "include/game/Destroyable.h"

Destroyable::Destroyable(qreal _healthPoint,qreal _resistance):QObject(),healthPoint(_healthPoint),resistance(_resistance)
{

}

Destroyable::~Destroyable()
{

}

void Destroyable::receiveAttack(qreal power)
{
    healthPoint = healthPoint-power/resistance;
    isDead();
}

void Destroyable::isDead()
{
    if(healthPoint<=0)
        emit destroyed(this);
}
