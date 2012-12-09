#include "include/game/Asteroid.h"

Asteroid::Asteroid(int x, int y, int resistance, int healthPoint,Shooter from,GameEngine *ge,qreal slope)
    :Displayable(x,y),Destroyable(),Obstacle(x,y),Projectile(x,y,from)
{
    //TODO
    //fonction qui genère M & N, cf spéc P 11
    //Il faut avoir connaître la taille de la scène, comme dans spaceship

}

void Asteroid::destroy()
{
}

QRectF Asteroid::boundingRect() const
{
    int l_width = pxmPicture->rect().width();
    int l_height = pxmPicture->rect().height();

    return QRectF(QPoint(x,y),QPoint(x+l_width,y+l_height));
}

QPainterPath Asteroid::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Asteroid::paint(QPainter* _painter, QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    _painter->drawPixmap(x,y,*pxmPicture);
}

void Asteroid::advance(int _step)
{
    Obstacle::advance(_step);
}

qreal Asteroid::trajectoryDraw(qreal _dX)
{
    return 0;
}

