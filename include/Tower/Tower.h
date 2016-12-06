//
// Created by ariel on 11/6/16.
//

#ifndef TOWERDEFENSE_TOWER_H
#define TOWERDEFENSE_TOWER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Monster/Monster.h"
#include "Location/TilePoint.h"

using Location::TilePoint;
using Monsters::Monster;

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
        Tower(TowerType type, float x, float y);

        /**
         * Destructor for the Tower class. Empty as of yet.
         */
        ~Tower();

        /**
         * Tower update method. Called before Tower::render() in each update cycle.
         */
        void update();

        /**
         * Causes a tower to take damage. Damage subtracted from _health. It is important to note that all of the
         * logic is handled in TowerMan, so it \a is possible for _health to have a negative value. Currently
         * unused.
         * @param dmg The amound of damage for the Tower to take
         */
        void takeDamage(int dmg);

        /**
         * Mark a tower for destruction and begin playing the destroy animation. Seperate from the deletion operator in 
         * order to make sure the animation finishes playing before the object itself is destroyed. Sets \p _shouldDestroy
         * to true.
         */
        void destroy();

        /**
         * Adds health to a tower. Param \p health is added to _health. If the tower's current health added to
         *  the \p health is greater than the max health for the defined TowerType, then \p _health will be set to the
         *  max health for the defined TowerType.
         * @param health The amound of health to be added to the Tower.
         */
        void addHealth(int health);

        /**
         * Function called by TowerMan when each tower can fire. Sets _lastFireTime to FireTime, plays the fire sound,
         * and switches to the firing texture.
         * @param fireTime
         */
        void startFire(sf::Time fireTime);

        /**
         * Function called by TowerMan when the texture can be switched back to the not firing texture.
         */
        void stopFire(sf::Time fireTime);

        void setTarget(Monster *monster);

        /**
         * Getter function for \p _health
         * @return Current Tower health
         */
        int getHealth() const;


        /**
         * Whether or not a tower has been marked for destruction
         * @return Whether or not a tower has been marked for destruction.
         */
        bool shouldDestroy() const;

        /**
         * Whether or not the tower is currently in a "firing" state.
         * @return Whether or not the tower is firing
         */
        bool isFiring();

        bool needsTarget();

        /**
         * Getter function for \p _type
         * @return The TowerType of the Tower object
         */
        TowerType getType() const;

        /**
         * Getter function for the \p _location field
         * @return The TilePoint location of the tower. Is a tile coordinate, not pixel.
         */
        TilePoint getPos() const;

        sf::Sprite &getSprite();

        /**
         * Getter for _lastFireTime
         * @return The sf::Time of the last time the tower fired.
         */
        sf::Time &getLastFireTime();

        static sf::SoundBuffer _fireSoundBuffer;
        static sf::Texture _normalTexture;
        static sf::Texture _firingTexture;

    private:
        /**
         * Tower health
         */
        int _health;
        bool _shouldDestroy;
        bool _isFiring;


        sf::Sound _fireSound;

        sf::Sprite _sprite;

        sf::Time _lastFireTime;

        Monster *_target = nullptr;
        TowerType _type;
        //TilePoint _location;
    };
}

#endif //TOWERDEFENSE_TOWER_H
