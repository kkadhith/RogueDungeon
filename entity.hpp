#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <string>
#include <iostream>

class Entity {
protected:
	std::string fullname;
	int level;
	// 1 = Warrior, 2 = Archer, 3 = Magician, 4 = Assassin
	int role;
	double maxHealth;
	double currHealth;
	// Stats below will be set in role classes
	double attack;
	double defense;
	double magic;
	double speed;
public:
	Entity() { }
	virtual ~Entity() { std::cout << fullname << " has died!" << std::endl; }
	std::string getFullname() const { return fullname; }
	int getLevel() const { return level; }
	double getMaxHealth() const { return maxHealth; }
	double getCurrHealth() const { return currHealth; }
	double getAttack() const { return attack; }
	double getDefense() const { return defense; }
	double getMagic() const { return magic; }
	double getSpeed() const { return speed; }
	
	// I'm thinking that setters can be used for leveling up and to update during attack()

	void setLevel(int l) { level = l; }
	void setMaxHealth(double h) { maxHealth = h; }
	void setCurrHealth(double h) { currHealth = h; } 
	void setAttack(double a) { attack = a; }
	void setDefense(double d) { defense = d; }
	void setMagic(double m) { magic = m; }
	void setSpeed(double s) { speed = s; }

	void fight(Entity* target)
	{
		target->setCurrHealth(target->getCurrHealth() - this->attack);
		if(target->getCurrHealth() <= 0.0)
		{
			delete target;
		}
	}
	};

#endif
