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
    Spaceship(int x,int y,Shooter _player,GameEngine *ge);
    ~Spaceship();
    void receiveAttack(int puissance);
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
	QString playerName;
    Shooter player;
	qreal speed;

    TypeProjectiles type;
	int resistanceForceField;

    BonusSpeed *bonusSpeed;
    BonusProjectile *bonusProjectile;
    GameEngine *gameEngine;
};
#endif
