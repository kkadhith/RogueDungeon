#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include "player.hpp"

class Item {
public:	
	Item() {}
	virtual void itemEffect(Player*) = 0;
	virtual void printItemEffect() = 0;
	virtual void itemAfterEffect(Player*) = 0;
	virtual string getName() = 0;
};

#endif
