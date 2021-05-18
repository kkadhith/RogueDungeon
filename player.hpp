#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "entity.hpp"

class Player : public Entity {
private:
	int experiencePoints;
public:
	Player();
	Player(std::string);
	~Player();
	void levelUp();
	void updateEXP(int exp);
	int getEXP() const { return experiencePoints; }
};

#endif
