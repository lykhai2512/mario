#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include "PlayingState.h"

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1200, 600), "MARIO");
    sf::Event *ev = new sf::Event;
    PlayingState test;
    sf::Clock clock;

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

        window->clear(sf::Color(92,148,252));
        test.execute(window);
        window->display();
    }

    delete ev;
    delete window;

    return 0;
}


 

