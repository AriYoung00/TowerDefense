//
// Created by ariel on 11/6/16.
//

#ifndef TOWERDEFENSE_TOWERMAN_H
#define TOWERDEFENSE_TOWERMAN_H

#include <vector>
#include "Tower.h"
#include "Events/ButtonClickEvent.h"
#include "Location/TilePoint.h"

using std::vector;
using Events::ButtonClickEvent;
using Location::TilePoint;

namespace Towers {
    class TowerMan {
    public:
        /**
         * Constructor for the TowerMan class. Initializes _towers.
         */
        TowerMan(sf::RenderWindow &window);

        /**
         * Update method for TowerMan class. Performs Tower-based logic, calls Tower::update() in all of the
         * Tower instances in _towers.
         */
        void update();

        /**
         * Render method for TowerMan class. Performs some pre-render actions, calls Tower::render() on the \ref
         * Tower objects in _towers.
         */
        void render();

        /**
         * ButtonClick event handler for the TowerMan class. Is called from EventMan when a button related to creating
         * or upgrading a tower is clicked. Removes/updates gui elemets in GuiUtil.
         * @param event The ButtonClickEvent object for the ButtonClick
         */
        void onButtonClick(ButtonClickEvent event);

        ///Temporary method
        void createTower(TowerType type, TilePoint location);

        /**
         * Get the tower at a particular tile-coordinate location.
         * @param location The TilePoint location for the tower to be returned.
         * @return The Tower on the TilePoint space specified be location. If no tower occupies the
         * specified space, returns NULL
         */
        Tower &getTowerAt(TilePoint location);

    private:
        /**
         * vector<Tower> of all the Tower objects on the board.
         */
        vector<Tower> _towers;

        sf::RenderWindow &_window;
        sf::Clock _fireClock;
        sf::Time _fireInterval;
        sf::Time _fireAnimationInterval;

        //Takes a reference since we're using an enhanced for loop
        bool _hasMonsterInRange(Tower &tower);
    };
}


#endif //TOWERDEFENSE_TOWERMAN_H