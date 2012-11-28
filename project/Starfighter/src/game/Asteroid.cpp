#include "include/game/Asteroid.h"

Asteroid::Asteroid(int x, int y, int resistance, int healthPoint,Shooter from):Obstacle(x,y),Projectile(x,y,from)
{
}

void Asteroid::destroy()
{
}

