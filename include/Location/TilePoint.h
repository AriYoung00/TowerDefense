//
// Created by ariel on 11/7/16.
//

#ifndef TOWERDEFENSE_TILEPOINT_H
#define TOWERDEFENSE_TILEPOINT_H

namespace Location {
    class TilePoint {
    public:
        TilePoint(int x, int y);

        void getX();
        void getY();
        void getPos(); ///Returns {posX, posY}

    private:
        int _posX;
        int _posY;

    };
}

#endif //TOWERDEFENSE_TILEPOINT_H
