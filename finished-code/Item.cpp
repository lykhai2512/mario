#include "Item.h"

Item* Item::createItem(ItemType type)
{
	switch (type)
	{
	case ItemType::GoodMushroom:
		//return new GoodMushroom;
		break;
	case ItemType::Flower:
		break;
	case ItemType::Coin:
		break;
	case ItemType::Star:
		break;
	default:
		break;
	}

	return nullptr;
}

void Item::move(){}

void Item::jump(){}

void Item::die(){}