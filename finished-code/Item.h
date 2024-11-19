#pragma once
#include "WorldObject.h"


class Item : public WorldObject{

protected:
	bool alive = true;

	sf::Vector2f position;
	sf::Texture* texture;
	sf::RectangleShape shape;
	float baseGround;

public:
	Item();

	~Item();
	
	static Item* createItem(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size);

	void move();
	void jump();
	void die();

	void collect(WorldObject* item);
	void beingCollected(sf::Vector2f& position, sf::Texture*& texture, sf::FloatRect& bounds, float& baseGround);

	void standOn(WorldObject* block);
	void beingStoodOn(sf::Vector2f& position, sf::Texture* texture, sf::FloatRect& bounds, float& baseGround);

	void hit(WorldObject* object);
	void beingHit(sf::Vector2f& position, sf::Texture* texture, sf::FloatRect& bounds, float& baseGround);

	bool isDead();
	void update();
	void draw(sf::RenderWindow* window);
};
