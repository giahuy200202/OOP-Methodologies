#include "Construction.h"

//------------CLASS HERO------------
class Hero
{
protected:
	int x, y;
	string name;
	double hp;
	int level;
	double attack, defend; // atk status, def status
public:
	//Setter
	void setXY(int, int);
	void setHp(double);
	virtual void setLevel();

	//Getter
	int getX();
	int getY();
	int getLevel();
	string getName();
	double getHP();
	double getAttack();
	double getDefend();
	
	//Input, output
	virtual void input();
	void output();

	//Check impact
	bool isImpactMonster(Monster*); // Impact with monsters
	bool isImpactHero(Hero*); // Impact with other heroes
	bool isImpactLevelConstruction(Construction*); // Impact with level construction
	bool isImpactCloneConstruction(Construction*); // Impact with clone construction
};


//------------CLASS ATTACKHERO------------
class AttackHero : public Hero
{
public:
	AttackHero();
	AttackHero(int, int, string, double, int, double, double);
	void input();
	void setLevel();
};


//------------CLASS DEFENDHERO------------
class DefendHero : public Hero
{
public:
	DefendHero();
	DefendHero(int, int, string, double, int, double, double);
	void input();
	void setLevel();
};


