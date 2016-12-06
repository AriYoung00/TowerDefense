#include "Monster/MonsterMan.h"
#include "Location/TileUtil.h"

using Location::TilePoint;
using std::cout;
using std::endl;

using Location::TileUtil;

namespace Monsters {
    MonsterMan::MonsterMan(sf::RenderWindow &window, UIManager &uiManager, StateManager &stateManager) :
            _window(window), _uiManager(uiManager), _stateManager(stateManager), _monsters() {
        _time_to_next_spawn = 3.0;
        _difficulty_curve = 1;
        //srand(4); // Chosen by fair dice roll, guaranteed to be random
    }

    void MonsterMan::update() {
        if (_spawnClock.getElapsedTime().asSeconds() >= _time_to_next_spawn) {
            _time_to_next_spawn -= 0.01;
            _spawnClock.restart();
            createMonster();
        }

        for (auto &m : _monsters) {
            m->update();
            if (m->getHealth() <= 0 && !m->isDead())
            {
                m->kill();
                _stateManager.addScore(1);
                _stateManager.addCoins(25);
            }
            if (TileUtil::tileFromCoordinate(m->getSprite().getPosition()).x > TileUtil::getBaseLocation().x - 0.8 &&
                !m->isDead()) {
                m->explode();

                _stateManager.removeLife();
                cout << "exploding" << endl;
            }
            if(m->isDead() && !m->getSprite().isPlaying())
            {
                cout << "erasing monster" << endl;
                _monsters.erase(std::remove(_monsters.begin(), _monsters.end(), m), _monsters.end());
            }
        }
    }

    void MonsterMan::render() {
        for (auto &m : _monsters) {
            _window.draw(m->getSprite());
        }
    }

    Monster *MonsterMan::getMonsterInRange(const sf::Vector2f &point, double range) {
        double distance = 0;
        for (auto &m : _monsters) {
            // Sorry about this. It's late, I'm lazy.
            distance = sqrt(pow(point.x - m->getSprite().getPosition().x, 2) +
                            pow(point.y - m->getSprite().getPosition().y, 2));
            if (distance <= range && !m->isDead())
                return m;
        }

        return nullptr;
    }

    void MonsterMan::createMonster() {
        int random = rand() % _difficulty_curve;
        if (random < 7) {
            _monsters.push_back(new Monster(Monsters::WHITE_MONSTER));
        } else if (random < 12) {
            _monsters.push_back(new Monster(Monsters::BLUE_MONSTER));
        } else {
            _monsters.push_back(new Monster(Monsters::RED_MONSTER));
        }

        if (_difficulty_curve < 15) {
            _difficulty_curve++;
        }
    }
}
