#pragma once

#include <SFML/Graphics.hpp>
#include "Mario.h"
#include "Resources.h"
#include "Renderer.h"
#include "Map.h"

class Game
{
public:
    Game();
    void Run();
    void HandleEvents();
    void Update(float deltaTime, Map& map);
    void Render();

private:
    sf::RenderWindow window;
    Renderer renderer;
    Mario mario;
    Map map;
    sf::Clock clock;  // For tracking deltaTime
};
