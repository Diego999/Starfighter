/*==============================================================*
 | Implementation file ProjectileAlien.cpp
 |    implements : ProjectileAlien class
 |
 | Creator : Diego Antognini
 | Creation date : 26/11/2012
 | Copyright: EIAJ, all rights reserved
 |
 | Version of the file : 0.0.1
 |
 *==============================================================*/

#include "include/game/Projectile.h"
#include <QDebug>

Projectile::Projectile(int _originX, int _originY,Shooter _from)
    :Displayable(_originX,_originY),
      originX(_originX),originY(_originY),from(_from)
{
    if(from == Player1)
        color = QColor(100,100,100);
    else
        color = QColor(200,200,200);
}

Projectile::~Projectile()
{

}

QRectF Projectile::boundingRect() const
{
    return QRectF(-RADIUS_PROJECTILE/2,-RADIUS_PROJECTILE/2,RADIUS_PROJECTILE,RADIUS_PROJECTILE);
}

QPainterPath Projectile::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(-RADIUS_PROJECTILE/2,-RADIUS_PROJECTILE/2,RADIUS_PROJECTILE,RADIUS_PROJECTILE);
    return l_path;
}

void Projectile::paint(QPainter *_painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    _painter->setBrush(color);
    _painter->drawEllipse(-RADIUS_PROJECTILE/2,-RADIUS_PROJECTILE/2,RADIUS_PROJECTILE,RADIUS_PROJECTILE);
    _painter->setPen(QPen(QColor(255,0,0)));
    _painter->drawPath(shape());
}

void Projectile::advance(int _step)
{
    Displayable::advance(_step);
}

