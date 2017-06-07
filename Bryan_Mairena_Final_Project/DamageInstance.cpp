#include "DamageInstance.h"
DamageInstance::DamageInstance()
{
	damage = 0;
}
DamageInstance::DamageInstance(float damage)
{
	this->damage = damage;
}
float DamageInstance::getDamage()
{
	return damage;
}