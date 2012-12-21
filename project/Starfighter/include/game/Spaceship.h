#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "include/game/Destroyable.h"
#include "include/game/Displayable.h"

#include "include/enum/Enum.h"

class Bonus;
class BonusSpeed;
class BonusProjectile;
class GameEngine;
class QTimer;

class Spaceship : public Destroyable, public virtual Displayable
{
    Q_OBJECT
public:
    Spaceship(qreal _dX,qreal _dY,Shooter _player,const QString& _playerName,qreal _dSpeed,qreal _dHealthPoint,qreal _dResistance,GameEngine *_gameEngine);
    ~Spaceship();

    void receiveAttack(qreal _dPower);
    void attack();
    void top();
    void bottom();

    TypeItem getTypeObject() const {return tSpaceship;}
    Shooter getPlayer() const {return player;}
    QString getPlayerName() const {return playerName;}
    qreal getHealthPoint() const {return dHealthPoint;}
    qreal getHealthForceField() const {return dHealthForceField;}
    BonusSpeed* getBonusSpeed() const {return bonusSpeed;}
    BonusProjectile* getBonusProjectile() const {return bonusProjectile;}
    qreal getPercentageSpeed() const;
    void addPoint(int point);
    int getScore() const{return score;}

    void setPixmap(QPixmap* _pxmPixmap);
    void addBonus(Bonus* _bonus);
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
    int score;

    TypeProjectiles type;
    qreal dHealthForceField;
    qreal dResistanceForceField;

    QTimer *timerProjectile;

    BonusSpeed *bonusSpeed;
    BonusProjectile *bonusProjectile;
    GameEngine *gameEngine;
};
#endif
