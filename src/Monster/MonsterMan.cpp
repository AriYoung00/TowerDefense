#include "Monster/MonsterMan.h"

#include <iostream>
#include <cmath>

using Location::TilePoint;
using std::cout;
using std::endl;

namespace Monsters {
    MonsterMan::MonsterMan(sf::RenderWindow &window) : _window(window), _monsters() {}

    void MonsterMan::update() {
        if (_spawnClock.getElapsedTime().asSeconds() >= 3) {
            _spawnClock.restart();
            createMonster();
        }

        for (auto &m : _monsters) {
            m->update();
						if (m->getSprite().getPosition().x > 640) {
							_monsters.erase(std::remove(_monsters.begin(), _monsters.end(), m), _monsters.end());
							cout << "Monster count: " << _monsters.size() << endl;
						}
        }
    }

    void MonsterMan::render() {
        for (auto &m : _monsters) {
            _window.draw(m->getSprite());
        }
    }

    Monster &MonsterMan::getMonstersInRange(const sf::Vector2f &point, double range, Monster &defaultValue) {
        double distance = 0;
        for (auto &m : _monsters) {
            // Sorry about this. It's late, I'm lazy.
            distance = sqrt(pow(point.x - m->getSprite().getPosition().x, 2) +
                            pow(point.y - m->getSprite().getPosition().y, 2));
            if (distance <= range)
                return *m;
        }

        return defaultValue;
    }

    void MonsterMan::createMonster() {
        // For now, location and speed are set to constant values in Monster, so we just need to fix this later
        _monsters.push_back(new Monster(0.3));
    }
}
