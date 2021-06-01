#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <string>
#include "hostile.hpp"

using namespace std;

class Zombie : public Hostile {
    public:
        Zombie() {
            
            health = 10.0;
            attackStrength = 5;
            description = "By itself, the Zombie is quite weak. It has no special attributes. In groups, they can eat you!";
        }
};

#endif
