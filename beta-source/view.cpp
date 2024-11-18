#include "view.h"

View::View(const sf::RenderWindow &w) : m_view(w.getDefaultView()), m_leftLevel(150.0f), m_skyLevel(150.0f), m_rightLevel(w.getSize().x-150.0f), m_groundLevel(w.getSize().y - 150.0f){}

void View::move(const float& x, const float& y) {
	m_leftLevel += x;
	m_rightLevel += x;
	m_skyLevel += y;
	m_groundLevel += y;
	m_view.setCenter(sf::Vector2f((m_leftLevel + m_rightLevel) / 2, (m_skyLevel + m_groundLevel) / 2));
}

void View::setView(sf::RenderWindow& w) {
	w.setView(m_view);
}

void View::followPlayer(const float& x, const float& y, const float& w, const float& h) {
	if (x <= m_leftLevel)
		move(x - m_leftLevel, 0);
	if (x+w >= m_rightLevel)
		move(x+w - m_rightLevel, 0);
	if (y+h >= m_groundLevel)
		move(0, y+h - m_groundLevel);
	if (y <= m_skyLevel)
		move(0, y - m_skyLevel);
}

bool View::outOfView(const float& x, const float& y, const float& w, const float& h) {
	return (x <= m_leftLevel-150.0f) || (x + w >= m_rightLevel+150.0f) || (y + h >= m_groundLevel+150.0f) || (y <= m_skyLevel-150.0f);
}