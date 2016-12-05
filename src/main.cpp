//
// Created by ariel on 10/30/16.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Tower/Tower.h"
#include "Tower/TowerMan.h"
#include "Location/TileUtil.h"


using std::cout;
using std::endl;

using Towers::Tower;
using Towers::TowerType;
using Towers::TowerMan;

using Monsters::MonsterMan;

using Location::TileUtil;


int main () {
    // Breaks on 4:3, large screen sizes, but is an acceptable scaling solution for now
    double scale = sf::VideoMode::getDesktopMode().height / 1080;
    sf::RenderWindow window(sf::VideoMode(1000, 1000, 32), "Tower Defense", sf::Style::Close);

    TileUtil::init(1000, 1000);
    TileUtil::loadMap("Resources/Maps/TestMap.json");

    MonsterMan monstMan(window);
    TowerMan towerMan(window, monstMan);
    Monster m1(0.3);
    vector<Monster *> thing;
    thing.push_back(&m1);

    window.setFramerateLimit(240);
    sf::SoundBuffer sound;
    sound.loadFromFile("Resources/Sounds/TowerFireSound-1.wav");
    sf::Sound sound1;
    sound1.setBuffer(sound);
    //sound1.play();

    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonReleased) {
                towerMan.createTower(TowerType::SHORT_RANGE, sf::Mouse::getPosition(window).x,
                                     sf::Mouse::getPosition(window).y);
                cout << "mouse clicked" << endl;
            }
        }

        window.clear(sf::Color::Black);

        TileUtil::render(window);

        towerMan.update();
        towerMan.render();

        monstMan.update();
        monstMan.render();


        window.display();
    }


    return 0;
}
