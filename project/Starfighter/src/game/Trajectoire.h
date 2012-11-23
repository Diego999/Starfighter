#ifndef TRAJECTOIRE_H
#define TRAJECTOIRE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Displayable.h"
#include "Qt/QPoint.h"

class Trajectoire
{
private:
	Displayable displayable[];

public:
	Qt::QPoint getPositionAtTime(int time);

};
#endif
