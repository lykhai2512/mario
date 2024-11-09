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
	sf::Texture mainTexture;
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

