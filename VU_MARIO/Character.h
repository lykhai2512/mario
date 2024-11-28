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
<<<<<<< HEAD:VU_MARIO/Character.h
	sf::RectangleShape *shape;
=======
	sf::Texture* texture;
	sf::RectangleShape* shape;
>>>>>>> 38eac82cadfc71f71e720716daf4a46ad0c2b960:finished-code/Character.h
	float baseGround;
	Animation *animation;

<<<<<<< HEAD:VU_MARIO/Character.h
	void initVariables(sf::Vector2f position, std::vector<AnimationStrategy*> animationStrategy, std::pair<sf::Texture*, std::vector<sf::IntRect>> images);
=======
	// additional attributes

	float Vx, Vy;// velocities in 2 axis
	// other attributes like acceleration and deceleration will be declared in classes below (inheriting from) characte r

>>>>>>> 38eac82cadfc71f71e720716daf4a46ad0c2b960:finished-code/Character.h
public:

	Character();

	~Character();

<<<<<<< HEAD:VU_MARIO/Character.h
	void move();
	virtual void jump();
=======
	virtual void move(float dT); // im making this time based whether you like it or not
	virtual void jump(float dT);
>>>>>>> 38eac82cadfc71f71e720716daf4a46ad0c2b960:finished-code/Character.h
	virtual void die();

	void standOnBlock(Block* block);
	virtual void beingStoodOn();

	virtual void reset();

	virtual bool isDead();
	virtual void update();
	virtual void draw(sf::RenderWindow& window);
};

