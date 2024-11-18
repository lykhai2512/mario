#ifndef RESOURCES_H
#define RESOURCES_H

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

class Resources {
public:
    static std::unordered_map<std::string, sf::Texture> textures;  // Static member declaration
};

#endif // RESOURCES_H
