#include "entity.hpp"

void Entity::attack(Entity* target)
{
	target->setCurrHealth(target->getCurrHealth() - this->attack());
	if(target->getCurrHealth() <= 0.0)
	{
		delete target;
	}
}
