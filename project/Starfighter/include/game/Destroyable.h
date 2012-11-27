#ifndef DESTROYABLE_H
#define DESTROYABLE_H


class Destroyable
{
    Q_OBJECT

public:
	Destroyable();
	void receiveAttack(int puissance);
	
protected:
	int resistance;
	int healthPoint;
};
#endif
