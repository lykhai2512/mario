#pragma once
#include<SFML/Audio.hpp>
#include<iostream>

enum class SoundID {
    
};

class SoundManager {
private:
    const std::vector<std::string>soundFile = {
        "../sounds/1up_collect.wav",
        "../sounds/back_to_small.wav",
        "../sounds/background_castle.wav",
        "../sounds/background_open.wav",
        "../sounds/background_star.wav",
        "../sounds/background_summer.wav",
        "../sounds/background_underground.wav",
        "../sounds/background_winter.wav",
        "../sounds/block_destroyed.wav",
        "../sounds/block_hitted.wav",
        "../sounds/bonus_appeared.wav",
        "../sounds/bonus_collected.wav",
        "../sounds/boss_destroyed.wav",
        "../sounds/coin_sound.wav",
        "../sounds/enemy_destroyed.wav",
        "../sounds/fire_rocket.wav",
        "../sounds/fireball_popped.wav",
        "../sounds/fireworks.wav",
        "../sounds/flag_down.wav",
        "../sounds/game_over.wav",
        "../sounds/getting_points.wav",
        "../sounds/jump_small.wav",
        "../sounds/jump_tall.wav",
        "../sounds/level_finished.wav",
        "../sounds/mario_dead.wav",
        "../sounds/menu_return.wav",
        "../sounds/time_passed.wav",
        "../sounds/world_finished.wav",
    };

    std::vector<sf::Sound> sound;
  

    static SoundManager* instance;    
    void load();
public:
    SoundManager();
    ~SoundManager();

    static SoundManager* getInstance();
    void playSound(SoundID id);
    void stopSound(SoundID id);
};