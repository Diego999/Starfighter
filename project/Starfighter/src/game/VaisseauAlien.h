#ifndef VAISSEAU_ALIEN_H
#define VAISSEAU_ALIEN_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Obstacle.h"
#include "Destroyable.h"

class VaisseauAlien : public Obstacle, public Destroyable
{
};
#endif
