#pragma once
#include<SFML/Graphics.hpp>

class GameState{
protected:
	bool active = false;
public:
	GameState();
	virtual ~GameState() = default;
	virtual void execute(sf::RenderWindow* window) = 0;
};

