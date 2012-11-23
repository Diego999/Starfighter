#ifndef SUPERNOVA_H
#define SUPERNOVA_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Obstacle.h"

class Supernova : public Obstacle
{
private:
	static int nbSpirales;


public:
	void Supernova(int x, int y);

};
#endif
