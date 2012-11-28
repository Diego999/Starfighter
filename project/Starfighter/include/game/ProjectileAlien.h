/*=====================================================================*
 | Declaration file ProjectileAlien.h
 |    declares :  ProjectileAlien class
 |
 | For more informations (creation date, creator, etc.), please see the
 | corresponding .cpp file
 |
 *=====================================================================*/

#ifndef PROJECTILE_ALIEN_H
#define PROJECTILE_ALIEN_H

#include "include/game/Projectile.h"

/**
* Class that represents a projectile throwed by an alien-spaceship
* An alien projectile is a king of a swirl
* @author Diego Antognini
* @version 0.0.1
*/

class ProjectileAlien : public Projectile
{
public:
    ProjectileAlien(int _originX, int _originY, qreal _dArgument, qreal _dModule, Shooter _from);

private:
    void advance(int step);

    static const qreal kIntervalModule = 0.5;
    static const qreal kIntervalArgument = 1.0;

    qreal dArgument;
    qreal dModule;
};
#endif
