#ifndef _HEALTHPOTION_HPP_
#define _HEALTHPOTION_HPP_

#include "item.hpp"
#include <iostream>

class HealthPotion : public Item {
private:
	int potionvalue;
	string name;
public:
	HealthPotion() : potionvalue(15), name("health potion") {}
	void itemEffect(Player* p) {
		p->setCurrHealth(p->getCurrHealth() + potionvalue);
	}
        void printItemEffect() {
		cout << "Healing potion that heals for 15 hp";
	}
        void itemAfterEffect(Player*) {}
	string getName() { return name; }

};
#endif
