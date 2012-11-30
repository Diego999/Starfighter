#include "include/game/Displayable.h"

Displayable::Displayable(int _x, int _y, QPixmap* _pxmPicture)
    :x(_x),y(_y),pxmPicture(_pxmPicture)
{
    setPos(x,y);
}

void Displayable::advance(int _step)
{
    if (!_step)
        return;
}

void Displayable::setPos(qreal _dX, qreal _dY)
{
    QGraphicsItem::setPos(_dX,_dY);
}

