//
// Created by ariel on 11/6/16.
//
#include "Tower/TowerMan.h"
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

namespace Towers {
    TowerMan::TowerMan(sf::RenderWindow &window, MonsterMan &monsterMan)
            : _towers(), _window(window), _initialTarget(0),
              _monsterMan(monsterMan) {
        _fireInterval = sf::seconds(0.7f);
        _fireAnimationInterval = sf::seconds(0.3f);
    }


    void TowerMan::update() {
        //TODO: Loop through button events, perform actions on towers based on button clicks
        sf::Time currentElapsed = _fireClock.getElapsedTime();

        for (auto &t : _towers) {
            if (t.getHealth() <= 0 && !t.shouldDestroy())
                t.destroy();

            if ((currentElapsed - t.getLastFireTime()) >= _fireInterval && _hasMonsterInRange(t))
                t.startFire(currentElapsed);
            else if ((currentElapsed - t.getLastFireTime()) >= _fireAnimationInterval && t.isFiring())
                t.stopFire(currentElapsed);

            //t.setTarget(_monsterMan.getMonstersInRange(t.getSprite().getPosition(), 10000, _initialTarget));

            t.update();
        }
    }

    void TowerMan::render() {
        //TODO: Perform pre-tower-render events (buttons, etc)
        for (auto &t : _towers) {
            _window.draw(t.getSprite());
        }

    }

    Tower& TowerMan::getTowerAt(TilePoint location) {
        for (auto &t : _towers) {
            //if (location == t.getPos())
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

    void TowerMan::createTower(TowerType type, float x, float y) {
        Tower t(type, x, y, _initialTarget);
        _towers.push_back(t);
    }
}