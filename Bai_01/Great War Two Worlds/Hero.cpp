#include "Hero.h"

//------------------HERO--------------------
//Getter
int Hero::getX() {
	return x;
}
int Hero::getY() {
	return y;
}
double Hero::getHP() {
	return hp;
}
double Hero::getAttack() { 
	return attack; 
}
double Hero::getDefend() {
	return defend;
}
int Hero::getLevel() {
	return level;
}
string Hero::getName() {
	return name;
}
//Setter
void Hero::setXY(int x, int y){
	this->x = x;
	this->y = y;
}
void Hero::setHp(double a){
	hp -= a;
}
void Hero::setLevel(){}

//Input, Output
void Hero::input(){}
void Hero::output(){
	cout << "Position: (" << x << "," << y << ")" << endl;
	cout << "Name: " << name << endl;
	cout << "HP: " << hp << endl;
	cout << "Level: " << level << endl;
	cout << "Attack / Defend: " << attack << "/" << defend << endl;
}

//Check impact
bool Hero::isImpactMonster(Monster*a) { 
	return (x == a->getX()) && (y == a->getY()); // Check position
}
bool Hero::isImpactHero(Hero*a){ 
	return (x == a->getX()) && (y == a->getY()); // Check position
}
bool Hero::isImpactLevelConstruction(Construction*a){ 
	return (x == a->getX()) && (y == a->getY()) && a->getType() == "Level"; // Check position and type of construction
}
bool Hero::isImpactCloneConstruction(Construction* a) {
	return (x == a->getX()) && (y == a->getY()) && a->getType() == "Clone"; // Check position and type of construction
}

//------------------ATTACK HERO--------------------
AttackHero::AttackHero(){}
AttackHero::AttackHero(int x, int y, string name, double hp, int level, double attack, double defend) {
	this->x = x;
	this->y = y;
	this->name = name;
	this->hp = hp;
	this->level = level;
	this->attack = attack;
	this->defend = defend;
}
void AttackHero::input() {
	cout << "Input x: "; cin >> x;
	cout << "Input y: "; cin >> y; cin.ignore(1);
	cout << "Input hero name: ";
	getline(cin, name);
	cout << "Input hp: "; cin >> hp;
	cout << "Input level: "; cin >> level;
	cout << "Input attack: "; cin >> attack; cin.ignore(1);
	defend = attack / 5;

}
//Increase level, Attack Hero increases attack status more than defend status
void AttackHero::setLevel() {
	level++;
	attack += 5;
	defend += 1;
}
//------------------DEFEND HERO--------------------
DefendHero::DefendHero() {}
DefendHero::DefendHero(int x, int y, string name, double hp, int level, double attack, double defend) {
	this->x = x;
	this->y = y;
	this->name = name;
	this->hp = hp;
	this->level = level;
	this->attack = attack;
	this->defend = defend;
}
void DefendHero::input() {
	cout << "Input x: "; cin >> x;
	cout << "Input y: "; cin >> y; cin.ignore(1);
	cout << "Input hero name: ";
	getline(cin, name);
	cout << "Input hp: "; cin >> hp;
	cout << "Input level: "; cin >> level;
	cout << "Input defend: "; cin >> defend; cin.ignore(1);
	attack = defend / 5;

}
//Increase level, Defend Hero increases defend status more than attack status
void DefendHero::setLevel() {
	level++;
	attack += 1;
	defend += 5;
}