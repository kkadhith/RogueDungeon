#include "enemy.hpp"

Enemy::Enemy(std::string n, int l, double h, double a)
{
	fullname = n;
	level = l;
	maxHealth = h;
	currHealth = maxHealth;
	attack = a;
}
