#include "Renderer.h"

Renderer::Renderer(sf::RenderTarget& target) : target(target) {}

void Renderer::Draw(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& size)
{
    sprite.setTexture(texture, true);  // Set the texture on the sprite

    sprite.setOrigin(sf::Vector2f(texture.getSize()) / 2.0f );  // Set origin to the center of the texture

    sf::Vector2f scale(size.x / texture.getSize().x, size.y / texture.getSize().y);  // Scale the sprite
    sprite.setScale(scale);

    sprite.setPosition(position);  // Set the sprite's position
    target.draw(sprite);  // Draw the sprite
}



