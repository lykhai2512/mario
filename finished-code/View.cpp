#include "view.h"

View::View(const sf::RenderWindow &w): 
	m_view(w.getDefaultView()), m_leftLevel(150.0f), m_skyLevel(150.0f), m_rightLevel(w.getSize().x - 150.0f), m_groundLevel(w.getSize().y - 150.0f){
	m_asp[0] = (float)(w.getSize().x);
	m_asp[1] = (float)(w.getSize().y);
}

void View::move(const float& x, const float& y) {
	m_leftLevel += x;
	m_rightLevel += x;
	m_skyLevel += y;
	m_groundLevel += y;
	m_view.setCenter(sf::Vector2f((m_leftLevel + m_rightLevel) / 2, (m_skyLevel + m_groundLevel) / 2));
}

void View::setView(sf::RenderWindow& w) {
	float asp = float(w.getSize().x) / float(w.getSize().y);
	if (asp < 2.0)
		m_view.setSize(m_asp[0]*(asp/2), m_asp[1]);
	else
		m_view.setSize(m_asp[0], m_asp[1]/(asp/2));
	w.setView(m_view);
}

void View::followPlayer(const sf::RectangleShape& s) {
	float x = s.getPosition().x, y = s.getPosition().y;
	if (x <= m_leftLevel)
		move(x - m_leftLevel, 0);
	if (x >= m_rightLevel)
		move(x - m_rightLevel, 0);
	if (y >= m_groundLevel)
		move(0, y - m_groundLevel);
	if (y <= m_skyLevel)
		move(0, y - m_skyLevel);
}

void View::followPlayer(const sf::CircleShape& s) {
	float x = s.getPosition().x, y = s.getPosition().y;
	if (x <= m_leftLevel)
		move(x - m_leftLevel, 0);
	if (x >= m_rightLevel)
		move(x - m_rightLevel, 0);
	if (y >= m_groundLevel)
		move(0, y - m_groundLevel);
	if (y <= m_skyLevel)
		move(0, y - m_skyLevel);
}

bool View::outOfView(const float& x, const float& y, const float& w, const float& h) {
	return (x <= m_leftLevel-150.0f) || (x+w >= m_rightLevel+150.0f) || (y+h >= m_groundLevel+150.0f) || (y <= m_skyLevel-150.0f);
}

bool View::outOfView(const sf::RectangleShape& s) {
	float x = s.getPosition().x, y = s.getPosition().y;
	return (x <= m_leftLevel - 150.0f) || (x >= m_rightLevel + 150.0f) || (y >= m_groundLevel + 150.0f) || (y <= m_skyLevel - 150.0f);
}

bool View::outOfView(const sf::CircleShape& s) {
	float x = s.getPosition().x, y = s.getPosition().y;
	return (x <= m_leftLevel - 150.0f) || (x >= m_rightLevel + 150.0f) || (y >= m_groundLevel + 150.0f) || (y <= m_skyLevel - 150.0f);
}
