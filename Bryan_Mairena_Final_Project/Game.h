#ifndef GAME_H
#define GAME_H
#include "GameObject.h"
#include "Player.h"
#include "Map.h"
#include "Level.h"
#include "Ability.h"
#include "Enemy.h"
class Game: public GameObject
{
private:
	Map * map;
	Player * player;
	bool winCondition;
public:
	Game();
	void update();
	void play();
	void menu();
	void battle(Enemy*boss);
	void recurssionExample(int i); 
};
#endif