#ifndef _ATTACKPOTION_HPP_
#define _ATTACKPOTION_HPP_

#include "item.hpp"
#include <iostream>

class AttackPotion : public Item {
private:
        int potionvalue;
	string name;
public:
	AttackPotion() : potionvalue(5), name("attack potion") {}
        void itemEffect(Player* p) {
                p->setAttack(p->getAttack() + potionvalue);
        }
        void printItemEffect() {
                cout << "Attack potion that temporarily increases attack by 5";
        }
        void itemAfterEffect(Player* p) {
		p->setAttack(p->getAttack() - potionvalue);
	}
	string getName() { return name; }

};
#endif
