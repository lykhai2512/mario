#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include <iostream>
#include <cmath>
#include <vector>
#include "Cloud.h"

int main() {
    std::vector<sf::Texture*> garbage;
    std::vector<sf::Sprite*> sprites;

    const float acceleration = 1.f;
    const float gravity = 10.f;
    float velocity = 0.f;
    float velocityUp = 0.f;

    sf::RectangleShape shape(sf::Vector2f(32, 64));
    shape.setPosition(500.f, 500.f);

    std::string fileName = "C:/Users/Admin/Pictures/Saved Pictures/mario";
    for (int i = 6; i <= 10; i++) {
        std::string newfile = fileName + "_right" + std::to_string(i) + ".png";

        sf::Texture* temp = new sf::Texture;
        temp->loadFromFile(newfile);
        garbage.push_back(temp);

        sf::Sprite* test = new sf::Sprite;
        test->setTexture(*temp);
        test->setPosition(500, 500);
        sprites.push_back(test);
    }

    int numSprite = 0;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1200, 900), "MARIO BROS 1985!");
    sf::Event* ev = new sf::Event;
    sf::Clock clock;
    sf::Time time;
    sf::Time elapsed = clock.getElapsedTime();

    bool isUp = false;

    const float frameDuration = 0.2f;  // Time per animation frame (in seconds)
    float frameTimer = 0.0f;  // Timer for animation frame switch

    while (window->isOpen()) {
        while (window->pollEvent(*ev)) {
            if (ev->type == sf::Event::Closed) {
                window->close();
            }
            if (ev->type == sf::Event::KeyPressed) {
                if (ev->key.code == sf::Keyboard::Escape) {
                    window->close();
                }
            }
        }

        time += clock.getElapsedTime();
        float deltaTime = clock.restart().asSeconds();

        // Update animation frame based on time
        frameTimer += deltaTime;
        if (frameTimer >= frameDuration) {
            frameTimer = 0.0f;  // Reset the frame timer
            if (numSprite < sprites.size() - 1) {
                numSprite++;  // Cycle to the next sprite frame
            }
            else {
                numSprite = 0;  // Loop back to the first frame
            }
        }

        // Mario movement logic
        if (shape.getPosition().y < 500.f) {
            shape.move(0, 0.25);
            isUp = true;
        }
        else {
            isUp = false;
            shape.setPosition(shape.getPosition().x, 500.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            velocity += acceleration;
            shape.move(velocity * deltaTime, 0);
            shape.move(0.25, 0);
            if (numSprite < sprites.size() - 2) numSprite++;
            else numSprite = 0;

            sprites[numSprite]->setScale(1.f, 1.f);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (!isUp) {
                shape.move(-0.25, 0);
                if (numSprite < sprites.size() - 2) numSprite++;
                else numSprite = 0;

                sprites[numSprite]->setScale(-1.f, 1.f);
            }
            else {
                shape.move(-0.25, 0);
                sprites[numSprite]->setScale(-1.f, 1.f);
            }
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (shape.getPosition().y >= 500.f) {
                if (velocityUp >= -300.f) {
                    velocityUp -= 100.f;
                }
                numSprite = sprites.size() - 1;
                isUp = true;
                shape.move(0, velocityUp);
            }
        }
        else {
            if (!isUp) numSprite = 0;
            velocity = 0;
            if (shape.getPosition().y < 464) velocityUp = 0;
        }

        // Draw the current animation frame
        window->clear();
        window->draw(*sprites[numSprite]);
        window->display();
    }

    // Clean up
    delete window;
    delete ev;
    for (auto del : sprites) delete del;
    for (auto gar : garbage) delete gar;

    return 0;
}
