#include <iostream>
#include "game.hpp"

using namespace std;

int main()
{
	//variables
	Game game;
	string dec;
	
	while(game.IsPlaying()) {
	    cin >> dec;
	    if(dec == "quit")
		    game.Quit();
	    if(dec == "dungeon")
		    //game.EnterDungeon();
	    if(dec == "shop")
		    //game.Shop();


	}
	return 0;
}
