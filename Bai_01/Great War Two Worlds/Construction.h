#include "Monster.h"

//------------CLASS CONSTRUCTION------------
class Construction
{
protected:
	int x, y;
	string name;
public:
	Construction();

	//Getter
	int getX();
	int getY();

	//Input, Output
	void input();
	void output();

	//Use to distinguish between each other
	virtual string getType();
};


//------------CLASS SPECIALCONSTRUCTION------------
class SpecialConstruction:public Construction
{
public:
	SpecialConstruction();
	string getType();
};


//------------CLASS CLONECONSTRUCTION------------
class CloneConstruction :public Construction
{
public:
	CloneConstruction();
	string getType();
};
