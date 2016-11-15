//
// Created by ariel on 11/6/16.
//
#include "Tower/TowerMan.h"

using std::vector;

namespace Towers {
    TowerMan::TowerMan() : _towers(*_towersPtr) {
        _towersPtr = new vector<Tower>();
        _fireInterval = sf::seconds(0.7f);
        _fireAnimationInterval = sf::seconds(0.3f);
    }

    TowerMan::~TowerMan() {
        delete _towersPtr;
        _towersPtr = nullptr;
    }

    void TowerMan::update() {
        //TODO: Loop through button events, perform actions on towers based on button clicks
        sf::Time currentElapsed = _fireClock.getElapsedTime();

        for (Tower & t : _towers) {
            if (t.getHealth() <= 0 && !t.shouldDestroy())
                t.destroy();

            if ((currentElapsed - t.getLastFireTime()) >= _fireInterval && _hasMonsterInRange(t))
                t.startFire(currentElapsed);
            else if ((currentElapsed - t.getLastFireTime()) >= _fireAnimationInterval)

            t.update();
        }
    }

    void TowerMan::render() {
        //TODO: Perform pre-tower-render events (buttons, etc)

        for (Tower & t : _towers)
            t.render();
    }

    Tower& TowerMan::getTowerAt(TilePoint location) {
        for (Tower &t : _towers) {
            if (location == t.getPos())
                return t;
        }
    }

    bool TowerMan::_hasMonsterInRange(Tower &tower) {
        //TODO: write _hasMonsterInRange
    }

    void TowerMan::onButtonClick(ButtonClickEvent event) {
        //TODO: Implement onButtonClick
    }

    void TowerMan::_createTower(TowerType type, TilePoint location) {
        Tower t(type, location);
        _towers.push_back(t);
    }
}