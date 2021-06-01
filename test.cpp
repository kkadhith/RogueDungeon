#include "gtest/gtest.h"

#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "factory.hpp"
#include "warrior.hpp"
#include "archer.hpp"
#include "magician.hpp"
#include "assassin.hpp"

#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(BasicInitializationTest, NewPlayer)
{
	Entity* player = new Player();
	EXPECT_EQ(player->getCurrHealth(), 100.0);
	delete player;
}

TEST(BasicInitializationTest, NewWarrior)
{
	Entity* player = new Warrior();
	cout << "Curr Health: " << player->getCurrHealth() << endl << "Max Health: " << player->getMaxHealth() << endl << "Player Name: " << player->getFullname() << endl;
	delete player;
}

TEST(BasicInitializationTest, FactoryTest)
{
	Factory factory;
	factory.setName("Elijah Fang");
	Entity* player = factory.selectRole(1);
	cout << player->getFullname() << endl;
	EXPECT_EQ(player->getFullname(), "Elijah Fang");
}

TEST(FightTest, BasicFight)
{
	Factory factory;
	Player* player = factory.selectRole(1);
	Hostile* enemy = new Hostile();
	cout << "Enemy health before fight: " << enemy->getHealth() << endl;
	player->fight(enemy);
	cout << "Enemy health after fight: " << enemy->getHealth() << endl;
}
