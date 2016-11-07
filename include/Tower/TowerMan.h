//
// Created by ariel on 11/6/16.
//

#ifndef TOWERDEFENSE_TOWERMAN_H
#define TOWERDEFENSE_TOWERMAN_H

#include "Tower/Tower.h"
#include "Events/ButtonClickEvent.h"

using EventType::ButtonClickEvent;

namespace Tower {
    class TowerMan {
    public:
        TowerMan();

        ~TowerMan();

        void onUpdate();

        void onButtonClick(ButtonClickEvent);

        void addTower(Tower);
    };
}

#endif //TOWERDEFENSE_TOWERMAN_H
