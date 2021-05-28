#ifndef __ASSASSIN_HPP__
#define __ASSASSIN_HPP__

#include "player.hpp"

class Assassin : public Player {
public:
	Assassin(){
		attack = 7.5;
		defense = 5.0;
		speed = 10.0;
		magic = 5.0;
	}
};

#endif
