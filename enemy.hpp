#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "entity.hpp"

class Enemy : public Entity {
	Enemy(std::string, double, double);
	~Enemy();
	virtual void attack(Entity* target);
};

#endif
