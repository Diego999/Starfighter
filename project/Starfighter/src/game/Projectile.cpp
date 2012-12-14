#include "include/game/Projectile.h"

Projectile::Projectile(qreal _XOrigin, qreal _YOrigin,Shooter _from)
    :Displayable(_XOrigin,_YOrigin),
      dXOrigin(_XOrigin),dYOrigin(_YOrigin),from(_from)
{
    if(from == Player1)
        color = new QColor(0,0,255);
    else if(from == Player2)
        color = new QColor(255,0,0);
    else if(from == Other)
        color = new QColor(qrand() % 256, qrand() % 256, qrand() % 256);
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
    _painter->setBrush(*color);
    _painter->drawEllipse(-RADIUS_PROJECTILE/2,-RADIUS_PROJECTILE/2,RADIUS_PROJECTILE,RADIUS_PROJECTILE);
    _painter->setPen(QPen(QColor(0,255,0)));
    _painter->drawPath(shape());
}

void Projectile::advance(int _step)
{
    Displayable::advance(_step);
}

