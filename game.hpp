#ifndef __GAME_HPP__
#define __GAME_HPP__

using namespace std;

class Game
{
private:
    bool isPlaying = true;
    string input;
public:
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
        cout << "Welcome to The Colluseum!" << endl;
        cout << "Defeat all the enemies in each dungeon in order to complete the game!" << endl;
        cout << "Your progress will automatically be saved every dungeon you complete." << endl;
        cout << "Choose your class" << endl;
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

