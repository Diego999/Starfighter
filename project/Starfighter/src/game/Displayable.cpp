#include "include/game/Displayable.h"

Displayable::Displayable(qreal _x, qreal _y, QPixmap* _pxmPicture)
    :x(_x),y(_y),pxmPicture(_pxmPicture)
{
    setPos(x,y);
}

Displayable::~Displayable()
{
    delete pxmPicture;
}

void Displayable::advance(int _step)
{
    if (!_step)
        return;
}

void Displayable::setPos(qreal _dX, qreal _dY)
{
    x=_dX;
    y=_dY;
    QGraphicsItem::setPos(x,y);
}
