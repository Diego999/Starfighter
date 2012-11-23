#ifndef DESTROYABLE_H
#define DESTROYABLE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class Destroyable
{
protected:
	int resistance;

	int healthPoint;


public:
	void receiveAttack(int puissance);

};
#endif
