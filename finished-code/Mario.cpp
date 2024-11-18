#include "Mario.h"
#include <iostream>

void tickDownToZero(float& n, float amount)
{
	if (n > 0)
	{
		n -= amount;
		n = (n < 0) ? 0 : n;
	}
	else if (n < 0)
	{
		n += amount;
		n = (n > 0) ? 0 : n;
	}
}



Mario::Mario(sf::Texture &tS, float XA, float maxXA, float YA, float XD, int sizeX, int sizeY) :textureSource(tS), XAccel(XA), YAccel(YA), XDecel(XD), sizeX(sizeX), sizeY(sizeY), XCap(maxXA) {
	this->Vx = 0;
	this->Vy = 0;
	this->isMidAid = 1;
	this->isAlive = 1;
	sf::Sprite buff(tS);
	this->sprite = buff;
	//this->sprite.setTextureRect(sf::IntRect(0, 0, this->sizeX, this->sizeY));
	//this->sprite.setColor(sf::Color::Red);
}

void Mario::move(float dT)
{
	float frame = 40;
	//std::cout << "Vx: " << this->Vx << " Vy: " << this->Vy << "\n";
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && !this->isMidAid)
	{
		this->Vy = -this->YAccel;
		this->isMidAid = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->Vx -= this->XAccel * dT * frame;
		if (Vx < -this->XCap)
			Vx = -this->XCap;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->Vx += this->XAccel * dT * frame;
		if (Vx > this->XCap)
			Vx = this->XCap;
	}

	this->sprite.move(Vx * dT * frame, Vy * dT * frame);
	tickDownToZero(Vx, XDecel * dT * frame);
	if(this->isMidAid)
		Vy += 3 * dT * frame;
	/*
	if (!!collision with floor)
	{
		this->isMidAir = false;
		this->setPosition();
		this->Vy = 0;
	}
	else
		this->isMidAir = true;
	*/

	if (this->sprite.getPosition().y > 300)
	{
		this->isMidAid = false;
		this->setPosition(sf::Vector2f(this->sprite.getPosition().x, 300)); // hard coded for now
		this->Vy = 0;
	}
	//else
	//	this->isMidAid = true;
	//	
}

void Mario::setPosition(sf::Vector2f a)
{
	this->sprite.setPosition(a);
}

void Mario::collect(WorldObject* a)
{

}

void Mario::die()
{
	this->isAlive = false;
}
//
void Mario::jump()
{
	std::cout << "nah";
}
//
void Mario::standOn(WorldObject* obj)
{
	std::cout << "nah";
}

void Mario::hit(WorldObject* obj)
{
	std::cout << "nah";
}

bool Mario::isDead()
{
	return !this->isAlive;
}

void Mario::draw(sf::RenderWindow &window)
{
	window.draw(this->sprite);
}

sf::Vector2f Mario::getPosition()
{
	return this->sprite.getPosition();
}

void Mario::setPositionFor(WorldObject* object)
{
}

void Mario::mapCollisionHandler(Map &topo)
{
	int indexI, indexJ;
	indexI = this->getPosition().y / 32.0;
	indexJ = this->getPosition().x / 32.0;
	std::cout << "MARIO POS: " << this->getPosition().x << ", " << this->getPosition().y << "\n"
		<< "I, J:      " << indexI << ", " << indexJ << "\n";
	

	
	int ILimit = topo.getArea().y, JLimit = topo.getArea().x;

	int sideIndexI[4]{ 0, 1, -1, 0 }; // left, down, up, right
	int sideIndexJ[4]{ -1, 0, 0, 1 };

	//if (indexI + sideIndexI[0] >= 0 && indexI + sideIndexI[0] < ILimit &&
	//	indexJ + sideIndexJ[0] >= 0 && indexJ + sideIndexJ[0] < JLimit &&
	//	topo[indexI + sideIndexI[0]][indexJ + sideIndexJ[1]] &&
	//	this->sprite.getGlobalBounds().intersects(topo[indexI + sideIndexI[0]][indexJ + sideIndexJ[0]]->getGlobalBounds())
	//	)
	//{// left
	//	std::cout << "colliding, left\n";
	//	std::cout << "checkint at square " << indexI + sideIndexI[0] << ", " << indexJ + sideIndexJ[0] << "\n";
	//	this->setPosition(sf::Vector2f(topo[indexI + sideIndexI[0]][indexJ + sideIndexJ[0]]->getGlobalBounds().left + 32, this->getPosition().y));
	//}
	
	std::cout << "CHK: " << indexI + sideIndexI[1] << ", " << indexJ + sideIndexJ[1] << "\n\n";

	if (indexI + sideIndexI[1] >= 0 && indexI + sideIndexI[1] < ILimit &&
		indexJ + sideIndexJ[1] >= 0 && indexJ + sideIndexJ[1] < JLimit &&
		topo[indexI + sideIndexI[1]][indexJ + sideIndexJ[1]] &&
		this->sprite.getGlobalBounds().intersects(topo[indexI + sideIndexI[1]][indexJ + sideIndexJ[1]]->getGlobalBounds())
		)
	{// down
		std::cout << "////////\n////////\n////////\n////////\n";
		std::cout << "colliding, down\n";
		std::cout << "checkint at square " << indexI + sideIndexI[1] << ", " << indexJ + sideIndexJ[1] << "\n";
		this->setPosition(sf::Vector2f(this->getPosition().x, topo[indexI + sideIndexI[1]][indexJ + sideIndexJ[1]]->getPosition().y - 32));
		this->Vy = 0;
		this->isMidAid = false;
	}
	else
		this->isMidAid = true;

}