#ifndef SUPERNOVA_H
#define SUPERNOVA_H

#include "Obstacle.h"

class Supernova : public Obstacle
{
	Q_OBJECT
public:
	void Supernova(int x, int y);

private:
	static const int nbSpirales = 360;

};
#endif
