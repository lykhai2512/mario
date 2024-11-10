#pragma once
#include<SFML/Audio.hpp>

class SoundManager {
private:
    sf::Sound backgroundSound;
    //...

    //load all sounds
public:
    void load();
    void playBackGroundsound(int mapNum);
    void playcoinSound();
    void enemyHitSound();
    //...
};