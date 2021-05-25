#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

class Factory {
public:
	Factory() {}
	changeRoles(int roleSelect)
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
				std::cout << "Invalid input" << endl;
				break;	
		}
	}
};

#endif
