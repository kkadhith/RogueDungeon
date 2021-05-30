#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "entity.hpp"
#include <iostream>

class Player : public Entity {
private:
	int experiencePoints;
public:
	Player() {
		fullname = "Player";
		maxHealth = 100.0;
		currHealth = maxHealth;
		level = 1;
	}
	Player(std::string name) {
		fullname = name;
		maxHealth = 100.0;
		maxHealth = currHealth;
		level = 1;
	}
	~Player() {}
	void levelUp() { level++; maxHealth += 5.0; attack += 2.5; }
	void updateEXP(int exp) {
		experiencePoints = experiencePoints + exp;
		if(experiencePoints >= 100)
		{
			levelUp();
			experiencePoints = experiencePoints - 100;
		}
	}
	int getEXP() const { return experiencePoints; }
};

#endif
