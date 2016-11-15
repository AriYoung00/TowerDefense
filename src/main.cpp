//
// Created by ariel on 10/30/16.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Tower/Tower.h"
#include <Tower/TowerMan.h>

using std::cout;
using std::endl;

using Towers::Tower;
using Towers::TowerType;
using Towers::TowerMan;

int main () {
    sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Hello SFML", sf::Style::Close);

    TowerMan man(window);

    window.setVerticalSyncEnabled(true);

    man.createTower(TowerType::SHORT_RANGE, Location::TilePoint(2, 2));
    sf::SoundBuffer sound;
    sound.loadFromFile("Resources/Sounds/TowerFireSound-1.wav");
    sf::Sound sound1;
    sound1.setBuffer(sound);
    sound1.play();

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            window.clear(sf::Color::White);

            man.update();
            man.render();

            window.display();
        }
    }


    return 0;
}