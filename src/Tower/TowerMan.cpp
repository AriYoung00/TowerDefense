//
// Created by ariel on 11/6/16.
//
#include "Tower/TowerMan.h"

using std::vector;

namespace Towers {
    TowerMan::TowerMan() : _towers(*_towersPtr) {
        _towersPtr = new vector<Tower>();
    }

    TowerMan::~TowerMan() {
        delete _towersPtr;
        _towersPtr = nullptr;
    }

    void TowerMan::update() {
        //TODO: Loop through button events, perform actions on towers based on button clicks

        for (Tower & t : _towers) {
            if (t.getHealth() <= 0 && !t.shouldDestroy())
                t.destroy();

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
}