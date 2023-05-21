#include "Hero.h"

class Map // Use singleton to create only map
{
private:
	static int length, width; 
	static Map* instance; //Only object
	static vector<Hero*> createdHero; // List hero created by Constructions
	static vector<Hero*> currentHero; // Your team
	static vector<Monster*> listMonsters; // List Monsters
	static vector<Construction*> listConstructions; // List Constructions
	Map(); // Private Constructor
public:
	void input(); //Input
	static Map* getInstance(); // Create only object
	static void createConstructionAndHero(); // Create Constructions and Heroes
	static void createMonsters(); // Create Monsters
	static void createCurrentHero(); // Create Player
	static void outputMap(); // Output all objects on map
	static void runGame(); // Run game
	static void deleteAllObjects(); // Free static memory
};