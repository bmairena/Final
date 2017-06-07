#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Enemy.h"
#include "Ability.h"
class Enemy;
class Ability;
class Player;
const int SIZE = 4;
class Player: public GameObject
{
private:
	int health = 250;
	float attackPower;
	std::string name;
	Ability* skills[SIZE];
public:
	Player(std::string name, float attackPower, GameObject * parent = 0);
	int getHealth();
	int getAP();
	std::string getName();
	void dealDamage(Enemy * enemy, DamageInstance dmg);
	void Player::takeDamage(DamageInstance dmg);
	void die();
	void update();
	const int SIZE = 4;
	std::string listSkills();
	Ability* getSkill(int index);
};
#endif