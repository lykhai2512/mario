#include "Collision.h"

void Collision::handleAllCollision(std::vector<WorldObject*> good_characters, std::vector<WorldObject*> bad_characters, std::vector<WorldObject*> items, std::vector<WorldObject*> blocks){
	for (WorldObject* good_character : good_characters) {
		for (WorldObject* bad_character : bad_characters) {
			this->GoodCharacterAndBadCharacter(good_character, bad_character);
		}
	}

	for (WorldObject* good_character : good_characters) {
		for (WorldObject* block : blocks) {
			this->GoodCharacterAndBlock(good_character, block);
		}
	}

	for (WorldObject* good_character : good_characters) {
		for (WorldObject* item : items) {
			this->GoodCharacterAndItem(good_character, item);
		}
	}

	for (WorldObject* bad_character : bad_characters) {
		for (WorldObject* block : blocks) {
			this->BadCharacterAndBlock(bad_character, block);
		}
	}

	for (WorldObject* bad_character : bad_characters) {
		for (WorldObject* item : items) {
			this->BadCharacterAndItem(bad_character, item);
		}
	}

	for (WorldObject* item : items) {
		for (WorldObject* block : blocks) {
			this->ItemAndBlock(item, block);
		}
	}
}

void Collision::GoodCharacterAndItem(WorldObject* good_character, WorldObject* item){

}

void Collision::GoodCharacterAndBlock(WorldObject* good_character, WorldObject* block){
	good_character->standOn(block);
	//require type,left right under
	good_character->hit(block);
}

void Collision::GoodCharacterAndBadCharacter(WorldObject* good_character, WorldObject* bad_character)
{
}

void Collision::BadCharacterAndItem(WorldObject* bad_character, WorldObject* item)
{
}

void Collision::BadCharacterAndBlock(WorldObject* bad_character, WorldObject* block){
	bad_character->standOn(block);
	//left right
	bad_character->hit(block);
}

void Collision::ItemAndBlock(WorldObject* item, WorldObject* block)
{
}
