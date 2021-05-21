#ifndef __WARRIOR_HPP__
#define __WARRIOR_HPP__

#include "player.hpp"

class Warrior : public Player {
public:
	Warrior() {
		attack = 10.0;
		defense = 10.0;
		magic = 2.5;
		speed = 5.0;
	}
};

#endif
