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


void handleClick(int posX, int posY, TowerMan &towerMan) {
    sf::Vector2f clickTile = TileUtil::tileFromCoordinate(posX, posY);
    if (!TileUtil::tileIsOccupied(clickTile)) {
        // I know that this is a pretty awful hack
        // I'm tired.
        clickTile.x = (int) (clickTile.x + 1); //+ 0.5);
        clickTile.y = (int) (clickTile.y + 1); //+ 0.5);

        cout << "tile coords " << clickTile.x << " " << clickTile.y << endl;
        towerMan.createTower(TowerType::SHORT_RANGE, clickTile);
    }
}

int main () {
    // Breaks on 4:3, large screen sizes, but is an acceptable scaling solution for now
    double scale = sf::VideoMode::getDesktopMode().height / 1080;
    sf::RenderWindow window(sf::VideoMode(1000, 1000, 32), "Tower Defense", sf::Style::Close);

    TileUtil::init(1000, 1000);
    TileUtil::loadMap("Resources/Maps/TestMap.json");

	StateManager *stateManager = new StateManager;
    UIManager uiManager(window, *stateManager);
    MonsterMan monstMan(window, uiManager, *stateManager);
    TowerMan towerMan(window, monstMan);
    monstMan.createMonster();

    window.setFramerateLimit(240);
    sf::SoundBuffer fireSound;
    fireSound.loadFromFile("Resources/Sounds/TowerFireSound-1.wav");
    sf::Sound sound;
    sound.setBuffer(fireSound);
    //sound1.play();

    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    handleClick(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, towerMan);
                    break;
                default:
                    break;
            }
		}


        TileUtil::render(window);

        towerMan.update();
        towerMan.render();

		monstMan.update();
		monstMan.render();

		uiManager.update();
		uiManager.render();

		window.display();
	}

    delete stateManager;

    return 0;
}
