#include "include/game/Displayable.h"

Displayable::Displayable(qreal _dX, qreal _dY, QPixmap* _pixmap)
    :dX(_dX),dY(_dY),pxmPicture(_pixmap)
{
    setPos(dX,dY);
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
    dX=_dX;
    dY=_dY;
    QGraphicsItem::setPos(dX,dY);
}

void Displayable::setPixmap(QPixmap *_pxmPixmap)
{
    if(pxmPicture!=0)
        delete pxmPicture;
    pxmPicture = _pxmPixmap;
}
