#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#define RADIUS_PROJECTILE 10

class Displayable : public QGraphicsItem
{
public:
    Displayable(qreal _x, qreal _y, QPixmap* _pixmap = 0);
    virtual ~Displayable();

    QSize sizePixmap() const {return isPixmap()?pxmPicture->size():QSize();}
    bool isPixmap() const {return !pxmPicture==0;}

    virtual QRectF boundingRect() const=0;
    virtual QPainterPath shape() const=0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    virtual void setPos(qreal x, qreal y);
    virtual void advance(int step);

protected:
    qreal x;
    qreal y;
    QPixmap* pxmPicture;
};
#endif
