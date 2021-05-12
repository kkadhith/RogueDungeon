#include "player.hpp"

Player::Player()
{
	fullname = "Player";
	health = 100.0;	
}

Player::Player(std::string name)
{
	fullname = name;
	health = 100.0;
}
