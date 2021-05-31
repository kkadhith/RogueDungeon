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

class Game
{
private:
	bool isPlaying = true;
	string input;
	string userName;
	int userRoleChoice;
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
        	cout << "Welcome to Generic Text RPG!" << endl;
        	cout << "Defeat enemies in each dungeon in order to level up and complete the game!" << endl;
        	cout << "Your progress will automatically be saved every dungeon you complete." << endl;
        	cout << "Please enter your name: ";
		cin >> userName;
		factory.setName(userName);
		cout << endl << "Please select a role:" << endl << "Warrior : [1]" << endl << "Archer : [2]" << endl << "Magician : [3]" << endl << "Assassin : [4]" << endl;
		cin >> userRoleChoice;
		Player* player = factory.selectRole(userRoleChoice);
		cout << endl;
    	}
    	void MainMenu() {
        	cout << "Enter Dungeon : [e]" << endl;
        	cout << "Buy Items     : [b]" << endl;
        	// cout << "Save Game     : [s]" << endl;
        	cout << "Quit Game     : [q]" << endl;
    	}
        	// void Fight();
        	bool IsPlaying() { return isPlaying; }
        	// void Shop();
        	// void EnterDungeon();


};


#endif

