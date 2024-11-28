#pragma once
#include "Block.h"
#include "Item.h"
#include "Animation.h"
#include "AssetManager.h"

class Character{
protected:
	float Vx;
	float Vy;
	bool alive = true;
	bool hasDoneSth = false;
	sf::Sprite *sprite;
	sf::Vector2f position;
	sf::RectangleShape *shape;
	float baseGround;
	Animation *animation;

	void initVariables(sf::Vector2f position, std::vector<AnimationStrategy*> animationStrategy, std::pair<sf::Texture*, std::vector<sf::IntRect>> images);
public:

	Character();

	~Character();

	void move();
	virtual void jump();
	virtual void die();

	void standOnBlock(Block* block);
	virtual void beingStoodOn();

	virtual void reset();

	virtual bool isDead();
	virtual void update();
	virtual void draw(sf::RenderWindow* window);
};

