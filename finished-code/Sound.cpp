#include "Sound.h"

SoundManager* SoundManager::instance = nullptr;


void SoundManager::load(){
	int size = this->soundFile.size();
	sound = std::vector<sf::Sound>(size);
	
	for (int i = 0; i < size; i++) {
		sf::SoundBuffer new_sound_buffer;
		
		if (!new_sound_buffer.loadFromFile(soundFile[i])){
			std::cout << "Can not load file " + soundFile[i];
			exit(1);
		}

		sound[i].setBuffer(new_sound_buffer);
	}
}

SoundManager::SoundManager(){}

SoundManager::~SoundManager(){
	delete instance;
}

void SoundManager::playSound(SoundID id){
	this->sound[(int)id].play();
}

void SoundManager::stopSound(SoundID id){
	this->sound[(int)id].stop();
}

SoundManager* SoundManager::getInstance()
{
	if (!instance) {
		instance = new SoundManager;
		instance->load();
	}
	return instance;
}
