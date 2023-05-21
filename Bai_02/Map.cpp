#include "Map.h"

//Initialize static members
Map* Map::instance = nullptr;
int Map::length;
int Map::width;
vector<Hero*> Map::createdHero;
vector<Hero*> Map::currentHero;
vector<Monster*> Map::listMonsters;
vector<Construction*> Map::listConstructions;

//Private constructor
Map::Map() {}

//Create only object
Map* Map::getInstance() {
	if (instance == nullptr) instance = new Map();
	else return instance;
}
void Map::input() {
	cout << "Input length: ";
	cin >> length;
	cout << "Input width: ";
	cin >> width;
}
// Create Constructions and Heroes
void Map::createConstructionAndHero() {

	//Create Constructions
	int n;
	cout << "--------------CONSTRUCTIONS AND HEROES---------------\n";
	cout << "Input the number of create hero constructions: "; cin >> n; 
	for (int i = 0; i < n; i++) {
		listConstructions.push_back(new Construction());
		while (true)
		{
			cout << "\n---------CONSTRUCTIONS--------\n";
			listConstructions[i]->input();
			if (listConstructions[i]->getX() > length || listConstructions[i]->getX() < 0 || listConstructions[i]->getY() > width || listConstructions[i]->getX() < 0)
				cout << "Position is out of range, Input again" << endl;
			else break;
		}
		//Create Hero
		int choose;
		cout << "\n---------HEROES--------\n";
		cout << "1. Attack hero" << endl;
		cout << "2. Defend hero" << endl;
		cout << "Input type of hero: "; cin >> choose; cin.ignore(1);
		if (choose == 1) {
			createdHero.push_back(new AttackHero());
			while (true) {
			createdHero[i]->input();
			if (createdHero[i]->getX() > length || createdHero[i]->getX() < 0 || createdHero[i]->getY() > width || createdHero[i]->getX() < 0)
				cout << "Position is out of range, Input again" << endl;
			else break;
			}
		}
		else {
			createdHero.push_back(new DefendHero());
			while (true) {
				createdHero[i]->input();
				if (createdHero[i]->getX() > length || createdHero[i]->getX() < 0 || createdHero[i]->getY() > width || createdHero[i]->getX() < 0)
					cout << "Position is out of range, Input again" << endl;
				else break;
			}
		}
	}

	//Create Level Constructions
	int m;
	cout << "\nInput the number of leveling constructions: "; cin >> m; 
	for (int i = n; i < n + m; i++) {
		cout << "\n---------CONSTRUCTIONS--------\n";
		listConstructions.push_back(new SpecialConstruction());
		while (true) {
			listConstructions[i]->input();
			if (listConstructions[i]->getX() > length || listConstructions[i]->getX() < 0 || listConstructions[i]->getY() > width || listConstructions[i]->getX() < 0)
				cout << "Position is out of range, Input again" << endl;
			else break;
		}
	}

	//Create Clone Constructions
	int z;
	cout << "\nInput the number of clone constructions: "; cin >> z; 
	for (int i = n + m; i < n + m + z; i++) {
		cout << "\n---------CONSTRUCTIONS--------\n";
		listConstructions.push_back(new CloneConstruction());
		while (true) {
			listConstructions[i]->input();
			if (listConstructions[i]->getX() > length || listConstructions[i]->getX() < 0 || listConstructions[i]->getY() > width || listConstructions[i]->getX() < 0)
				cout << "Position is out of range, Input again" << endl;
			else break;
		}
	}
}

// Create Monsters
void Map::createMonsters() {
	cout << "\n--------------MONSTERS---------------\n";
	int n;
	cout << "Input the number of monsters: "; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		cout << "-----MONSTERS-----\n";
		listMonsters.push_back(new JungleMonster());
		while (true) {
			listMonsters[i]->input();
			if (listMonsters[i]->getX() > length || listMonsters[i]->getX() < 0 || listMonsters[i]->getY() > width || listMonsters[i]->getX() < 0)
				cout << "Position is out of range, Input again" << endl;
			else break;
		}
	}
}

// Create Player
void Map::createCurrentHero() {
	cout << "\n--------------PLAYER---------------\n";
	currentHero.push_back(new AttackHero());
	while (true) {
		currentHero[0]->input();
		if (currentHero[0]->getX() > length || currentHero[0]->getX() < 0 || currentHero[0]->getY() > width || currentHero[0]->getX() < 0)
			cout << "Position is out of range, Input again" << endl;
		else break;
	}
}

//Output all objects on map
void Map::outputMap() {

	//Output constructions
	cout << "\n--------------CONSTRUCTIONS---------------\n";
	for (int i = 0; i < listConstructions.size(); i++) {
		cout << "-----CONSTRUCTION-----\n";
		listConstructions[i]->output();
		cout << "Type: " << listConstructions[i]->getType() << endl;
	}

	//Output Monsters
	cout << "\n----------------MONSTERS-----------------\n";
	for (int i = 0; i < listMonsters.size(); i++) {
		cout << "-----MONSTER-----\n";
		listMonsters[i]->output();
		cout << endl;
	}

	//Output heroes created by constructions
	cout << "\n----------------HEROES-----------------\n";
	for (int i = 0; i < createdHero.size(); i++) {
		cout << "-----HERO-----\n";
		createdHero[i]->output();
		cout << endl;
	}

	//Output your team
	cout << "\n----------------YOUR TEAM-----------------\n";
	for (int i = 0; i < currentHero.size(); i++) {
		cout << "-----HERO-----\n";
		currentHero[i]->output();
		cout << endl;
	}
	
	//Win or Lose
	if (listMonsters.size() == 0 && currentHero.size() != 0)
		cout << "\n-----------------HUMAN WIN--------------------\n";
	if ( currentHero.size() == 0)
		cout << "\n-----------------HUMAN LOSE--------------------\n";
}

//Run game
void Map::runGame() {

	//Move your team
	int x, y;
	while (true) {
		cout << "Input position your team want to move" << endl;
		cout << "Input x: "; cin >> x;
		cout << "Input y: "; cin >> y;
		if (x < 0 || y < 0 || x>length|| y>width) continue;
		else {
			for(int i=0; i<currentHero.size(); i++)
				currentHero[i]->setXY(x, y);
			break;
		}
	}

	//Heroes
	for (int i = 0; i < createdHero.size(); i++)
	{
		if (currentHero[0]->isImpactHero(createdHero[i])) //Check impact with other heroes
		{
			cout << "\n-------------NEW HERO ENGAGES IN YOUR TEAM----------------\n";
			currentHero.push_back(createdHero[i]); //Add hero to your team
			createdHero.erase(createdHero.begin() + i); //Delete hero in list hero created by construction
			break;
		}
	}

	//Construction
	for (int i = 0; i < listConstructions.size(); i++) 
	{
		//Level construction
		if (currentHero[0]->isImpactLevelConstruction(listConstructions[i])) //Check impact with level construction
		{
			cout << "\n-------------YOUR TEAM HAS BEEN LEVEL UP----------------\n";
			for (int j = 0; j < currentHero.size(); j++)
				currentHero[j]->setLevel(); //Increase level of heroes
			listConstructions.erase(listConstructions.begin() + i); //Delete construction has been used
			break;
		}
		//Clone construction
		if (currentHero[0]->isImpactCloneConstruction(listConstructions[i])) //Check impact with clone construction
		{
			cout << "\n------------YOUR TEAM HAS BEEN CLONE (x2)---------------\n";
			int n = currentHero.size();
			for (int j = 0; j < n; j++) {
				//Clone heroes
				if (currentHero[i]->getAttack() > currentHero[i]->getDefend())
					currentHero.push_back(new AttackHero(currentHero[i]->getX(), currentHero[i]->getY(), currentHero[i]->getName(), currentHero[i]->getHP(), currentHero[i]->getLevel(), currentHero[i]->getAttack(), currentHero[i]->getDefend()));
				else
					currentHero.push_back(new DefendHero(currentHero[i]->getX(), currentHero[i]->getY(), currentHero[i]->getName(), currentHero[i]->getHP(), currentHero[i]->getLevel(), currentHero[i]->getAttack(), currentHero[i]->getDefend()));
			}
			listConstructions.erase(listConstructions.begin() + i); //Delete construction has been used
			break;
		}
	}


	//Monster
	for (int i = 0; i < listMonsters.size(); i++) 
	{
		if (currentHero[0]->isImpactMonster(listMonsters[i])) //Check impact
		{
			cout << "\n------ATTACKING BETWWEEN MONSTER AND HUMAN------\n";
			for (int j = 0; j < currentHero.size(); j++) 
			{
				//Check if damage of monsters  greater than defend status heroes 
				if (listMonsters[i]->getAttack() + listMonsters[i]->getPower() * 2 - currentHero[j]->getDefend() > 0) {
					//if true, decrease hp's heroes
					currentHero[j]->setHp(listMonsters[i]->getAttack() + listMonsters[i]->getPower() * 2 - currentHero[j]->getDefend());
				}
				//else Hero is invulberable
				listMonsters[i]->setHp(currentHero[j]->getAttack());
				//Check each hero in your team is dead or not
				if (currentHero[j]->getHP() <= 0) {
					currentHero.erase(currentHero.begin() + j);// If dead delete hero from your team
					j--;
				}
			}
			//Check each monster is dead or not
			if (listMonsters[i]->getHP() <= 0) {
				listMonsters.erase(listMonsters.begin() + i); // If dead delete monster from list monster
				i--;
			}
		}
	}
}

//Free memory
void Map::deleteAllObjects(){
	//Free constructions
	for (int i = 0; i < listConstructions.size(); i++) {
		delete listConstructions[i];
		listConstructions[i] = nullptr;
	}
	//Free monsters
	for (int i = 0; i < listMonsters.size(); i++) {
		delete listMonsters[i];
		listMonsters[i] = nullptr;
	}
	//Free heroes created by constructions
	for (int i = 0; i < createdHero.size(); i++) {
		delete createdHero[i];
		createdHero[i] = nullptr;
	}
	//Free all heroes in team
	for (int i = 0; i < currentHero.size(); i++) {
		delete currentHero[i];
		currentHero[i] = nullptr;
	}
}