#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include <string>
#include "player.hpp"
#include "warrior.hpp"
#include "archer.hpp"
#include "magician.hpp"
#include "assassin.hpp"

class Factory {
private:
	std::string username;
public:
	Factory() {}

	Player* selectRole(int roleInt)
	{
		Player* temp;
		switch(roleInt)
		{
			case 1:
				temp = new Warrior(username);			
				break;
			case 2:
				temp = new Archer(username);
				break;
			case 3:
				temp = new Magician(username);
				break;
			case 4:
				temp = new Assassin(username);
				break;
			default:
				std::cout << "Invalid input" << std::endl;
				break;	
		}
		return temp;
	}
	
	void setName(std::string n)
	{
		username = n;
		//std::cout << "Name has been successfully set!" << std::endl;
	}
};

#endif
