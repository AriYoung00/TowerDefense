//
// Created by ariel on 10/30/16.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Tower/Tower.h"
#include "Tower/TowerMan.h"


using std::cout;
using std::endl;

using Towers::Tower;
using Towers::TowerType;
using Towers::TowerMan;

using Monsters::MonsterMan;


int main () {
    sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Tower Defense", sf::Style::Close);

    MonsterMan monstMan(window);
    TowerMan towerMan(window, monstMan);

    window.setFramerateLimit(240);
    sf::SoundBuffer fireSound;
    fireSound.loadFromFile("Resources/Sounds/TowerFireSound-1.wav");
    sf::Sound sound;
    sound.setBuffer(fireSound);
    //sound1.play();

    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                cout << "received close event" << endl;
                window.close();
            } else if (event.type == sf::Event::MouseButtonReleased) {
                towerMan.createTower(TowerType::SHORT_RANGE, sf::Mouse::getPosition(window).x,
                                     sf::Mouse::getPosition(window).y);
            }
		}

		window.clear(sf::Color::Black);

		towerMan.update();
		towerMan.render();

		monstMan.update();
		monstMan.render();

		window.display();
	}

    return 0;
}
