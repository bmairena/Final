#include "Enemy.h"
#include <iostream>
Enemy::Enemy(std::string name, float attackPower, float health, Level * level, GameObject * parent) : GameObject(name,parent)
{
	this->attackPower = attackPower;
	this->health = health;
}
int Enemy::getHealth()
{
	return health;
}
std::string Enemy::getName()
{
	return name;
}
float Enemy::getAP()
{
	return attackPower;
}
DamageInstance Enemy::generateDamageInstance()
{
	DamageInstance dmg(attackPower);
	return dmg;
}
void Enemy::dealDamage(Player * player, DamageInstance dmg)
{
	player->takeDamage(dmg);
}
void Enemy::takeDamage(DamageInstance dmg)
{
	health -= dmg.getDamage();
	if (health <= 0)
	{
		die();
	}
}
void Enemy::die()
{
	std::cout << name << " has died!\n";
}
void Enemy::update()
{

}