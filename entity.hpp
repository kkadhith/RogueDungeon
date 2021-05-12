#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <string>

class Entity {
public:
	std::string fullname;
	double health;

	Entity() { }
	virtual ~Entity() { }

	virtual void attack(Entity*) = 0;
};

#endif
