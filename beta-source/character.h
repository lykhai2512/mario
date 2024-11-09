#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
const float GravitationalPull = 1.5;

class Character {
protected:
	float Vx = 0, Vy = 0;
	bool isMidAir; // check if character is midair;
	float VxAccel; // horizontal acceleration
	float MaxVx;   // max horizontal speed
	float VxDecel; // deceleration of horizontal movement
	float VyInstantaneousSpeed; // for jumps
	std::vector <sf::Texture> textureList; // for animations, for now this stays unimplemented
	sf::Vector2u spriteSize;
public:
	sf::Sprite charSprite;
	sf::RectangleShape debug;
	Character(float VxAccel, float MaxVx, float VxDecel, float VyInstSpeed, std::string pathToTexture);
	sf::Vector2f getPosition();
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f a);
	void updateSpeed();
	void move(float dT, float screenDepth);
	void affect(Character& b); // this stays unimplemented
};

Character::Character(float VxAccel, float MaxVx, float VxDecel, float VyInstSpeed, std::string pathToTexture)
{
	this->VxAccel = VxAccel;
	this->MaxVx = MaxVx;
	this->VxDecel = VxDecel;
	this->VyInstantaneousSpeed = VyInstSpeed;
	sf::Texture a;
	a.loadFromFile(pathToTexture);
	this->charSprite.setTexture(a);
	this->spriteSize = a.getSize();
	sf::RectangleShape b(sf::Vector2f(100, 100));
	this->debug = b;
	this->isMidAir = true;
	debug.setFillColor(sf::Color::Red);
	// currently this is set for debug 
}

sf::Vector2f Character::getPosition() // currently this is set for debug 
{
	return this->debug.getPosition();
}

void Character::updateSpeed() // for now this method is used for the one character in the executable. later on this entire class will be a base class, from which other characters will inherit, and each will have their own way of movement
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
	{
		this->Vx -= (this->Vx >= -this->MaxVx) ? this->VxAccel : 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->Vx += (this->Vx <= this->MaxVx) ? this->VxAccel : 0;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && !this->isMidAir) {
		this->Vy = -this->VyInstantaneousSpeed;
		this->isMidAir = true;
	}

}

void Character::move(float dT, float screenDepth) // currently this is set for debug 
{
	this->debug.move(Vx * dT * 60, Vy * dT * 60);
	
	if (this->Vx > 0) {
		this->Vx -= VxDecel;
		this->Vx = (this->Vx < 0) ? 0 : this->Vx;
	}
	else
	{
		this->Vx += VxDecel;
		this->Vx = (this->Vx > 0) ? 0 : this->Vx;
	} // these tick Vx down to 0;

	if (this->isMidAir)
		Vy += GravitationalPull;

	if (this->debug.getPosition().y > screenDepth - this->debug.getSize().y) {
		this->isMidAir = false;
		this->debug.setPosition(this->debug.getPosition().x, screenDepth - this->debug.getSize().y);
		this->Vy = 0;

	}
}

void Character::setPosition(float x, float y) // currently this is set for debug 
{
	this->debug.setPosition(x, y);
}

void Character::setPosition(sf::Vector2f a) // currently this is set for debug 
{
	this->debug.setPosition(a);
}