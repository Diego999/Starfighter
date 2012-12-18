#ifndef DESTROYABLE_H
#define DESTROYABLE_H

class Destroyable : public QObject
{
    Q_OBJECT
public:
    Destroyable(qreal _dHealthPoint,qreal _dResistance);
    virtual ~Destroyable() {}

    virtual void receiveAttack(qreal _dPower);
    void isDead();

signals:
    void destroyed(Destroyable* _destroyItem);
protected:
    qreal dHealthPoint;
    qreal dResistance;

};
#endif
