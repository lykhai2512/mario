#pragma once
#include "Character.h"
#include "PlayableCharacter.h"
#include "NonPlayableCharacter.h"
#include "Block.h"
#include "Item.h"

class Collision {
public:
	void handleAllCollision(std::vector<PlayableCharacter*>good_characters, std::vector<NonPlayableCharacter*>bad_characters
	, std::vector<Item*>items, std::vector<Block*>blocks);

	void GoodCharacterAndBlock(PlayableCharacter* good_character, Block* block);
	void BadCharacterAndBlock(NonPlayableCharacter* bad_character, Block* block);
	void GoodCharacterAndItem(PlayableCharacter* good_character, Item* item);
	void GoodCharacterAndBadCharacter(PlayableCharacter* good_character, NonPlayableCharacter* bad_character);
	void BadCharacterAndBadCharacter(NonPlayableCharacter* bad_character, NonPlayableCharacter* bad_character2);
	void ItemAndBlock(Item* item, Block* block);
};