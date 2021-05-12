#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "entity.hpp"

class Player : public Entity {
	Player();
	Player(std::string);
	~Player();
};

#endif
