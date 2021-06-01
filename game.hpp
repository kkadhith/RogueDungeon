#ifndef __GAME_HPP__
#define __GAME_HPP__

using namespace std;

#include "factory.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "warrior.hpp"
#include "archer.hpp"
#include "magician.hpp"
#include "assassin.hpp"
#include <string>
#include <vector>
#include "hostile.hpp"
#include "zombie.hpp"
#include "giant.hpp"
#include "dragon.hpp"

class Game
{
private:
	bool isPlaying = true;
	string input;
	string userName;
	int userRoleChoice;
	vector<Hostile*> hostiles;
	Player* player;
public:
	Factory factory;
        Game() {};
        // ~Game() = default;
        void Quit() {
        	isPlaying = false;
		delete player;
		for(Hostile* h : hostiles) {
			delete h;
		}
        }
    	void startGameDialogue() {
        	cout << "(This is a text based RPG. Press the character between the brackets [] to select different options.)" << endl;
        	cout << "Start New Game : [s]" << endl;
        	cout << "Load Game      : [l]" << endl;
        	cout << "Quit Game      : [q]" << endl;
    	}	
    	void Begin() {
        	cout << "Welcome to Generic Text RPG!" << endl;
        	cout << "Defeat enemies in each dungeon in order to level up and complete the game!" << endl;
        	cout << "Your progress will automatically be saved every dungeon you complete." << endl;
        	cout << "Please enter your name: ";
		cin >> userName;
		factory.setName(userName);
		cout << endl << "Please select a role:" << endl << "Warrior : [1]" << endl << "Archer : [2]" << endl << "Magician : [3]" << endl << "Assassin : [4]" << endl;
		cin >> userRoleChoice;
		player = factory.selectRole(userRoleChoice);
		cout << endl;
    	}
    	void MainMenu() {
        	cout << "Enter Dungeon : [e]" << endl;
        	cout << "Buy Items     : [b]" << endl;
        	// cout << "Save Game     : [s]" << endl;
        	cout << "Quit Game     : [q]" << endl;
    	}
        void Fight() {
		bool fin = false;
		int run;
		int runChance = 60;		//player's chance at escaping from 0 to 100
		cout << "You face off against a " << hostiles.at(0)->getName() << endl;
		while(!fin) {
			cout << "You have " << player->getCurrHealth() << " health" << endl;
			cout << "The " << hostiles.at(0)->getName() << "has " << hostiles.at(0)->getHealth() << " health." << endl;
			cout << "Attack : [a]" << endl;
			cout << "Defend : [d]" << endl;
			cout << "Use item : [i]" << endl;
			cout << "Special ability : [s]" << endl;
			cout << "Run away : [r]" << endl;
			cout << "Anything else to wait" << endl;
			cin >> input;
			run = 101;
			if(input == "a"){
				player->fight(hostiles.at(0));
			}else if(input == "d") {
				//player.defend();
			} else if(input == "i") {
				//ShowInv();
				//cin >> input;
				//player.useItem(inventory.at(input));
			} else if(input == "s") {
				//player.abilities();
			} else if(input == "r") {
				run = rand() % 100;
			}
		
			//enemy action
			cout << "The " << hostiles.at(0)->getName() << "attacks you" << endl;
			hostiles.at(0)->fightPlayer(player);

			//outcomes
			if(player->getCurrHealth() <= 0) {
				//lose
				fin = true;
			}
			if(run < runChance) {
                                cout << "You got away!" << endl;
				player->setCurrHealth(player->getMaxHealth());
                                fin = true;
                        }
			if(hostiles.at(0)->getHealth() <= 0) {
				//win
				cout << "You killed the " << hostiles.at(0)->getName() << "! You got " << /*hostiles.at(0)->getXP() <<*/ "XP and " << /*hostiles.at(0)->getMoney() <<*/ " gold!" << endl;
				//player->updateEXP(/*enemyEXP*/0);
				//player->addGold();
				player->setCurrHealth(player->getMaxHealth());
				delete hostiles.at(0);
				hostiles.erase(hostiles.begin());
				fin = true;
			}
	
			//inventory end of fight effects
		}
		
	}
        bool IsPlaying() { return isPlaying; }
        // void Shop();
        void EnterDungeon() {
		bool delving = true;
		cout << "You begin to enter the dungeon" << endl;
		while(delving) {
			if(hostiles.empty()){
				cout << "You cleared the dungeon!" << endl;
				delving = false;
				SetupDungeon();
				//something something, another dungeon something something
			}else{
				cout << "Going deeper, you come across a " << hostiles.at(0)->getName() << "." << hostiles.at(0)->getDesc() << endl;
				Fight();
				if(isPlaying) {
					cout << "Would you like to go deeper?" << endl;
					cout << "Yes : [y]" << endl;
					cout << "No : anything else" << endl;
					cin >> input;
					if(input != "y") delving = false;
				}
				else{
					delving = false;
					//death text, end game
				}
			}
		}
	}
	void SetupDungeon() {
		for(int i = 0; i < 3; i++) {
			Hostile* zombie = new Zombie();
			hostiles.push_back(zombie);
		}
		for(int i = 0; i < 2; i++) {
			Hostile* giant = new Giant();
			hostiles.push_back(giant);
		}
		Hostile* dragon = new Dragon();
		hostiles.push_back(dragon);
	}
};


#endif

