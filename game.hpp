#ifndef __GAME_HPP__
#define __GAME_HPP__


class Game
{
public:
	Game() : play(true) {}
	~Game() = default;
	void Quit() { play = false;}
	void Fight();
	bool IsPlaying() { return play; }
	void Shop();
	void EnterDungeon();

private:
	//Player player;
	//DungeonList dungeons;
	//Shop shop;
	//Enemy currEnemy;
	bool play;
};


#endif
