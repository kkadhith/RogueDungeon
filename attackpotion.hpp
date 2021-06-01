#ifndef _ATTACKPOTION_HPP_
#define _ATTACKPOTION_HPP_

#include "item.hpp"
#include <iostream>

class AttackPotion : public Item {
private:
        int potionvalue = 5;
public:
        void itemEffect(Player* p) {
                p->setAttack(p->getAttack() + potionvalue);
        }
        void printItemEffect() {
                cout << "Attack potion that temporarily increases attack by 5";
        }
        void itemAfterEffect(Player*) {
		p->setAttack(p->getAttack() - potionvalue);
	}


};
#endif
~

