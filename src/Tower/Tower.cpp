//
// Created by ariel on 11/6/16.
//

#include "Tower/Tower.h"

using Location::TilePoint;

namespace Towers {
    Tower::Tower(TowerType type, TilePoint location) : _location(location) {
        _type = type;

        if (_type == TowerType::SHORT_RANGE)
            _health = 650;
        else if (_type == TowerType::LONG_RANGE)
            _health = 350;
        else
            _health = 400;
    }

    void Tower::update() {
        //TODO: Actually write this. Relies on MonsterMan, TileUtil.
    }

    void Tower::takeDamage(int dmg) {
        _health -= dmg;
    }

    void Tower::addHealth(int health) {
        _health += health;

        if (_health > 650)
            _health -= _health - 650;
    }

    int Tower::getHealth() {
        return _health;
    }

    TowerType Tower::getType() {
        return _type;
    }

    TilePoint Tower::getPos() {
        return _location;
    }
}