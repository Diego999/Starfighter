#include "include/game/Bonus.h"

Bonus::Bonus(QPoint P1, QPoint P2, QPoint P3, /*qreal speed,*/ GameEngine *ge, Spaceship *ss):Displayable(x,y)
{
    pxmPicture = new QPixmap(":/images/game/bonus");
}

QRectF Bonus::boundingRect() const
{
    int l_width = pxmPicture->rect().width();
    int l_height = pxmPicture->rect().height();

    return QRectF(QPoint(x,y),QPoint(x+l_width,y+l_height));
}

QPainterPath Bonus::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Bonus::paint(QPainter* _painter, QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    _painter->drawPixmap(x,y,*pxmPicture);
}

void Bonus::trajectoryDraw(qreal x, qreal y)
{

}
