#pragma once
#include "WorldObject.h"

class Collision {
public:
	void handleAllCollision(std::vector<WorldObject*>good_characters, std::vector<WorldObject*>bad_characters
	, std::vector<WorldObject*>items, std::vector<WorldObject*>blocks);

	void GoodCharacterAndItem(WorldObject* good_character, WorldObject* item);
	void GoodCharacterAndBlock(WorldObject* good_character, WorldObject* block);
	void GoodCharacterAndBadCharacter(WorldObject* good_character, WorldObject* bad_character);
	void BadCharacterAndItem(WorldObject* bad_character, WorldObject* item);
	void BadCharacterAndBlock(WorldObject* bad_character, WorldObject* block);
	void ItemAndBlock(WorldObject* item, WorldObject* block);
};