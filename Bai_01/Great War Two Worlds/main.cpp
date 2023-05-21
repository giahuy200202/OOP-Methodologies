#include "Map.h"
int main() {

	Map* a = Map::getInstance();

	cout << "INPUT MAP" << endl;
	a->input();
	//Initialize the game
	a->createConstructionAndHero();
	a->createMonsters();
	a->createCurrentHero();
	a->outputMap();

	//Play game
	while (true)
	{
		int choose;
		cout << "\n----------MENU------------\n";
		cout << "1. Move" << endl;
		cout << "2. Exit" << endl;
		cout << "Input choose: "; cin >> choose;
		if (choose == 1) {
			a->runGame();
			a->outputMap();
		}
		else {
			a->deleteAllObjects();
			delete a;
			a = nullptr;
			return 0;
		}
	}
}