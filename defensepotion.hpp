#ifndef _DEFENSEPOTION_HPP_
#define _DEFENSEPOTION_HPP_

#include "item.hpp"
#include <iostream>

class DefensePotion : public Item {
private:
        int potionvalue;
	string name;
public:
	DefensePotion() : potionvalue(5), name("defense potion") {}
        void itemEffect(Player* p) {
                p->setDefense(p->getDefense() + potionvalue);
        }
        void printItemEffect() {
                cout << "Defense potion that temporarily increases defense by 5";
        }
        void itemAfterEffect(Player* p) {
                p->setDefense(p->getDefense() - potionvalue);
        }
	string getName() { return name; }

};
#endif
