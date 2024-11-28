#pragma once
#include<map>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Animation.h"

class Block{
protected:
	
	bool alive = true;
	sf::Vector2f position;
	float baseGround;
	sf::RectangleShape *shape;

public:
	
	Block();

	~Block();

	static Block* createBlock(BlockType type, sf::Vector2f position);
    virtual void die();

	virtual void beingStoodOn(float& baseGround, const sf::FloatRect& bounds);

	virtual void beingHit(const sf::FloatRect& bounds,sf::Vector2f& position);
	void beingHitByNonPlayable(const sf::FloatRect& bounds, float& speed);

	virtual bool isDead();
	virtual void draw(sf::RenderWindow* window);
	
	virtual void update();
};

