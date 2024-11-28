#pragma once
#include "GameState.h"

class MenuState : public GameState{
	//Get asset from AssetManager and draw
	//allow mouse input, choosing level, choosing character (Luigi,Mario)
private:
	
public:
	void execute(sf::RenderWindow* window);
};

