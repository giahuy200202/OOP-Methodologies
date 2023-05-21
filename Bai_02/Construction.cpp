#include "Construction.h"

//----------------CONSTRUCTION-----------------
Construction::Construction() {}

//Getter
int Construction::getX() {
	return x;
}
int Construction::getY() {
	return y;
}
string Construction::getType() {
	return "Create";
}

//Input
void Construction::input() {
	cout << "Input x: "; cin >> x;
	cout << "Input y: "; cin >> y; cin.ignore(1);
	cout << "Input construction name: ";
	getline(cin, name);
}

//Output
void Construction::output() {
	cout << "Position: (" << x << "," << y << ")" << endl;
	cout << "Name: " << name << endl;
}

//----------------SPECIAL CONSTRUCTION-----------------
SpecialConstruction::SpecialConstruction() {}
string SpecialConstruction::getType() {
	return "Level";
}

//----------------CLONE CONSTRUCTION-----------------
CloneConstruction::CloneConstruction() {}
string CloneConstruction::getType() {
	return "Clone";
}