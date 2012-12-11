#include "include/game/Asteroid.h"
#include "include/engine/DisplayEngine.h"
#include <QDebug>
#include <math.h>

#define SPEED_A 1
#define MAX_A 5
#define MIN_A 3

Asteroid::Asteroid(qreal _x, qreal _y,Shooter from, int _resistance, int _healthPoint,GameEngine *_ge,qreal _slope,bool small)
    :Displayable(_x,_y),Destroyable(),Obstacle(_x,_y),Projectile(_x,_y,from),resistance(_resistance),healthPoint(_healthPoint),ge(_ge),slope(_slope),smallA(small)
{
    if(smallA)
    {
        pxmPicture = new QPixmap(":/images/game/asteroids/rock20000");
        int left = ge->randInt(2);

        slope=tan(slope);
        if(left==0)
            direction = 1;
        else
            direction = -1;
    }
    else
    {
        pxmPicture = new QPixmap(":/images/game/asteroids/rock10000");
        qreal xmin = ge->displayEngine()->warzoneValueMin().x();
        qreal ymin = ge->displayEngine()->warzoneValueMin().y();

        qreal xmax = ge->displayEngine()->warzoneValueMax().x();
        qreal ymax = ge->displayEngine()->warzoneValueMax().y();

        qreal xc = (xmax-xmin)/2+xmin;
        qreal yc = (ymax-ymin)/2+ymin;

        qreal xg = ge->randInt(xmax-xmin)+xmin;
        qreal yg = ge->randInt(2);

        //LEFT
        if(xg <= xc)
        {
            direction = 1;
            qreal xl = xmax+(xmax-xc)/2;
            qreal xf = ge->randInt(xl-xc)+xc;
            if(yg == 0)//Top Left
                slope = -ymax/(xf-xg);
            else
                slope = ymax/(xf-xg);
        }
        //RIGHT
        else
        {
            direction = -1;
            qreal xl = xmin-(xc-xmin)/2;
            qreal xf = ge->randInt(xc-xl)-xl;
            if(yg == 0)//Top Left
                slope = -ymax/(xf-xg);
            else
                slope = ymax/(xf-xg);
        }
        x=xg;
        if(yg == 0)
            y = ymin;
        else
            y = ymax;
    }
}

Asteroid::~Asteroid()
{
    if(!smallA)
    {
        int nb = ge->randInt(MAX_A-MIN_A)+MIN_A;
        int res = 0;
        int hp = 0;

        for(int i = 0;i<nb;i++)
            ge->displayEngine()->addAsteroide(new Asteroid(x,y,Other,res,hp,ge,M_PI*2/(double)nb*i,true));
    }
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

void Asteroid::paint(QPainter* _painter,const QStyleOptionGraphicsItem* _option, QWidget* _widget)
{
    _painter->drawPixmap(0,0,*pxmPicture);
    _painter->setPen(QPen(QColor(255,0,0)));
    _painter->drawPath(shape());
}

void Asteroid::advance(int _step)
{
    Obstacle::advance(_step);

    y-=trajectoryDraw(SPEED_A);
    x+=direction*SPEED_A;
    setPos(x,y);
}

qreal Asteroid::trajectoryDraw(qreal _dX)
{
    return slope*_dX;
}

