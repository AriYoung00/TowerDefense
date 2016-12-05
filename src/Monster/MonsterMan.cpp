#include "Monster/MonsterMan.h"

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using Location::TilePoint;
using std::cout;
using std::endl;

namespace Monsters {
    MonsterMan::MonsterMan(sf::RenderWindow &window, UIManager &uiManager) : _window(window), _uiManager(uiManager), _monsters() {
//		_uiManager = *uiManager;
		srand(time(0));
    }

    void MonsterMan::update() {
        if (_spawnClock.getElapsedTime().asSeconds() >= 3) {
            _spawnClock.restart();
            createMonster();
        }

        for (auto &m : _monsters) {
            m->update();
			if (m->getSprite().getPosition().x > 640) {
				_monsters.erase(std::remove(_monsters.begin(), _monsters.end(), m), _monsters.end());
				_uiManager.removeLife();
                cout << "Monster count: " << _monsters.size() << endl;
            }
            else if(m->getHealth() <= 0 && !m->isDead())
            {
                m->kill();
				_uiManager.addPoints(1);
            }
            if(m->isDead() && !m->getSprite().isPlaying())
            {
                _monsters.erase(std::remove(_monsters.begin(), _monsters.end(), m), _monsters.end());
            }
        }
    }

    void MonsterMan::render() {
        for (auto &m : _monsters) {
            _window.draw(m->getSprite());
        }
    }

    Monster *MonsterMan::getMonstersInRange(const sf::Vector2f &point, double range) {
        double distance = 0;
        for (auto &m : _monsters) {
            // Sorry about this. It's late, I'm lazy.
            distance = sqrt(pow(point.x - m->getSprite().getPosition().x, 2) +
                            pow(point.y - m->getSprite().getPosition().y, 2));
            if (distance <= range)
                return m;
        }

        return nullptr;
    }

    void MonsterMan::createMonster() {
		int random = rand() % 10;
		if (random < 5) {
			_monsters.push_back(new Monster(Monsters::WHITE_MONSTER));
		} else if (random < 8) {
			_monsters.push_back(new Monster(Monsters::BLUE_MONSTER));
		} else {
			_monsters.push_back(new Monster(Monsters::RED_MONSTER));
		}
    }
}
