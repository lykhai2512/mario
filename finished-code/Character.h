#pragma once

#include "Block.h"
#include "Item.h"
#include "Animation.h"
#include "AssetManager.h"


class Character{
protected:
	bool alive = true;
	bool hasDoneSth = false;
	sf::Sprite *sprite;
	sf::Vector2f position;
	sf::Texture* texture;
	sf::RectangleShape *shape;
	float baseGround;
	sf::Texture* animation_texture;
	Animation *animation;
public:

	Character();

	~Character();

	virtual void move();
	virtual void jump();
	virtual void die();

	virtual void standOn(Block* block);
	virtual void beingStoodOn();

	virtual void reset();

	virtual bool isDead();
	virtual void update();
	virtual void draw(sf::RenderWindow* window);
};

