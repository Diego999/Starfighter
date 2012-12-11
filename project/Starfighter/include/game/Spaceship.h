#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "include/game/Destroyable.h"
#include "include/game/Displayable.h"
#include "include/game/Bonus.h"
#include "include/engine/GameEngine.h"
#include "include/enum/Enum.h"

#define MAX_BONUS 2
#define MAX_PV 100

class BonusSpeed;
class BonusProjectile;

class Spaceship : public Destroyable, public virtual Displayable
{
    Q_OBJECT

public:
    Spaceship(qreal x,qreal y,Shooter _player,QString _playerName,qreal _speed,qreal _healthPoint,qreal _resistance,qreal _resistanceForceField,GameEngine *ge);
    ~Spaceship();
    void receiveAttack(qreal power);
    void attack();
    void top();
    void bottom();

    void addBonus(Bonus* bonus);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private slots:
    void removeSpeedBonus();
    void removeProjectileBonus();

private:
    Shooter player;
	QString playerName;
	qreal speed;

    TypeProjectiles type;
    qreal resistanceForceField;

    BonusSpeed *bonusSpeed;
    BonusProjectile *bonusProjectile;
    GameEngine *gameEngine;
};
#endif
