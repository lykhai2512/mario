#include "Game.h"
#include "map.h"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(1200, 1000), "Mario Game"),
    renderer(window),
    mario(0, 0),
    map(40)  // Assuming each cell in the map is PxP pixels
{
    // Load map and get Mario's initial position
    sf::Vector2f marioPosition = map.LoadFromFile("resources/maps/map.txt");
    mario.setPosition(marioPosition);

    // Load textures
    if (!Resources::textures["brick.png"].loadFromFile("resources/textures/brick.png")) {
        std::cerr << "Failed to load brick texture!" << std::endl;
    }

    if (!Resources::textures["mario.png"].loadFromFile("resources/textures/mario.png")) {
        std::cerr << "Failed to load mario texture!" << std::endl;
    }

    // Calculate the map dimensions based on grid size
    float mapWidth = map.grid[0].size() * map.cellSize; 
    float mapHeight = map.grid.size() * map.cellSize;     

    sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    view.setCenter(mapWidth / 2.0f, mapHeight / 2.0f);
    window.setView(view);
}


void Game::Run()
{
    // Main game loop
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();  // Restart the clock and get deltaTime

        HandleEvents(); // Handle user input and window events
        Update(deltaTime, map); // Update game objects
        Render(); // Render the updated scene
    }
}

void Game::HandleEvents()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close(); // Close window if the user presses the close button
        }
    }
}

void Game::Update(float deltaTime, Map& map)
{
    // Update the Mario character with the current deltaTime
    mario.Update(deltaTime, map);
}

void Game::Render()
{
    window.clear(sf::Color::Blue);

    // Draw the map and Mario
    map.Draw(renderer);  // Draw the map
    mario.Render(renderer);  // Draw Mario

    window.display(); // Display the updated window
}
