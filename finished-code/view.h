#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class View{
private:
	float m_leftLevel;
	sf::View m_view;
	float m_rightLevel;
	float m_groundLevel;
	float m_skyLevel;
	float m_asp[2];
public:
	View(const sf::RenderWindow& w);
	void move(const float& x, const float& y);
	void setView(sf::RenderWindow& w);

	void followPlayer(const sf::RectangleShape &s);
	void followPlayer(const sf::CircleShape& s);

	bool outOfView(const float& x, const float& y, const float& w, const float& h);
	bool outOfView(const sf::RectangleShape& s);
	bool outOfView(const sf::CircleShape& s);
};
