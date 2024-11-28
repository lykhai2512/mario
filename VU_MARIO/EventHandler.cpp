#include "EventHandler.h"

void EventHandler::notifyIncreasingCoin(){
	for (PlayingState* follower : this->followers) {
		follower->addCoin();
	}
}

void EventHandler::notifyDecreasingLives(){
	for (PlayingState* follower : this->followers) {
		follower->decreaseLives();
	}
}

void EventHandler::notifyIncreasingScore(){
	for (PlayingState* follower : this->followers) {
		follower->addScore();
	}
}

void EventHandler::notifyRestart(){
	for (PlayingState* follower : this->followers) {
		follower->restart();
	}
}

void EventHandler::notifyVictory(){
	for (PlayingState* follower : this->followers) {
		follower->changeMap();
	}
}
