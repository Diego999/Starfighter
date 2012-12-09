#include "include/game/AlienSpaceship.h"
#include <math.h>

AlienSpaceship::AlienSpaceship(QPoint P1, QPoint P2, QPoint P3, int nbSpirales)
    :Displayable(P1.x(),P2.y()),Obstacle(P1.x(),P1.y()),Destroyable()
{
    int x1 = P1.x();
    int x2 = P2.x();
    int x3 = P3.x();
    int y1 = P1.y();
    int y2 = P2.y();
    int y3 = P3.y();

    dX0 = (x3*x3*(y2-y1)+x2*x2*(y1-y3)-(x1*x1+(y1-y2)*(y1-y3))*(y2-y3))
            /(2*(x3*(y2-y1)+x2*(y1-y3)+y1*(y3-y2)));
    dY0 = (-x2*x2*x3+x1*x1*(-x2+x3)+x3*(y1*y1-y2*y2)+y1*(x2*x2-x3*x3+y2*y2-y3*y3)+x2*(x3*x3-y1*y1+y3*y3))
            /(2*(x3*(y1-y2)+x1*(y2-y3)+x2*(-y1+y3)));
    dModule = sqrt((x1-dX0)*(x1-dX0)+(y1-dY0)*(y1-dY0));

    dTheta = acos((dX0+x1)/dModule);
}

void AlienSpaceship::advance(int _step)
{
    Obstacle::advance(_step);

    dTheta-=kIntervalArgument;

    x = dX0+dModule*cos(dArgument*M_PI/180.0);
    y = dY0-dModule*sin(dArgument*M_PI/180.0);

    setPos(x,y);
}

QRectF AlienSpaceship::boundingRect() const
{
    int l_width = pxmPicture->rect().width();
    int l_height = pxmPicture->rect().height();

    return QRectF(QPoint(x,y),QPoint(x+l_width,y+l_height));
}

QPainterPath AlienSpaceship::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void AlienSpaceship::paint(QPainter* _painter, QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    _painter->drawPixmap(x,y,*pxmPicture);
}
