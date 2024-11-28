#pragma once
#include "PlayingState.h"

class EventHandler{
private:
	std::vector<PlayingState*> followers;
	static EventHandler* instance;
public:
	static EventHandler* getInstance();
	void notifyIncreasingCoin();
	void notifyDecreasingLives();
	void notifyIncreasingScore();
	void notifyRestart();
	void notifyVictory();
};

