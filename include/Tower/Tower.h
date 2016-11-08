//
// Created by ariel on 11/6/16.
//

#ifndef TOWERDEFENSE_TOWER_H
#define TOWERDEFENSE_TOWER_H

#include "Location/TilePoint.h"

using Location::TilePoint;

namespace Towers {
    enum class TowerType {
        SHORT_RANGE, LONG_RANGE, HEAVY_DUTY //TODO: Make this not bad
    };

    class Tower {
    public:
        Tower(TowerType type, TilePoint location);
        ~Tower();

        void update(); ///Tower update method
        void takeDamage(int dmg); /// All logic is handled in TowerMan, so towers /can/ have negative health
        void addHealth(int health);

        int getHealth();
        TowerType getType();
        TilePoint getPos();

    private:
        int _health;
        TowerType _type;
        TilePoint _location;
    };
}

#endif //TOWERDEFENSE_TOWER_H
