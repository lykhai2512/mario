#pragma once
#include<map>
#include <SFML/Graphics.hpp>
#include "WorldObject.h"
#include "AssetManager.h"



class Block : public WorldObject{
private:
	
	static std::map<int, sf::Vector2f>size;

	bool alive = true;

	sf::Vector2f position;
	sf::Texture* texture;
	sf::RectangleShape shape;	

public:
	

	Block();

	~Block();

	static Block* createBlock(BlockType type,const std::string& image_file,sf::Vector2f position);
	void move();
    void jump();
    void die();
    void collect(WorldObject* object);
    void standOn(WorldObject* object);
    void setPositionFor(WorldObject* object);
    void hit(WorldObject* object);
	bool isDead();
	void draw(sf::RenderWindow* window);
};

