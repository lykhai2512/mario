#include "Collision.h"


void Collision::handleAllCollision(std::vector<PlayableCharacter*> good_characters, std::vector<NonPlayableCharacter*> bad_characters, std::vector<Item*> items, std::vector<Block*> blocks){
	for (PlayableCharacter* good_character : good_characters) {
		good_character->reset();
		for (Block* block : blocks) {
			GoodCharacterAndBlock(good_character, block);
		}
	}

	for (NonPlayableCharacter* bad_character : bad_characters) {
		bad_character->reset();
		for (Block* block : blocks) {
			BadCharacterAndBlock(bad_character, block);
		}
	}

	for (PlayableCharacter* good_character : good_characters) {
		for (NonPlayableCharacter* bad_character : bad_characters) {
			GoodCharacterAndBadCharacter(good_character, bad_character);
		}
	}

	int enemies_size = bad_characters.size();

	for (int i = 0; i < enemies_size - 1; i++) {
		for (int j = i + 1; j < enemies_size; j++) {
			BadCharacterAndBadCharacter(bad_characters[i], bad_characters[j]);
		}
	}
	
	for (PlayableCharacter* good_character : good_characters) {
		for (Item* item : items) {
			GoodCharacterAndItem(good_character, item);
		}
	}

}

void Collision::GoodCharacterAndBlock(PlayableCharacter* good_character, Block* block){
	if (!good_character->isDead() && !block->isDead()) {
		good_character->standOnBlock(block);
		good_character->hit(block);
	}
}

void Collision::BadCharacterAndBlock(NonPlayableCharacter* bad_character, Block* block){
	if (!bad_character->isDead() && !block->isDead()) {
		bad_character->standOnBlock(block);
		bad_character->hit(block);
	}
}

void Collision::GoodCharacterAndItem(PlayableCharacter* good_character, Item* item){
	if (!good_character->isDead() && !item->isDead()) {
		good_character->collect(item);
	}
}

void Collision::GoodCharacterAndBadCharacter(PlayableCharacter* good_character, NonPlayableCharacter* bad_character){
	if (!good_character->isDead() && !bad_character->isDead()) {
		good_character->standOn(bad_character);
		good_character->hit(bad_character);
	}
}

void Collision::BadCharacterAndBadCharacter(NonPlayableCharacter* bad_character, NonPlayableCharacter* bad_character2){
	if (!bad_character->isDead() && !bad_character2->isDead()) {
		bad_character->hit(bad_character2);
	}
}

void Collision::ItemAndBlock(Item* item, Block* block)
{
}


