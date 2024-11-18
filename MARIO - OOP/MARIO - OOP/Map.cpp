#include <fstream>
#include <iostream>
#include "Map.h"
#include "Renderer.h"
#include "Resources.h"

Map::Map(float cellSize) : cellSize(cellSize), grid() {}

sf::Vector2f Map::LoadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open map file " << filename << std::endl;
        return {};  // Return default vector (0,0) if file fails to open
    }

    grid.clear();
    std::string line;
    size_t y = 0;
    sf::Vector2f marioPosition;

    while (std::getline(file, line))
    {
        std::vector<int> row;
        for (size_t x = 0; x < line.size(); ++x)
        {
            if (line[x] == '1')
                row.push_back(1);  // Wall (brick)
            else if (line[x] == '0')
                row.push_back(0);  // Empty space
            else if (line[x] == 'M')
            {
                row.push_back(0);  // Mario's start position (considered empty space)
                marioPosition = sf::Vector2f(cellSize * x + cellSize / 2.0f, cellSize * y + cellSize / 2.0f);
            }
        }
        grid.push_back(row);
        y++;
    }

    file.close();
    return marioPosition;
}
 

void Map::Draw(Renderer& renderer)
{
    for (size_t y = 0; y < grid.size(); ++y) // Iterate over rows (y-axis)
    {
        for (size_t x = 0; x < grid[y].size(); ++x) // Iterate over columns (x-axis)
        {
            if (grid[y][x] == 1)  // Check if the current cell is a brick
            {
                renderer.Draw(Resources::textures["brick.png"],
                    sf::Vector2f(cellSize * x, cellSize * y),  // Position based on grid
                    sf::Vector2f(cellSize, cellSize));         // Size of each tile
            }
        }
    }
}

bool Map::IsCollidingWithBrick(const sf::FloatRect& rect) 
{
    for (size_t y = 0; y < grid.size(); ++y) {
        for (size_t x = 0; x < grid[y].size(); ++x) {
            if (grid[y][x] == 1) { // Assuming 1 represents a brick
                sf::FloatRect brickBounds(x * cellSize, y * cellSize, cellSize, cellSize);
                if (brickBounds.intersects(rect)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int Map::getMapHeight()
{
	return grid.size() * cellSize;
}





