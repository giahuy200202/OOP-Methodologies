#include "Monster.h"

//----------------MONSTER-----------------
//Getter
int Monster::getX() {
	return x;
}
int Monster::getY() {
	return y;
}
double Monster::getHP() {
	return hp;
}
double Monster::getAttack() { 
	return attack;
}
double Monster::getPower() { 
	return power;
}

//Setter
void Monster::setHp(double a) {
	hp -= a;
}

//Input, output
void Monster::input(){
	cout << "Input x: "; cin >> x;
	cout << "Input y: "; cin >> y; cin.ignore(1);
	cout << "Input monster name: ";
	getline(cin, name);
	cout << "Input hp: "; cin >> hp;
	cout << "Input level: "; cin >> level;
	cout << "Input attack: "; cin >> attack;
	cout << "Input power: "; cin >> power; cin.ignore(1);
}
void Monster::output(){
	cout << "Position: (" << x << "," << y << ")" << endl;
	cout << "Name: " << name << endl;
	cout << "HP: " << hp << endl;
	cout << "Level: " << level << endl;
	cout << "Attack / power: " << attack << "/" << power << endl;
}

//----------------JUNGLE MONSTER-----------------
JungleMonster::JungleMonster() {}
