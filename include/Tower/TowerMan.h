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
        TowerMan();

        void update();
        void onButtonClick(ButtonClickEvent event);

        Tower getTowerAt(TilePoint location);

    private:
        vector<Tower> _towers;

        void _createTower(TilePoint location);
        void _destroyTower(Tower * tower);

    };
}


#endif //TOWERDEFENSE_TOWERMAN_H