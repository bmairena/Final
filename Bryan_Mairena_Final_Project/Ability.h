#ifndef ABILITY_H
#define ABILITY_H
#include "DamageInstance.h"
#include "Player.h"
#include <iostream>
#include "GameObject.h"
class DamageInstance;
class Player;
class Enemy;
class Ability
{
protected:
	Player * parent;
	std::string name;
	float damage;
	int charges;
	int maxCharges;
	int maxCoolDown;
	int remainingCoolDown;
public:
	Ability(std::string name, float dmg, Player * parent);
	DamageInstance useAbility();
	Ability(Player * parent);
	DamageInstance getDamage();
	int getRemainingCharges();
	void update();
	std::string getName();
	int getMaxCharges();
};
#endif
