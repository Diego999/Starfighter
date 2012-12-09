#include "include/game/Asteroid.h"
#include "include/engine/DisplayEngine.h"
#include <QDebug>

#define SPEED_A 1

Asteroid::Asteroid(int _x, int _y,Shooter from, int _resistance, int _healthPoint,GameEngine *_ge,qreal _slope)
    :Displayable(_x,_y),Destroyable(),Obstacle(x,y),Projectile(x,y,from),resistance(_resistance),healthPoint(_healthPoint),ge(_ge),slope(_slope)
{
    if(slope!=0)
        pxmPicture = new QPixmap(":/images/game/asteroids/rock20000");
    else
    {
        pxmPicture = new QPixmap(":/images/game/asteroids/rock10000");
        int xmin = ge->displayEngine()->warzoneValueMin().x();
        int ymin = ge->displayEngine()->warzoneValueMin().y();

        int xmax = ge->displayEngine()->warzoneValueMax().x();
        int ymax = ge->displayEngine()->warzoneValueMax().y();

        int xc = (xmax-xmin)/2+xmin;
        int yc = (ymax-ymin)/2+ymin;

        int xg = ge->randInt(xmax-xmin)+xmin;
        int yg = ge->randInt(2);

        //LEFT
        if(xg <= xc)
        {
            direction = 1;
            int xl = xmax+(xmax-xc)/2;
            int xf = ge->randInt(xl-xc)+xc;
            if(yg == 0)//Top Left
                slope = -ymax/(double)(xf-xg);
            else
                slope = ymax/(double)(xf-xg);
        }
        //RIGHT
        else
        {
            direction = -1;
            int xl = xmin-(xc-xmin)/2;
            int xf = ge->randInt(xc-xl)-xl;
            if(yg == 0)//Top Left
                slope = -ymax/(double)(xf-xg);
            else
                slope = ymax/(double)(xf-xg);
        }
        x=xg;
        if(yg == 0)
            y = ymin;
        else
            y = ymax;

        setPos(x,y);
    }
}

Asteroid::~Asteroid()
{

}

void Asteroid::destroy()
{
}

QRectF Asteroid::boundingRect() const
{
    return QRectF(pxmPicture->rect());
}

QPainterPath Asteroid::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Asteroid::paint(QPainter* _painter, QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    _painter->drawPixmap(0,0,*pxmPicture);
}

void Asteroid::advance(int _step)
{
    Obstacle::advance(_step);

    y-=trajectoryDraw(SPEED_A);
    x+=direction*SPEED_A;
    setPos(x,y);
    qDebug() << x << " " << y;
}

qreal Asteroid::trajectoryDraw(qreal _dX)
{
    return slope*_dX;
}

