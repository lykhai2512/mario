#pragma once
#include "Item.h"

class Coin : public Item{
public:
	Coin();
	
	void beingCollected();
	void twinkle();
};

