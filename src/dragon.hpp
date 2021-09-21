#ifndef __DRAGON_HPP__
#define __DRAGON_HPP__

#include <string>
#include "hostile.hpp"

using namespace std;

class Dragon : public Hostile {
    private:
        int dragonAttack;
    public:
        Dragon() {
	    name = "Dragon";
            dragonAttack = 5;
            health = 50.0;
            attackStrength = 22;
            description = "The Dragon is a fiery beast! It has a small chance of inflicting you with a burn.";
        }
        void setDragonAttack(int d) {
            dragonAttack = d;
        }
        int getDragonAttack() {
            return dragonAttack;
        }
};

#endif
