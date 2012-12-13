#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "include/game/Destroyable.h"
#include "include/game/Displayable.h"
#include "include/enum/Enum.h"

#define MAX_SPACESHIP_BONUS 2
#define MAX_SPACESHIP_PV 100
#define AMPLI_SPACESHIP_PROJ_V 60.0
#define OMEGA_SPACESHIP_PROJ_V 1.0
#define PROJ_SPACESHIP_DEF ProjSimple

class Bonus;
class BonusSpeed;
class BonusProjectile;
class GameEngine;

class Spaceship : public Destroyable, public virtual Displayable
{
    Q_OBJECT
public:
    Spaceship(qreal _dX,qreal _dY,Shooter _player,const QString& _playerName,qreal _dSpeed,qreal _dHealthPoint,qreal _dResistance,qreal _dResistanceForceField,GameEngine *_gameEngine);
    ~Spaceship();

    void receiveAttack(qreal _dPower);
    void attack();
    void top();
    void bottom();

    Shooter getTypeObject() const {return player;}

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
    qreal dSpeed;

    TypeProjectiles type;
    qreal dHealthForceField;
    qreal dResistanceForceField;

    BonusSpeed *bonusSpeed;
    BonusProjectile *bonusProjectile;
    GameEngine *gameEngine;
};
#endif
