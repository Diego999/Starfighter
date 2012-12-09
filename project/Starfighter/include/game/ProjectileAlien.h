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
    ProjectileAlien(int _originX, int _originY,Shooter _from, qreal _dArgument, qreal _dModule);
    ~ProjectileAlien();

private:
    void advance(int step);
    qreal trajectoryDraw(qreal _dX);

    static const qreal kIntervalModule = 1.0;
    static const qreal kIntervalArgument = 1.0;

    qreal dArgument;
    qreal dModule;
};
#endif
