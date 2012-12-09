#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "include/game/Displayable.h"
#include "include/enum/Enum.h"

class Obstacle : public virtual Displayable
{
    //Q_OBJECT

public:
    Obstacle(int x, int y);

   /* virtual QRectF boundingRect() const=0;
    virtual QPainterPath shape() const=0;
    virtual void paint(QPainter* _painter, QStyleOptionGraphicsItem* _option, QWidget* _widget)=0;*/
//protected:
    //qreal trajectoryDraw(qreal x);


};
#endif
