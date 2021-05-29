#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "entity.hpp"

class Enemy : public Entity {
public:
	Enemy() { fullname = "Enemy"; level = 1; maxHealth = 50; currHealth = maxHealth; }
	Enemy(std::string, int, double, double);
	~Enemy() { }
};

#endif
