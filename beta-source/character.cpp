#include "character.h"

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

void Character::setPosition(sf::Vector2f a) // currently this is set for debug 
{
	this->debug.setPosition(a);
}