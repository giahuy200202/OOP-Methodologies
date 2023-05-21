#ifndef _HERO_H_
#define _HERO_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Monster
{
protected:
	int x, y;
	string name;
	double hp;
	int level;
	double attack; // atk status
	double power; // power status
public:
	//Getter
	int getX();
	int getY();
	double getHP();
	double getAttack();
	double getPower() ;

	//Setter
	void setHp(double);

	//Input, output
	void input();
	void output();
};

class JungleMonster :public Monster
{
public:
	JungleMonster();
};
#endif
