#include <iostream>
#include "game.hpp"

using namespace std;

int main()
{
        Game game;
        string dec; 
        game.startGameDialogue();
	cin >> dec;
	//This is where the player decides to start a new game, load a saved game, or quit. As of now, there is no way to save a game, so ultimately just starts a new game
    	if (dec == "q")	
	{
        	return 0;
    	}
    	else
	{
        	game.Begin();
		game.SetupDungeon();
    	}
    	dec = "";
        while(game.IsPlaying()) 
	{
        	game.MainMenu();
        	cin >> dec;
        	if(dec == "q")
		{
        	            game.Quit();
        	}
        	else if(dec == "b") 
		{
        	            // game.ItemShop();
        	}
        	else if(dec == "e") 
		{
        	            game.EnterDungeon();
        	}
        }
        return 0;
}

