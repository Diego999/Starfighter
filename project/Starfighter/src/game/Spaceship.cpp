#include "include/game/Spaceship.h"
#include "include/engine/DisplayEngine.h"
#include "include/game/BonusForceField.h"
#include "include/game/BonusHP.h"
#include "include/game/BonusProjectile.h"
#include "include/game/BonusSpeed.h"

#include <QTimer>
#include <QList>

Spaceship::Spaceship(int x,int y,Shooter _player,GameEngine *ge):Displayable(x,y)
{
    pxmPicture->load(":/images/game/ship.png");
    if(_player == Player2)
        *pxmPicture = pxmPicture->transformed(QTransform().rotate(180));
}

QRectF Spaceship::boundingRect() const
{
    int l_width = pxmPicture->rect().width();
    int l_height = pxmPicture->rect().height();

    return QRectF(QPoint(x,y),QPoint(x+l_width,y+l_height));
}

QPainterPath Spaceship::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Spaceship::paint(QPainter *_painter,QStyleOptionGraphicsItem *_option, QWidget *_widget)
{
    QRect l_rectSize = gameEngine->displayEngine()->sceneSize();

    if(x<l_rectSize.width()/2)
        _painter->drawPixmap(x,y-pxmPicture->height()/2,*pxmPicture);
    else//Player2
        _painter->drawPixmap(x-pxmPicture->width(),y-pxmPicture->height()/2,*pxmPicture);
}

void Spaceship::addBonus(Bonus *bonus)
{
    if(BonusHP* bhp = dynamic_cast<BonusHP*>(bonus))
    {
        healthPoint+=bhp->getHealthPoint();
        if(healthPoint>MAX_PV)
            healthPoint=MAX_PV;
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
        resistanceForceField+=bff->getResistanceForceField();
        if(resistanceForceField>MAX_PV)
            resistanceForceField = MAX_PV;
        delete bff;
    }
    else if(BonusSpeed* bs = dynamic_cast<BonusSpeed*>(bonus))
    {
        if(bonusSpeed==NULL)
        {
            bonusSpeed = bs;
            speed+=bs->getSpeed();
            QTimer::singleShot(bs->getExpiration(),this,SLOT(removeSpeedBonus()));
        }
    }
}

void Spaceship::removeProjectileBonus()
{
    delete bonusProjectile;
    bonusProjectile = NULL;
}

void Spaceship::removeSpeedBonus()
{
    delete bonusSpeed;
    bonusSpeed = NULL;
}

void Spaceship::attack(int puissance)
{
}

void Spaceship::top(int step)
{
}

void Spaceship::bottom(int step)
{
}
