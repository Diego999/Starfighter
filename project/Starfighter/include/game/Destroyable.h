#ifndef DESTROYABLE_H
#define DESTROYABLE_H

class Destroyable : public QObject
{
public:
	Destroyable();
    virtual ~Destroyable();

	void receiveAttack(int puissance);
	
protected:
	int resistance;
	int healthPoint;
};
#endif
