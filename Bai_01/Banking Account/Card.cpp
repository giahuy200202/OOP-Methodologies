#include "Card.h"
Card::Card(dateFormat a, string b) {
	releaseDate = a;
	linkAccount = b;
}
string Card::getCreditNumber() {
	return creditNumber;
}
void Card::input() {
	cout << "Input credit card number: ";
	getline(cin, creditNumber);
}
void Card::output() {
	cout << "Credit card number: " << creditNumber << endl;
	cout << "Release date: " << releaseDate.day << "/" << releaseDate.month << "/" << releaseDate.year << endl;
	cout << "Linked with ( Account number ): " << linkAccount << endl;
}