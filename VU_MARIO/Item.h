#pragma once
#include "SFML/Graphics.hpp"
#include "AssetManager.h"
#include "Animation.h"

class Item{

protected:
	bool alive = true;

	sf::Vector2f position;
	sf::Sprite* sprite;
	sf::RectangleShape *shape;
	Animation* animation;
	float baseGround;

public:
	Item();

	~Item();
	
	static Item* createItem(ItemType type,sf::Vector2f position);

	virtual void move();
	virtual void die();

	virtual void beingCollected(const sf::FloatRect& bounds);

	virtual void reset();

	virtual bool isDead();
	virtual void update();
	virtual void draw(sf::RenderWindow* window);

	virtual void twinkle();
};
