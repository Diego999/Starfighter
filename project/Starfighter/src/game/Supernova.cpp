#include "include/game/Supernova.h"
#include "include/game/ProjectileAlien.h"
#include "include/engine/GameEngine.h"
#include "include/engine/DisplayEngine.h"
#include "include/enum/Enum.h"

Supernova::Supernova(qreal _dX, qreal _dY,GameEngine *_gameEngine):
    Displayable(_dX,_dY),
    Obstacle(_dX,_dY),
    gameEngine(_gameEngine)
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

Supernova::~Supernova()
{
    for(int i = 0;i<nbSpirales;i++)
        gameEngine->addProjectile(new ProjectileAlien(pos().x(),pos().y(),Other,360.0/nbSpirales*(i+1),0));
}
