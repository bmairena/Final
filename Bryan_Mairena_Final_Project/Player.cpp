#include "Player.h"
Player::Player(std::string name, float attackPower, GameObject * parent)
	: GameObject(name, parent)
{
	this->attackPower = attackPower;
	skills[0] = new Ability("Fireball", 25, this);
	skills[1] = new Ability("Frostbolt", 15, this);
	skills[2] = new Ability("Earthquake", 20, this);
	skills[3] = new Ability("Impale", 12, this);

}
int Player::getHealth()
{
	return health;
}
int Player::getAP()
{
	return attackPower;
}
std::string Player::getName()
{
	return name;
}
void Player::dealDamage(Enemy * enemy, DamageInstance dmg)
{
	enemy->takeDamage(dmg);
}
void Player::takeDamage(DamageInstance dmg)
{
	health -= dmg.getDamage();
	if (health <= 0)
	{
		die();
	}
}
void Player::die()
{
	std::cout << "You have died.\n";
	delete this;	
}
void Player::update()
{
	for (int i = 0; i < 4; i++)
	{
		skills[i]->update();
	}
}
std::string Player::listSkills()
{
	std::string retVal = "";
	for (int i = 0; i < 4; i++)
	{
		retVal += (std::to_string(i + 1) + ": " + skills[i]->getName() + " " 
			+ std::to_string(skills[i]->getRemainingCharges()) + "/" 
			+ std::to_string(skills[i]->getMaxCharges()) +  "\n");
	}
	return retVal;
}
Ability* Player::getSkill(int index)
{
	return skills[index - 1];
}