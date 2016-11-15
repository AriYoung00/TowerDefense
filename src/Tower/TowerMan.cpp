//
// Created by ariel on 11/6/16.
//
#include "Tower/TowerMan.h"
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

namespace Towers {
    TowerMan::TowerMan(sf::RenderWindow &window) : _towers(), _window(window) {
        _fireInterval = sf::seconds(0.7f);
        _fireAnimationInterval = sf::seconds(0.3f);
    }


    void TowerMan::update() {
        //TODO: Loop through button events, perform actions on towers based on button clicks
        sf::Time currentElapsed = _fireClock.getElapsedTime();

        for (Tower & t : _towers) {
            if (t.getHealth() <= 0 && !t.shouldDestroy())
                t.destroy();

            if ((currentElapsed - t.getLastFireTime()) >= _fireInterval && _hasMonsterInRange(t))
                t.startFire(currentElapsed);
            else if ((currentElapsed - t.getLastFireTime()) >= _fireAnimationInterval && t.isFiring())
                t.stopFire(currentElapsed);

            t.update();
        }
    }

    void TowerMan::render() {
        //TODO: Perform pre-tower-render events (buttons, etc)

        for (Tower & t : _towers)
            _window.draw(t.getSprite());
    }

    Tower& TowerMan::getTowerAt(TilePoint location) {
        for (Tower &t : _towers) {
            if (location == t.getPos())
                return t;
        }
    }

    bool TowerMan::_hasMonsterInRange(Tower &tower) {
        //TODO: write _hasMonsterInRange
        return true;
    }

    void TowerMan::onButtonClick(ButtonClickEvent event) {
        //TODO: Implement onButtonClick
    }

    void TowerMan::createTower(TowerType type, TilePoint location) {
        Tower t(type, location);
        _towers.push_back(t);
        for (auto &i : _towers)
            cout << " here's one" << endl;
    }
}