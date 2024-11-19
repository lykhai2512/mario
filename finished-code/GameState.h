#pragma once
#include<SFML/Graphics.hpp>

class GameState{
public:
	virtual ~GameState() = default;
	virtual void execute(sf::RenderWindow* window) = 0;
};

