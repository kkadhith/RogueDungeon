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
	delete player;
}
