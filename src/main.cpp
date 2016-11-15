//
// Created by ariel on 10/30/16.
//
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Tower/Tower.h"

using std::cout;
using std::endl;

using Towers::Tower;
using Towers::TowerType;

int main () {
    sf::RenderWindow window(sf::VideoMode(640,480,32),"Hello SFML");

    Tower t(TowerType::HEAVY_DUTY, Location::TilePoint(7, 7));

    window.setVerticalSyncEnabled(true);

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }

            window.clear(sf::Color::White);
            t.update();
            window.draw(t.getSprite());
            window.display();
        }
    }


    return 0;
}