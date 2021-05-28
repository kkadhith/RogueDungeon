#ifndef __MAGICIAN_HPP__
#define __MAGICIAN_HPP__

#include "player.hpp"

class Magician : public Player {
public:
	Magician() {
		attack = 2.5;
		defense = 5.0;
		magic = 15.0;
		speed = 2.5;
	}
};

#endif
