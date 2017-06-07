#include "Level.h"
#include "Enemy.h"
Level::Level()
{
	bool discovered;
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	levelBoss = generateBoss();
}
void Level::setNorth(Level * north)
{
	this->north = north;
}
void Level::setEast(Level * east)
{
	this->east = east;
}
void Level::setSouth(Level * south)
{
	this->south = south;
}
void Level::setWest(Level * west)
{
	this->west = west;
}
Level* Level::getNorth()
{
	return north;
}
Level* Level::getEast()
{
	return east;
}
Level* Level::getSouth()
{
	return south;
}
Level* Level::getWest()
{
	return west;
}
Enemy* Level::generateBoss()
{
	Enemy* retVal;
	int seed = rand() % 7 + 1;
	switch (seed)
	{
	case 1: retVal = new Enemy(std::string("Goblin"),1,10,this);
		return retVal;
		break;
	case 2:	 retVal = new Enemy(std::string("Skeleton"),2,12,this);
		return retVal;
		break;
	case 3: retVal = new Enemy(std::string("Ogre"),3,15,this);
		return retVal;
		break;
	case 4:	 retVal = new Enemy(std::string("Vampire"),3,17,this);
		return retVal;
		break;
	case 5:	 retVal = new Enemy(std::string("Dragon"),5,25,this);
		return retVal;
		break;
	case 6:	 retVal = new Enemy(std::string("Wyvern"),4,20,this);
		return retVal;
		break;
	case 7:	retVal = new Enemy(std::string("Zomebie"),1,7,this);
		return retVal;
		break;
	default:
		 retVal = new Enemy(std::string("Goblin"), 1,10,this);
		return retVal;
		break;
	}
}
Enemy* Level::getBoss()
{
	return levelBoss;
}
void Level::setCords(int x, int y)
{
	xCord = x;
	yCord = y;
}
std::string Level::getCords()
{
	std::string x = std::to_string(xCord);
	std::string y = std::to_string(yCord);
	std::string retVal = x + "," + y;
	return retVal;
}
void Level::killBoss()
{
	levelBoss = nullptr;
}
void Level::printAvaliable()
{
	if (north != NULL)
	{
		std::cout << "1. North\n";
	}
	if (south != NULL)
	{
		std::cout << "2. South\n";
	}
	if (east != NULL)
	{
		std::cout << "3. East\n";
	}
	if (west != NULL)
	{
		std::cout << "4. West\n";
	}

}