#include "enemy.hpp"

Enemy::Enemy(std::string n, double h, double a)
{
	fullname = n;
	health = h;
	attack = a;
}

void Enemy::attack(Entity* target)
{
	target->setHealth(target->getHealth() - (this->getAttack()/2.0));
}
