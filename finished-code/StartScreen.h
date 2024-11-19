#pragma once
#include "GameState.h"
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
class StartScreen : public GameState
{
	StartScreen* runState(sf::RenderWindow& tgt);
};

