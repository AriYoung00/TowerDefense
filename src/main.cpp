//
// Created by ariel on 10/30/16.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Tower/Tower.h"
#include "Tower/TowerMan.h"
#include "Location/TileUtil.h"
#include "UI/UIManager.h"


using std::cout;
using std::endl;

using Towers::Tower;
using Towers::TowerType;
using Towers::TowerMan;

using Monsters::MonsterMan;

using Location::TileUtil;


int main () {
    sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Tower Defense", sf::Style::Close);


    // Breaks on 4:3, large screen sizes, but is an acceptable scaling solution for now
    double scale = sf::VideoMode::getDesktopMode().height / 1080;
    sf::RenderWindow window(sf::VideoMode(1000, 1000, 32), "Tower Defense", sf::Style::Close);

    TileUtil::init(1000, 1000);
    TileUtil::loadMap("Resources/Maps/TestMap.json");

    UIManager uiManager(window);
    MonsterMan monstMan(window, uiManager);
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
                window.close();
            } else if (event.type == sf::Event::MouseButtonReleased) {
                towerMan.createTower(TowerType::SHORT_RANGE, sf::Mouse::getPosition(window).x,
                                     sf::Mouse::getPosition(window).y);
            }
		}

		window.clear(sf::Color::Black);

        TileUtil::render(window);

        towerMan.update();
        towerMan.render();

		monstMan.update();
		monstMan.render();

		uiManager.update();
		uiManager.render();

		window.display();
	}

    return 0;
}
