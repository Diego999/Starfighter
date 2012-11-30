#include "include/game/Spaceship.h"
#include "include/engine/DisplayEngine.h"

Spaceship::Spaceship(int x,int y,GameEngine *ge):Displayable(x,y)
{

}

QRectF Spaceship::boundingRect() const
{
    int l_width = pxmPicture->rect().width();
    int l_height = pxmPicture->rect().height();

    return QRectF(QPoint(x-l_width/2,y-l_height/2),QPoint(x+l_width/2,y+l_height/2));
}

QPainterPath Spaceship::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Spaceship::paint(QPainter *_painter,QStyleOptionGraphicsItem *_option, QWidget *_widget)
{
    QRect l_rectSize = gameEngine->displayEngine()->sceneSize();

    if(x<l_rectSize.width()/2)
        _painter->drawPixmap(x,y-pxmPicture->height()/2,*pxmPicture);
    else//Player2
        _painter->drawPixmap(x-pxmPicture->width(),y-pxmPicture->height()/2,*pxmPicture);
}

void Spaceship::attack(int puissance)
{
}

void Spaceship::top(int step)
{
}

void Spaceship::bottom(int step)
{
}
