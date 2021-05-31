#ifndef __GIANT_HPP__
#define __GIANT_HPP__

#include <string>
#include "hostile.hpp"

using namespace std;

class Giant : public Hostile {
    public:
        Giant() {
            health = 25.0;
            attackStrength = 1;
            description = "The Giant has a lot of health! If you aren't careful, the giant might stun you, and you won't be able to fight!";
        }
};

#endif
