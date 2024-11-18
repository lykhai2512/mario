#include "entity.h"

Entity::Entity(const std::string &filename, const float& x, const float& y, const float& w, const float& h, View& view): m_view(view){
	m_body = sf::RectangleShape(sf::Vector2f(w, h));
	m_txt.loadFromFile(filename);
	m_body.setTexture(&m_txt);
	m_body.setOrigin(m_body.getSize().x / 2.0f, m_body.getSize().y / 2.0f);
	m_body.setPosition(x, y);
}