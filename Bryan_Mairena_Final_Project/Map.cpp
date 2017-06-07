#include "Map.h"
#include <time.h>
Map::Map()
{
	srand(time(NULL));
	createMap();
	current = layout[0][0];
	addMove(current);
}
void Map::createMap()
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			layout[i][j] = new Level();
			layout[i][j]->setCords(i, j);
		}
	}
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (i - 1 >= 0)
			{
				layout[i][j]->setSouth(layout[i - 1][j]);
			}
			else
			{
				layout[i][j]->setSouth(nullptr);
			}
			if (i + 1 < HEIGHT)
			{
				layout[i][j]->setNorth(layout[i + 1][j]);
			}
			else
			{
				layout[i][j]->setNorth(nullptr);
			}
			if(j-1 >= 0)
			{
				layout[i][j]->setWest(layout[i][j-1]);
			}
			else
			{
				layout[i][j]->setWest(nullptr);
			}
			if(j+1 < WIDTH)
			{
				layout[i][j]->setEast(layout[i][j + 1]);
			}
			else
			{
				layout[i][j]->setEast(nullptr);
			}
		}
	}

}
void Map::update()
{

}
Level* Map::getCurrentLevel()
{
	return current;
}
void Map::setCurrentLevel(Level * current)
{
	this->current = current;
	addMove(current);
}
bool Map::victoryCheck() 
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			if (layout[i][j]->getBoss() != NULL)
			{
				return false;
			}
			
		}
	}
	return true;
}
void Map::addMove(Level*move)
{
	playerPath.push(move);
}
void Map::printPath()
{
	std::stack<Level*> temp(playerPath);
	for (int i = 0; i < temp.size(); i++)
	{
		std::cout << "Move #" << temp.size() - i << ": " << temp.top()->getCords() << std::endl;
		temp.pop();
	}
}
