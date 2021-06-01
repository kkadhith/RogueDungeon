#ifndef _DEFENSEPOTION_HPP_
#define _DEFENSEPOTION_HPP_

#include "item.hpp"
#include <iostream>

class DefensePotion : public Item {
private:
        int potionvalue = 5;
public:
        void itemEffect(Player* p) {
                p->setDefense(p->getDefense() + potionvalue);
        }
        void printItemEffect() {
                cout << "Defense potion that temporarily increases defense by 5";
        }
        void itemAfterEffect(Player*) {
                p->setDefense(p->getDefense() - potionvalue);
        }


};
#endif
