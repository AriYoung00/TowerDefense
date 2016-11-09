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
        /**
         * Constructor for the tower class. Requires both type and location, with no default values
         * @param type The type of tower to create.
         * @param location The TilePoint location (tile grid, not pixels) for the tower to be created on
         */
        Tower(TowerType type, TilePoint location);
        /**
         * Destructor for the Tower class. Empty as of yet.
         */
        ~Tower();

        /**
         * Tower update method. Called before Tower::render() in each update cycle.
         */
        void update();
        /**
         * Tower render method. Is called after Tower::update() in each update cycle.
         */
        void render();
        /**
         * Causes a tower to take damage. \param Damage subtracted from \var _health. It is important to note that all of the
         * logic is handled in \ref TowerMan, so it \a is possible for \var _health to have a negative value. Currently
         * unused.
         * @param dmg The amound of damage for the Tower to take
         */
        void takeDamage(int dmg);
        /**
         * Adds health to a tower. Param \p health is added to \var _health. If (\var _health + \param health) is greater
         * than the max health for the defined \ref TowerType, then \var _health will be set to the max health for the
         * defined \ref TowerType.
         * @param health The amound of health to be added to the Tower.
         */
        void addHealth(int health);

        /**
         * Getter function for \var _health
         * @return Current Tower health
         */
        int getHealth();
        /**
         * Getter function for \var _type
         * @return The \ref TowerType of the Tower object
         */
        TowerType getType();
        /**
         * Getter function for the \var _location field
         * @return The TilePoint location of the tower. Is a tile coordinate, not pixel.
         */
        TilePoint getPos();

    private:
        /**
         * Tower health
         */
        int _health;
        /**
         * TowerType for current tower
         */
        TowerType _type;
        /**
         * TilePoint location for current tower
         */
        TilePoint _location;
    };
}

#endif //TOWERDEFENSE_TOWER_H
