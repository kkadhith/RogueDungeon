#include "player.hpp"

Player::Player()
{
	fullname = "Player";
	maxHealth = 100.0;
	currHealth = maxHealth;
	level = 1;	
}

Player::Player(std::string name)
{
	fullname = name;
	maxHealth = 100.0;
	currHealth = maxHealth;
	level = 1;
}

void Player::levelUp()
{
	level++;
	health += 5.0;
	attack += 2.5;
}

void Player::updateEXP(int exp)
{
	experiencePoints = experiencePoints + exp;
	if(experiencePoints >= 100)
	{
		levelUp();
		experiencePoints = experiencePoints - 100;	
	}	
}
