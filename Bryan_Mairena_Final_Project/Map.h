#ifndef MAP_H
#define MAP_H
#include <stack>
#include "Level.h"
const int HEIGHT = 5;
const int WIDTH = 5;
class Map
{
private:
	std::stack<Level*> playerPath;
	void createMap();
	Level* current;
	Level* layout[WIDTH][HEIGHT];
public:
	Map();
	Level* getCurrentLevel();
	void setCurrentLevel(Level * current);
	void update();
	bool victoryCheck();
	void addMove(Level*move);
	void printPath();

	
	
};
#endif