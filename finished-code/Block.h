#pragma once
#include<map>
#include <SFML/Graphics.hpp>
#include "WorldObject.h"
#include "AssetManager.h"

class Block : public WorldObject{
protected:
	
	bool alive = true;

	sf::Vector2f position;
	sf::Texture* texture;
	sf::RectangleShape shape;	

public:
	

	Block();

	~Block();

	static Block* createBlock(ID type, const std::string& image_file, sf::Vector2f position,sf::Vector2f size);
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
	void draw(sf::RenderWindow* window);
	
	void update();
};

