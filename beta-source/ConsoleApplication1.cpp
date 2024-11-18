#include "view.h"
#include "gun.h"

int main() {
    // Create a window with a title and size 800x600
    sf::RenderWindow window(sf::VideoMode(1600, 800), "SFML Movable Object with Gravity");
    sf::Texture neko;
    neko.loadFromFile("neko2.png");
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    player.setTexture(&neko);
    player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
    View mainView(window);
    window.setFramerateLimit(60);
    
    
    sf::CircleShape hihi(200);
    hihi.setPosition(900, 0);
    player.setPosition(0, 200); // Initial position (near the middle of the screen)
    // Variables for gravity and movement
    float moveSpeed = 15.0f;        // Horizontal movement speed
    float gravity = 0.4f;          // Gravity acceleration
    float jumpSpeed = -20.0f;      // Jump impulse
    float yVelocity = 0.0f;        // Vertical speed
    bool isGrounded = false;       // Is the object on the ground?
    float hoverBoost = -0.15f;
    
    float groundLevel = 750;
    float groundCam = groundLevel;

    sf::RectangleShape lowerArea(sf::Vector2f(800, 800));
    lowerArea.setPosition(0, groundLevel);
    lowerArea.setFillColor(sf::Color::Green);

    bool isFlippedHorizontally = false;

    Gun ak47(mainView);
    while (window.isOpen()) {
        sf::Event event; 
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        hihi.setFillColor(sf::Color::White);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            player.move(-moveSpeed, 0); // Move left
            player.setScale(-1.0f, 1.0f); // Flip horizontally
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            player.move(moveSpeed, 0); // Move right
            player.setScale(1.0f, 1.0f); // Normal orientation
        }

        if (!isGrounded) {
            yVelocity += gravity; // Increase downward velocity by gravity
            player.setFillColor(yVelocity < 0 ? sf::Color::Yellow : sf::Color::Cyan);
        }

        // Jumping (only allowed when on the ground)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isGrounded) {
            yVelocity = jumpSpeed; // Apply jump impulse
            isGrounded = false;    // No longer grounded when jumping
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isGrounded && yVelocity <= 0) {
            yVelocity += hoverBoost;
            player.setFillColor(sf::Color::Green);
        }
         
        if (ak47.isCooldown()) ak47.cooldown();
        if (ak47.isReload()) ak47.reload();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !ak47.isCooldown()) {
            ak47.load(player.getPosition().x, player.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            ak47.tilt(true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            ak47.tilt(false);
        }
        ak47.unload();
        // Update vertical position based on yVelocity
        player.move(0, yVelocity);

        // Collision with the ground
        if (player.getPosition().y >= groundLevel) {
            player.setPosition(player.getPosition().x, groundLevel); // Snap to ground
            yVelocity = 0;  // Reset vertical velocity
            isGrounded = true;  // The player is now grounded
            player.setFillColor(sf::Color::White);
        }

        mainView.followPlayer(player.getPosition().x, player.getPosition().y, 0, 0);
        window.clear(sf::Color::Black);
        
        mainView.setView(window);
        window.draw(hihi);
        window.draw(player);
        //window.draw(lowerArea);
        ak47.displayBullets(window);
        window.display();
    }
    return 0;
}
