#include "Mario.h"
#include "Resources.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>

Mario::Mario(float x, float y)
    : Character(x, y, 100.0f) {
} // Initialize base class with position and speed

void Mario::Update(float deltaTime, Map& map) {
    sf::Vector2f oldPosition = position;
    sf::FloatRect marioBounds(position, sf::Vector2f(32.0f, 32.0f)); // Adjust for Mario's size

    float movementSpeed = static_cast<float>(speed) * deltaTime;

    // Handle movement and collisions
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position.x += movementSpeed;
        marioBounds.left = position.x;
        if (map.IsCollidingWithBrick(marioBounds)) {
            position.x = oldPosition.x; // Revert if colliding
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position.x -= movementSpeed;
        marioBounds.left = position.x;
        if (map.IsCollidingWithBrick(marioBounds)) {
            position.x = oldPosition.x; // Revert if colliding
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        position.y -= movementSpeed;
        marioBounds.top = position.y;
        if (map.IsCollidingWithBrick(marioBounds)) {
            position.y = oldPosition.y; // Revert if colliding
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        position.y += movementSpeed;
        marioBounds.top = position.y;
        if (map.IsCollidingWithBrick(marioBounds)) {
            position.y = oldPosition.y; // Revert if colliding
        }
    }
}

void Mario::Render(Renderer& renderer) {
    sf::Sprite sprite;
    sprite.setTexture(Resources::textures["mario.png"]);
    sprite.setOrigin(16, 16);  // Assuming sprite size is 32x32
    sprite.setRotation(angle); // Apply rotation if needed

    renderer.Draw(Resources::textures["mario.png"], position, sf::Vector2f(32.0f, 32.0f));
}

void Mario::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;
}
