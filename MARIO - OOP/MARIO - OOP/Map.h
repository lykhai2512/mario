#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>     
#include "Renderer.h"
#include "Resources.h"
#ifndef MAP_H
#define MAP_H
class Map {
public:
    Map(float cellSize);
    sf::Vector2f LoadFromFile(const std::string& filename);
    void Draw(Renderer& renderer);
    bool IsCollidingWithBrick(const sf::FloatRect& rect);
    int getMapHeight();

//private:
    float cellSize;
    std::vector<std::vector<int>> grid;
    float speed = 100.0f;  // Example variable for speed
};

#endif