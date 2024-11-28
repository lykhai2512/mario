#include "View.h"


View::View() {
	view = nullptr;
}

View::View(sf::FloatRect floatRect) {
	view = new sf::View(floatRect);
}

View::~View() {
	delete view;
}

void View::update(std::vector<PlayableCharacter*> playable, sf::RenderWindow* window){
	float minPositionX = std::numeric_limits<float>::max();
	PlayableCharacter* chosen_character = nullptr;

	for (PlayableCharacter* character : playable) {
		if (character->findMinForView(minPositionX)) {
			chosen_character = character;
		}
	}

	//chosen_character->setCenterForView(this->view);
	
	if (minPositionX > window->getSize().x / 2) {
		chosen_character->setCenterForView(view);
	}
}

void View::setForWindow(sf::RenderWindow* window){
	window->setView(*view);
}
