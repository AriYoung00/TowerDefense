//
// Created by ariel on 11/8/16.
//

#ifndef TOWERDEFENSE_MONSTERMAN_H
#define TOWERDEFENSE_MONSTERMAN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Monster.h"

using std::vector;

namespace Monsters {
    class MonsterMan {
    public:
        MonsterMan(sf::RenderWindow &window);

        Monster &getMonstersInRange(const sf::Vector2f &point, double range, Monster &defaultValue);

        void update();

        void render();

        void createMonster();

    private:
        vector<Monster *> _monsters;

        sf::Clock _spawnClock;
        sf::RenderWindow &_window;
    };
}

#endif //TOWERDEFENSE_MONSTERMAN_H
