/*==============================================================*
 | Implementation file Supernova.cpp
 |        implements : Supernova class
 |
 |
 | summary : Entity class that represents an supernova.
 |           For more information, please consult the specification file
 |
 | Creator : Diego Antognini
 | Creation date : 27/11/2012
 | Copyright: EIAJ, all rights reserved
 |
 |
 | Version of the file : 1.0.0
 |
 *==============================================================*/

#include "include/engine/GameEngine.h"

#include "include/game/Supernova.h"
#include "include/game/ProjectileAlien.h"

Supernova::Supernova(qreal _dX, qreal _dY,GameEngine *_gameEngine):
    gameEngine(_gameEngine),//GameEngine
    dX(_dX),
    dY(_dY)
{
}

Supernova::~Supernova()
{
    for(int i = 0;i<nbSpirales;i++)
        gameEngine->addProjectile(new ProjectileAlien(dX,dY,Other,static_cast<double>(2*M_PI)/nbSpirales*(i+1),0));
}
