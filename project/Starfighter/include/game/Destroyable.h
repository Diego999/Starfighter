#ifndef DESTROYABLE_H
#define DESTROYABLE_H

class Destroyable : public QObject
{
    Q_OBJECT
public:
    Destroyable(qreal _healthPoint,qreal _resistance);
    virtual ~Destroyable();

    virtual void receiveAttack(qreal power);
    void isDead();

signals:
    void destroyed(Destroyable* destroyItem);
protected:
    qreal healthPoint;
    qreal resistance;

};
#endif
