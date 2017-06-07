#ifndef LEVEL
#define LEVEL
#include "Enemy.h"
class Enemy;
class Level
{
private:
	Enemy * levelBoss;
	Level * north;
	Level * south;
	Level * west;
	Level * east;
	int xCord;
	int yCord;
public:
	Level();
	void setNorth(Level*);
	void setEast(Level*);
	void setSouth(Level*);
	void setWest(Level*);
	Level* getNorth();
	Level* getEast();
	Level* getSouth();
	Level* getWest();
	Enemy* generateBoss();
	Enemy* getBoss();
	void setCords(int x, int y);
	std::string getCords();
	void killBoss();
	void printAvaliable();
};
#endif