//
// Created by ariel on 11/6/16.
//
#include "Tower/TowerMan.h"
#include <lib/json.hpp>
#include <Location/TileUtil.h>

using std::vector;
using std::cout;
using std::endl;

using Location::TileUtil;

namespace Towers {
    TowerMan::TowerMan(sf::RenderWindow &window, MonsterMan &monsterMan, StateManager &stateManager)
            : _towers(), _window(window),
              _monsterMan(&monsterMan),
              _stateMan(stateManager) {
        _fireInterval = sf::seconds(0.7f);
        _fireAnimationInterval = sf::seconds(0.05f);

        Tower::_normalTexture.loadFromFile("Resources/Textures/Tower-lvl1.png");
        Tower::_firingTexture.loadFromFile("Resources/Textures/Tower-lvl1-fire.png");
        Tower::_fireSoundBuffer.loadFromFile("Resources/Sounds/TowerFireSound-1.wav");
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

            if (t.needsTarget() && _monsterMan->getMonsterInRange(t.getSprite().getPosition(),
                                                                  1.5 * TileUtil::getTileDistance())) {
                t.setTarget(_monsterMan->getMonsterInRange(t.getSprite().getPosition(),
                                                           1.5 * TileUtil::getTileDistance()));
            }

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

    void TowerMan::createTower(TowerType type, sf::Vector2f pos) {
        if (_stateMan.getCoins() >= 100) {
            _stateMan.removeCoins(100);
            TileUtil::setOccupied(pos.x, pos.y); // Intentional type mismatch
            cout << "setting " << pos.x << " " << pos.y << " to occupied" << endl;
            Tower t(type, TileUtil::coordinateFromTile(pos).x, TileUtil::coordinateFromTile(pos).y);
            _towers.push_back(t);
        }
    }
}
