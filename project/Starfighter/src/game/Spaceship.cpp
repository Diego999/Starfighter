#include "include/game/Spaceship.h"
#include "include/game/ProjectileCross.h"
#include "include/game/ProjectileSimple.h"
#include "include/game/ProjectileV.h"
#include "include/game/BonusForceField.h"
#include "include/game/BonusHP.h"
#include "include/game/BonusProjectile.h"
#include "include/game/BonusSpeed.h"
#include "include/engine/DisplayEngine.h"

Spaceship::Spaceship(qreal _dX,qreal _dY,Shooter _player,const QString& _playerName,qreal _dSpeed,qreal _dHealthPoint,qreal _dResistance,qreal _dResistanceForceField,GameEngine *_gameEngine)
    :Displayable(_dX,_dY),
      Destroyable(_dHealthPoint,_dResistance),
      player(_player),playerName(_playerName),dSpeed(_dSpeed),dResistanceForceField(_dResistanceForceField),gameEngine(_gameEngine)
{
    type = PROJ_SPACESHIP_DEF;
    bonusSpeed = 0;
    bonusProjectile = 0;
    setPixmap(new QPixmap(":/images/game/spaceship"));

    if(_player == Player2)
    {
        setPixmap(new QPixmap(getPixmap()->transformed(QTransform().rotate(180))));
        setPos(_dX-getPixmap()->size().width(),_dY);
    }
}

Spaceship::~Spaceship()
{
    delete bonusSpeed;
    delete bonusProjectile;
}

QRectF Spaceship::boundingRect() const
{
    return QRectF(getPixmap()->rect());
}

QPainterPath Spaceship::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Spaceship::paint(QPainter *_painter,const QStyleOptionGraphicsItem *_option, QWidget *_widget)
{
    _painter->drawPixmap(0,0,*getPixmap());
    _painter->setPen(QPen(QColor(255,0,0)));
    _painter->drawPath(shape());
}

void Spaceship::addBonus(Bonus *bonus)
{
    if(BonusHP* bhp = dynamic_cast<BonusHP*>(bonus))
    {
        dHealthPoint+=bhp->getHealthPoint();
        if(dHealthPoint>MAX_SPACESHIP_PV)
            dHealthPoint=MAX_SPACESHIP_PV;
        delete bhp;
    }
    else if(BonusProjectile* bp = dynamic_cast<BonusProjectile*>(bonus))
    {
        if(bonusSpeed==NULL)
        {
            type = bp->getType();
            bonusProjectile = bp;
            QTimer::singleShot(bp->getExpiration(),this,SLOT(removeProjectileBonus()));
        }
    }
    else if(BonusForceField* bff = dynamic_cast<BonusForceField*>(bonus))
    {
        dResistanceForceField+=bff->getResistanceForceField();
        if(dResistanceForceField>MAX_SPACESHIP_PV)
            dResistanceForceField = MAX_SPACESHIP_PV;
        delete bff;
    }
    else if(BonusSpeed* bs = dynamic_cast<BonusSpeed*>(bonus))
    {
        if(bonusSpeed==NULL)
        {
            bonusSpeed = bs;
            dSpeed+=bs->getSpeed();
            QTimer::singleShot(bs->getExpiration(),this,SLOT(removeSpeedBonus()));
        }
    }
}

void Spaceship::removeProjectileBonus()
{
    delete bonusProjectile;
    bonusProjectile = NULL;
    type = PROJ_SPACESHIP_DEF;
}

void Spaceship::removeSpeedBonus()
{
    dSpeed-=bonusSpeed->getSpeed();
    delete bonusSpeed;
    bonusSpeed = NULL;
}

void Spaceship::receiveAttack(qreal power)
{
    //TODO
    isDead();
}

void Spaceship::attack()
{
    int l_x = 0;
    int l_y = 0;

    if(player==Player1)
        l_x = pos().x()+getPixmap()->width();
    else
        l_x = pos().x();//Don't need to remove the width of the QPixmap,already done in the constructor

    l_y = pos().y()+getPixmap()->height()/2;

    switch(type)
    {
        case ProjSimple:
            gameEngine->displayEngine()->addProjectile(new ProjectileSimple(l_x,l_y,player));
            break;

        case ProjCross:
            for(int i = 0;i<3;i++)
                gameEngine->displayEngine()->addProjectile(new ProjectileCross(l_x,l_y,player,i-1));
            break;

        case ProjV:
            gameEngine->displayEngine()->addProjectile(new ProjectileV(l_x,l_y,player,AMPLI_SPACESHIP_PROJ_V,AMPLI_SPACESHIP_PROJ_V));
            break;
        case ProjAlien:
            break;

        case Nothing:
            break;
    }
}

void Spaceship::top()
{
    setPos(pos().x(),pos().y()-dSpeed);
}

void Spaceship::bottom()
{
    setPos(pos().x(),pos().y()+dSpeed);
}
