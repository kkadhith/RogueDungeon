#ifndef __HOSTILE_HPP__
#define __HOSTILE_HPP__

#include <string>

using namespace std;

class Hostile {
    protected:
        double health;
        int attackStrength;
        string description;
    public:
        Hostile() {
            health = 0.0;
            attackStrength = 0;
            description = "";
        }
    
        void fightPlayer(Player* p) {
            p->setHealth(p->getHealth() - this->attackStrength());
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

};


#endif
