#pragma once
#include "SFML/Graphics.hpp"
#include "AssetManager.h"
#include "Animation.h"

class Item{

protected:
	bool alive = true;

	sf::Vector2f position;
	sf::Texture* texture;
	sf::Sprite* sprite;
	sf::RectangleShape *shape;
	Animation* animation;
	float baseGround;

public:
	Item();

	~Item();
	
	static Item* createItem(ID type, const std::string& image_file, sf::Vector2f position, sf::Vector2f size);

	virtual void move();
	virtual void die();

	virtual void beingCollected();

	virtual void reset();

	virtual bool isDead();
	virtual void update();
	virtual void draw(sf::RenderWindow* window);

	virtual void twinkle();
};
