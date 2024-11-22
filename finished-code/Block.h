#pragma once
#include<map>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Animation.h"

class Block{
protected:
	
	bool alive = true;
	sf::Vector2f position;
	sf::Texture* texture;
	sf::Sprite* sprite;
	sf::RectangleShape shape;

public:
	
	Block();

	~Block();

	static Block* createBlock(ID type, const std::string& image_file, sf::Vector2f position,sf::Vector2f size);
    virtual void die();

	virtual void beingStoodOn();

	virtual void beingHit();

	virtual bool isDead();
	virtual void draw(sf::RenderWindow* window);
	
	virtual void update();
};

