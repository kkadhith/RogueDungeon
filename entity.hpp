#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <string>

class Entity {
private:
	std::string fullname;
	int level;
	double maxHealth;
	double currHealth;
	double attack;
public:
	Entity() { }
	virtual ~Entity() { std::cout << fullname << " has died!" << endl; }
	std::string getFullname() const { return fullname; }
	int getLevel() const { return level; }
	double getMaxHealth() const { return maxHealth; }
	double getCurrHealth() const { return currHealth; }
	double getAttack() const { return attack; }
	
	// I'm thinking that setters can be used for leveling up and to update during attack()

	void setLevel(int l) { level = l; }
	void setMaxHealth(double h) { maxHealth = h; }
	void setCurrHealth(double h) { currHealth = h; } 
	void setAttack(double a) { attack = a; }

	void attack(Entity*);
};

#endif
