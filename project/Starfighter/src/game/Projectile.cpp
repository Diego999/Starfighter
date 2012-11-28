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

Projectile::Projectile(int _originX, int _originY,Shooter _from)
    :Displayable(_originX,_originY),
      originX(_originX),originY(_originY),from(_from)
{
    x = _originX;
    y = _originY;
}

QRectF Projectile::boundingRect() const
{
    qreal l_dAdjust = 0.5;
    return QRectF(originX - l_dAdjust, originY - l_dAdjust,
                  10 + l_dAdjust, 10 + l_dAdjust);
}

QPainterPath Projectile::shape() const
{
    QPainterPath l_path;
    l_path.addRect(originX,originY, 10, 10);
    return l_path;
}

void Projectile::paint(QPainter *_painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    _painter->setBrush(color);
    _painter->drawEllipse(0,0,10,10);
}

void Projectile::advance(int _step)
{
    if (!_step)
        return;
}

