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
	sf::RectangleShape* shape;
	float baseGround;
	sf::Texture* animation_texture;
	Animation *animation;

	// additional attributes

	float Vx, Vy;// velocities in 2 axis
	// other attributes like acceleration and deceleration will be declared in classes below (inheriting from) characte r

public:

	Character();

	~Character();

	virtual void move(float dT); // im making this time based whether you like it or not
	virtual void jump(float dT);
	virtual void die();

	virtual void standOn(Block* block);
	virtual void beingStoodOn();

	virtual void reset();

	virtual bool isDead();
	virtual void update();
	virtual void draw(sf::RenderWindow& window);
};

