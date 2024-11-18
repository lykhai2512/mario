#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <random>
#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <string>

const float PI = 3.141592653f;
const float grav = 9.8f;
class View{
private:
	float m_leftLevel;
	sf::View m_view;
	float m_rightLevel;
	float m_groundLevel;
	float m_skyLevel;
public:
	View(const sf::RenderWindow& w);
	void move(const float& x, const float& y);
	void setView(sf::RenderWindow& w);

	void followPlayer(const float& x, const float& y, const float& w, const float &h);
	bool outOfView(const float& x, const float& y, const float& w, const float& h);
};