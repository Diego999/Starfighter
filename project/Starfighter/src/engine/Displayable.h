#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "DisplayEngine.h"
#include "Trajectoire.h"
#include "Qt/QPixMap.h"
#include "Qt/QRectF.h"
#include "Qt/QPainterPath.h"
#include "Qt/QPainter.h"
#include "Qt/QStyleOptionGraphicsItem.h"
#include "Qt/QWidget.h"

class Displayable : public DisplayEngine
{
private:
	DisplayEngine displayEngine;
	Trajectoire trajectoire;

protected:
	int x;

	int y;

	Qt::QPixMap pixmap;


protected:
	void advance(int step);

public:
	Qt::QRectF boundingRect();

	Qt::QPainterPath shape();

	Qt::QPixMap pixmap();

	void paint(Qt::QPainter* painter, Qt::QStyleOptionGraphicsItem* option, Qt::QWidget* widget);

	void Displayable(int x, int y, Qt::QPixMap* pixmap = 0);

};
#endif
