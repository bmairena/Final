#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include "GameObject.h"
#include "Ability.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"
class Player;
class Ability;
class Level;
class Enemy: public GameObject
{
protected:
	Level * level;
	float health;
	float attackPower;
public:
	Enemy(std::string name, float attackPower, float health, Level * level, GameObject * parent = 0);
	int getHealth();
	std::string getName();
	float getAP();
	void dealDamage(Player * player, DamageInstance dmg);
	void takeDamage(DamageInstance dmg);
	void die();
	void update();
	DamageInstance generateDamageInstance();
};
#endif