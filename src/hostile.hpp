#ifndef __HOSTILE_HPP__
#define __HOSTILE_HPP__

#include "entity.hpp"
#include "player.hpp"

#include <string>

using namespace std;

class Hostile {
    protected:
        double health;
        int attackStrength;
        string description;
	string name;
    public:
        Hostile() {
	    name = "";
            health = 0.0;
            attackStrength = 0;
            description = "";
        }
    
        void fightPlayer(Entity* p) {
            p->setCurrHealth(p->getCurrHealth() - this->attackStrength);
        }

        void setHealth(double h) {
            health = h;
        }
        double getHealth() {
            return health;
        }
        void setAttackStrength(int a) {
            attackStrength = a;
        }
        int getAttackStrength() {
            return attackStrength;
        }
        void setDesc(string d) {
            description = d;
        }
        string getDesc() {
            return description;
        }
	void setName(string n) {
	    name = n;
	}
	string getName() {
	    return name;
	}
};


#endif
