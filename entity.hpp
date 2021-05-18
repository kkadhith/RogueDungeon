#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <string>

class Entity {
private:
	std::string fullname;
	double health;
	double attack;
public:
	Entity() { }
	virtual ~Entity() { }
	std::string getFullname() const { return fullname; }
	double getHealth() const { return health; }
	double getAttack() const { return attack; }
	
	// I'm thinking that setters can be used for leveling up and to update during attack()

	void setHealth(double h) { health = h; } 
	void setAttack(double a) { attack = a; }

	// Different computations per class child. Simply put: Health = Health - Attack

	virtual void attack(Entity*) = 0;
};

#endif
