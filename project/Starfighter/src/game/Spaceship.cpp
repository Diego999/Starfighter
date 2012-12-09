#include "include/game/Spaceship.h"
#include "include/game/ProjectileCross.h"
#include "include/game/ProjectileSimple.h"
#include "include/game/ProjectileV.h"
#include "include/game/BonusForceField.h"
#include "include/game/BonusHP.h"
#include "include/game/BonusProjectile.h"
#include "include/game/BonusSpeed.h"
#include "include/engine/DisplayEngine.h"

#include <QTimer>
#include <QDebug>

#define AMPLI_PV 3
#define OMEGA_PV 15

Spaceship::Spaceship(int x,int y,Shooter _player,GameEngine *ge):Displayable(x,y),player(_player),gameEngine(ge)
{
    type = ProjSimple;
    pxmPicture = new QPixmap(":/images/game/spaceship");
    if(_player == Player2)
    {
        *pxmPicture = pxmPicture->transformed(QTransform().rotate(180));
        x-=pxmPicture->size().width();
        setPos(x,y);
    }
}

Spaceship::~Spaceship()
{
    delete bonusSpeed;
    delete bonusProjectile;
}

QRectF Spaceship::boundingRect() const
{
    return QRectF(pxmPicture->rect());
}

QPainterPath Spaceship::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Spaceship::paint(QPainter *_painter,const QStyleOptionGraphicsItem *_option, QWidget *_widget)
{
    _painter->drawPixmap(0,0,*pxmPicture);
    _painter->setPen(QPen(QColor(255,0,0)));
    _painter->drawPath(shape());
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

void Spaceship::receiveAttack(int puissance)
{

}

void Spaceship::attack()
{
    int l_x = 0;
    int l_y = 0;

    if(player==Player1)
        l_x = x+pxmPicture->width();
    else
        l_x = x-pxmPicture->width();

    l_y = y+pxmPicture->height()/2;

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
            gameEngine->displayEngine()->addProjectile(new ProjectileV(l_x,l_y,player,AMPLI_PV,OMEGA_PV));
            break;
        case ProjAlien:
            break;

        case Nothing:
            break;
    }
}

void Spaceship::top()
{
    y-=speed;
}

void Spaceship::bottom()
{
    y+=speed;
}
