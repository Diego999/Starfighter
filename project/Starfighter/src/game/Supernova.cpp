#include "include/game/Supernova.h"
#include "include/game/ProjectileAlien.h"
#include "include/enum/Enum.h"

Supernova::Supernova(qreal x, qreal y,GameEngine *ge):Displayable(x,y),Obstacle(x,y),gameEngine(ge)
{
}

QRectF Supernova::boundingRect() const
{
    return QRectF(0,0,0,0);
}

QPainterPath Supernova::shape() const
{
    QPainterPath l_path;
    l_path.addEllipse(boundingRect());
    return l_path;
}

void Supernova::paint(QPainter *_painter, const QStyleOptionGraphicsItem *, QWidget *)
{

}

Supernova::~Supernova()
{
    for(int i = 0;i<nbSpirales;i++)
        gameEngine->displayEngine()->addProjectile(new ProjectileAlien(x,y,Other,(i+1),0));
}
