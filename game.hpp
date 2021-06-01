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
#include "hostile.hpp"

class Game
{
private:
	bool isPlaying = true;
	string input;
	string userName;
	int userRoleChoice;
	vector<Hostile> hostiles;
	Player* player;
public:
	Factory factory;
        Game() {};
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
		string userName;
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
		string input;
		runChance = 60;		//player's chance at escaping from 0 to 100
		cout << "You face off against a " << enemies.at(0).getDesc() << endl;
		while(!fin) {
			cout << "You have " << player.getHealth() << " health" << endl;
			cout << "The " << enemies.at(0).getDesc() << "has " << enemies.at(0).getHealth() << " health" << endl;
			cout << "Attack : [a]" << endl;
			cout << "Defend : [d]" << endl;
			cout << "Use item : [i]" << endl;
			cout << "Special ability : [s]" << endl;
			cout << "Run away : [r]" << endl;
			cout << "Anything else to wait" << endl;
			cin >> input;
			if(input == "a"){
				player.fight(enemies.at(0));
			}else if(input == "d") {
				//player.defend();
			} else if(input == "i") {
				//ShowInv();
				//cin >> input;
				//player.useItem(inventory.at(input));
			} else if(input == "s") {
				//player.abilities();
			} else if(input == "r") {
				int run = rand() % 100;
			}
			cout << "The " << enemies.at(0).getDesc() << "attacks you" << endl;
			enemies.at(0).fightPlayer(player);
			if(run < runChance) {
				cout << "You got away!" << endl;
				fin = true;
			}
			if(player.getHealth() <= 0) {
				//lose
				fin = true;
			}
			if(enemies.at(0).getHealth() <= 0) {
				//win
				player.updateEXP(/*enemyEXP*/0);
				fin = true;
			}
		}
		
	}
        	bool IsPlaying() { return isPlaying; }
        	// void Shop();
        	// void EnterDungeon();


};


#endif

