#include "Ability.h"
Ability::Ability(std::string name, float dmg, Player * parent)
{
	this->name = name;
	damage = dmg;
	this->parent = parent;
	
	maxCharges = 4;
	charges = maxCharges;
	maxCoolDown = 2;
	remainingCoolDown = maxCoolDown;
}
Ability::Ability(Player * parent)
{
	this->parent = parent;
	charges = 4;
}
DamageInstance Ability::getDamage()
{
	float dmg = 0;
	dmg = damage + (parent->getAP()/10);
	DamageInstance damageDealt(dmg);
	return damageDealt;
}
int Ability::getRemainingCharges()
{
	return charges;
}
int Ability::getMaxCharges()
{
	return maxCharges;
}
DamageInstance Ability::useAbility()
{
	if (getRemainingCharges() > 0)
	{
		charges--;
		return getDamage();
	}
	else
	{
		std::cout << "No charges rememaining. Choose another ability!\n";
		return 0;
	}
}
void Ability::update()
{
	if (charges < maxCharges)
	{
		remainingCoolDown--;
		if (remainingCoolDown <= 0)
		{
			charges++;
			remainingCoolDown = maxCoolDown;
		}
	}
	else
	{
		return;
	}
}
std::string Ability::getName()
{
	return name;
}