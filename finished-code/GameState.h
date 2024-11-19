#pragma once
#include <SFML/Graphics.hpp>

class GameState
{
public:
	virtual GameState* runState(sf::RenderWindow& tgt) = 0;
};

