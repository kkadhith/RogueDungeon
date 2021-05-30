#include <iostream>
#include "game.hpp"

using namespace std;

int main()
{

        Game game;
        string dec; 
        game.startGameDialogue();
    cin >> dec;
    if (dec == "q") {
        return 0;
    }
    else {
        game.Begin();
    }
    dec = "";
        while(game.IsPlaying()) {
        game.MainMenu();
            cin >> dec;
            if(dec == "q"){
                    game.Quit();
        }
            else if(dec == "b") {
                    // game.ItemShop();
        }
            else if(dec == "e") {
                    // game.EnterDungeon();
        }
        }
        return 0;
}

