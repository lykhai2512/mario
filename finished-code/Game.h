#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

class Game {
private:
	
	sf::RenderWindow* window;
	sf::Event* ev;
	GameState* currentState;
public:
	void run();
	~Game();
};