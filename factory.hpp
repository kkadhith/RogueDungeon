#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <iostream>
#include "player.hpp"
#include "warrior.hpp"
#include "archer.hpp"
#include "magician.hpp"
#include "assassin.hpp"

class Factory {
public:
	Factory() {}

	Player* changeRoles(int roleSelect)
	{
		Player* temp;
		switch(roleSelect)
		{
			case 1:
				temp = new Warrior();			
				break;
			case 2:
				temp = new Archer();
				break;
			case 3:
				temp = new Magician();
				break;
			case 4:
				temp = new Assassin();
				break;
			default:
				std::cout << "Invalid input" << std::endl;
				break;	
		}
		return temp;
	}
};

#endif
