#include "Game.h"
#include <iostream>
#include <exception>
Game::Game() : GameObject(0)
{
	recurssionExample(1000000);
	system("pause");
	system("cls");
	winCondition = false;
	map = new Map();
	std::cout << "Enter Player Name: ";
	std::string newName;
	getline(std::cin,newName);
	player = new Player(newName,10,this);
	play();
}
void Game::update()
{
	map->update();
	player->update();
}
void Game::play()
{
	while (!winCondition)
	{
		menu();
		update();
		winCondition = map->victoryCheck();
		if (winCondition)
		{
			std::cout << "Congratulations you have defeated all of the monsters in the Dungeon!\n";
		}	
		system("cls");
	}
}
void Game::menu()
{
	try {
		Level * current = map->getCurrentLevel();
		if (current->getBoss() != NULL)
		{
			battle(current->getBoss());
		}
		else
		{
			std::cout << "There doesnt seem to be anything here.\n\n";
		}
		char choice;
		std::cout << "Enter which direction you would like to travel: \n";
		current->printAvaliable();
		std::cin >> choice;
		switch (choice)
		{
		case 'n':
		case 'N':
		case '1': if (map->getCurrentLevel()->getNorth() != NULL)
		{
			map->setCurrentLevel(map->getCurrentLevel()->getNorth());
		}
		else
		{
		  std::cout << "You can't go that way.\n";
		}
		break;
		case 's':
		case 'S':
		case '2':  if (map->getCurrentLevel()->getSouth() != NULL)
		{
			map->setCurrentLevel(map->getCurrentLevel()->getSouth());
		}
		else
		{
		   std::cout << "You can't go that way.\n";
		}
		break;
		case 'e':
		case 'E':
		case '3':  if (map->getCurrentLevel()->getEast() != NULL)
		{
			map->setCurrentLevel(map->getCurrentLevel()->getEast());
		}
		else
		{
		   std::cout << "You can't go that way.\n";
		}
		break;
		case 'w':
		case 'W':
		case '4':  if (map->getCurrentLevel()->getNorth() != NULL)
		{
			map->setCurrentLevel(map->getCurrentLevel()->getWest());
		}
		else
		{
		   std::cout << "You can't go that way.\n";
		}
		break;
		default: throw("No matching cases.\n");
			break;
		}
		std::cin.ignore(100, '\n');
		std::cin.clear();
	}
	catch (const char* e)
	{
		std::cout << e;
		system("pause");
	}

}

void Game::battle(Enemy*boss)
{
	bool playersTurn = true;
	bool enemysTurn = false;
	std::cout << "A " << boss->getName() << " appeared!\n";
	while (true)
	{
		std::cout << "Player HP" << player->getHealth() << "\t\t\t" << "Enemy HP:" << boss->getHealth() << "\n\n\n\n\n\n\n";
		if (playersTurn)
		{
			int choice;
			std::cout << "Select an ability to use: (1-4)\n";
			std::cout << player->listSkills();
			std::cin >> choice;
			Ability* chosenSkill = player->getSkill(choice);
			while (chosenSkill->getDamage().getDamage() == 0)
			{
				std::cout << "No charges remaining select a difference Ability: \n" << player->listSkills();
				std::cin >> choice;
				chosenSkill = player->getSkill(choice);
			}
			player->dealDamage(boss, chosenSkill->useAbility());
			playersTurn = false;
			enemysTurn = true;
			if (boss->getHealth() <= 0)
			{
				map->getCurrentLevel()->killBoss();
				return;
			}
		}
		else if (enemysTurn)
		{
			boss->dealDamage(player, boss->generateDamageInstance());
			enemysTurn = false;
			playersTurn = true;
		}
		player->update();
	}
}
void Game::recurssionExample(int i)
{
	std::cout << i << std::endl;
	if(i > 0)
	{
		recurssionExample(i / 2);
	}
	else if (i == 0)
	{
		std::cout << "here is some recurssion!";
	}
}