#ifndef DESTROYABLE_H
#define DESTROYABLE_H

#include <QObject>

class Destroyable : public QObject
{
public:
	Destroyable();
	void receiveAttack(int puissance);
	
protected:
	int resistance;
	int healthPoint;
};
#endif
