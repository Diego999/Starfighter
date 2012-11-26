#include "Projectile.h"

Projectile::Projectile(int _originX, int _originY,Shooter _from)
    :Displayable(_originX,_originY),originX(_originX),originY(_originY),from(_from)
{
    x = _originX;
    y = _originY;
}

QRectF Projectile::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(originX - adjust, originY - adjust,
                  10 + adjust, 10 + adjust);
}

QPainterPath Projectile::shape() const
{
    QPainterPath path;
    path.addRect(originX,originY, 10, 10);
    return path;
}

void Projectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(color);
    painter->drawEllipse(0,0,10,10);
}

void Projectile::advance(int step)
{
    if (!step)
        return;
}

