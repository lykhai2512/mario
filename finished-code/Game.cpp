#include "Game.h"
#include "MenuState.h"

void Game::run(){
	window = new sf::RenderWindow(sf::VideoMode(1200,900), "MARIO BROS 1985!");
	this->currentState = new MenuState;
	
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

        window->clear();
        this->currentState->execute(window);
        window->display();
    }

}

Game::~Game(){
	delete this->currentState;
	delete this->window;
	delete this->ev;
}
