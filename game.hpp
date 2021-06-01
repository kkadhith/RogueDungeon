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
#include <iostream>
#include "item.hpp"
#include "healthpotion.hpp"
#include "attackpotion.hpp"
#include "defensepotion.hpp"

class Game
{
private:
	bool isPlaying = true;
	string input;
	string userName;
	int userRoleChoice;
	vector<Hostile*> hostiles;
	vector<Item*> inventory;
	vector<Item*> afterEffects;
	Player* player;
public:
	Factory factory;
        Game() {}
        // ~Game() = default;
        void Quit() {
        	isPlaying = false;
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
			bool choosing = true;
			while(choosing) {
				cin >> input;
				if(input == "a"){
					player->fight(hostiles.at(0));
					choosing = false;
				}else if(input == "d") {
					//player.defend();
					choosing = false;
				} else if(input == "i") {
					printInv();
					cin >> input;
					int invIndex;
					bool checked = false;
					do {
						cin >> input;
						if(is_number(input)) {
							invIndex = stoi(input);
							if(invIndex <= inventory.size()) checked = true;
						}
					} while(!checked);
					if(invIndex != inventory.size()){
						inventory.at(invIndex)->itemEffect(player);
						cout << "You used the " << inventory.at(invIndex);
						afterEffects.push_back(inventory.at(invIndex));
						inventory.erase(inventory.begin() + invIndex);
						choosing = false;
					}
				} else if(input == "s") {
					//player.abilities();
					choosing = false;
				} else if(input == "r") {
					run = rand() % 100;
					choosing = false;
				} else cout << "Invalid input" << endl;
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
				player->updateEXP(/*enemyEXP*/0);
				//player->addGold();
				player->setCurrHealth(player->getMaxHealth());
				delete hostiles.at(0);
				hostiles.erase(hostiles.begin());
				fin = true;
			}
	
		//inventory end of fight effects
		for(Item* i : afterEffects) {
			i->itemAfterEffect(player);
			delete i;
		}
		afterEffects.clear();
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
	void printInv() {
		if(inventory.empty()) {
			cout << "No items in inventory" << endl;
		} else{
			for(unsigned i = 0; i < inventory.size(); i++) {
				cout << "[" << i << "]:" << inventory.at(i)->getName() << " - ";
				inventory.at(i)->printItemEffect();
				cout << endl;
			}
		}
		cout << "[" << inventory.size() << "]: return" << endl;
	}
	bool is_number(string& s) {
		string::const_iterator it = s.begin();
		while(it != s.end() && isdigit(*it)) ++it;
		return !s.empty() && it == s.end();
	}
};


#endif

