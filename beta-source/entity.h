#pragma once
#include "view.h"

class Entity {
private:
	sf::RectangleShape m_body;
	sf::Texture m_txt;
	View& m_view;
	float m_velocityX;
	float m_velocityY;
	float hoverBoost;
	float m_gravity;
	bool isGrounded;
	float m_ground;
public:
	Entity(const std::string &filename, const float &x, const float &y, const float &w, const float &h, View& view);
};