#include "gun.h"

Bullet::Bullet(const float& x, const float& y, const float& a, const float& v, const float& r, View& view): m_view(view) {
	m_body.setRadius(r);
	m_body.setFillColor(sf::Color::Red);
	m_body.setPosition(x +50*cosf(a), y-50*sinf(a));
	m_velocityX = v*cosf(a);
	m_velocityY = -v*sinf(a);
	m_out = false;
}

bool Bullet::outOfView() {
	if (m_out) return true;
	if (m_view.outOfView(m_body.getPosition().x, m_body.getPosition().y, m_body.getRadius(), m_body.getRadius())) {
		m_out = true;
		return true;
	}
	else return false;
		
}

void Bullet::move() {
	m_body.move(m_velocityX, m_velocityY);
}

Bullet& Bullet::operator=(const Bullet& b) {
	m_body = sf::CircleShape(b.m_body.getRadius());
	m_velocityX = b.m_velocityX;
	m_velocityY = b.m_velocityY;
	m_view = b.m_view;
	return *this;
}

void Bullet::displayBullet(sf::RenderWindow& w) {
	w.draw(m_body);
}

Gun::Gun(View& view) : m_ammo(500), m_mag(500), m_angle(0), m_cooldown(0), m_reload(0), m_cooldown_time(2), m_reload_time(20), m_view(view){}

void Gun::load(const float& x, const float& y) {
	if (m_ammo > 0) {
		srand(time(0));
		int k = rand() % 5;
		switch (random1) {
		case true:
			switch (random2) {
			case true:
				m_bullets.push_back(Bullet(x, y, m_angle, 50.0f, 10, m_view));
				random2 = false;
				break;
			case false:
				m_bullets.push_back(Bullet(x, y, m_angle + float(rand() % 13 - 6) * PI / 180, 50.0f + float(rand() % 10 - 5), 10, m_view));
				random2 = true;
				random1 = false;
				break;
			}
			break;
		case false:
			switch (random2) {
			case true:
				m_bullets.push_back(Bullet(x, y, m_angle + float(rand() % 11 - 5) * PI / 180, 50.0f + float(rand() % 8 - 3), 10, m_view));
				random2 = false;
				break;
			case false:
				m_bullets.push_back(Bullet(x, y, m_angle + float(rand() % 9 - 4) * PI / 180, 50.0f + float(rand() % 7 - 2), 10, m_view));
				random2 = true;
				random1 = true;
				break;
			}
		}
		//m_bullets.push_back(Bullet(x, y, m_angle, 50.0f, m_view));
		//m_bullets.push_back(Bullet(x, y, m_angle + float(rand() % 11- 5) * PI / 180, 50.0f + float(rand() % 10 - 5), m_view));
		//m_bullets.push_back(Bullet(x, y, m_angle+ float(rand() % 11 - 5) * PI / 180, 50.0f + float(rand() % 11 - 6), m_view));
		//m_bullets.push_back(Bullet(x, y, m_angle+ float(rand() % 31 - 15) * PI / 180, 50.0f + float(rand() % 8 - 3), m_view));
		//m_bullets.push_back(Bullet(x, y, m_angle+ float(rand() % 21 - 10) * PI / 180, 50.0f + float(rand() % 7 - 2), m_view));
		//m_bullets.push_back(Bullet(x, y, m_angle+ float(rand() % 31 - 15) * PI / 180, 50.0f + float(rand() % 4 - 9), m_view));
		//m_bullets.push_back(Bullet(x, y, m_angle+ float(rand() % 11 - 15) * PI / 180, 50.0f + float(rand() % 5 - 1), m_view));
		m_cooldown = m_cooldown_time;
		--m_ammo;
		if (m_ammo == 0) {
			m_reload = m_reload_time;
		}
	}
}

void Gun::unload() {
	bool check = false;
	for (size_t i = 0; i < m_bullets.size(); i++) {
		if (!m_bullets[i].outOfView()) {
			m_bullets[i].move();
			check = true;
		}
	}
	if (!check)
		m_bullets.clear();
}

bool Gun::isCooldown() {
	return m_cooldown != 0;
}

bool Gun::isReload() {
	return m_reload != 0;
}

void Gun::tilt(const bool &sign) {
	if (sign) m_angle += PI / 180;
	else m_angle -= PI / 180;
	if (m_angle >= 2 * PI)
		m_angle -= 2 * PI;
	if (m_angle <= 0)
		m_angle += 2 * PI;
}

void Gun::cooldown() {
	--m_cooldown;
}

void Gun::reload() {
	--m_reload;
	if (m_reload == 0)
		m_ammo = m_mag;
}

void Gun::displayBullets(sf::RenderWindow& w) {
	for (Bullet b : m_bullets) {
		if (!b.outOfView())
			b.displayBullet(w);
	}
}
