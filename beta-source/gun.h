#pragma once
#include "view.h"

class Bullet {
private:
	sf::CircleShape m_body;
	float m_velocityX;
	float m_velocityY;
	View& m_view;
	bool m_out;
public:
	Bullet(const float& x, const float& y, const float& a, const float& v, const float& r, View& view);
	Bullet& operator=(const Bullet& b);
	bool outOfView();
	void move();
	void displayBullet(sf::RenderWindow& w);
};

class Gun {
private:
	std::vector<Bullet> m_bullets;
	int m_ammo;
	int m_mag;
	int m_cooldown;
	int m_cooldown_time;
	int m_reload_time;
	int m_reload;
	float m_angle;
	View& m_view;
	bool random1;
	bool random2;
public:
	Gun(View& view);
	void load(const float &x, const float &y);
	void tilt(const bool& sign);
	bool isCooldown();
	bool isReload();
	void cooldown();
	void reload();
	void unload();
	void displayBullets(sf::RenderWindow& w);
};