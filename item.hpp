#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include "player.hpp"

class Item {
public:	
	virtual void itemEffect(Player*) = 0;
	virtual void printItemEffect() = 0;
	virtual void itemAfterEffect(Player*) = 0;
	
};

#endif
