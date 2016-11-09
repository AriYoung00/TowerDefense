//
// Created by ariel on 11/7/16.
//
#include "Location/TilePoint.h"

namespace Location {
    TilePoint::TilePoint(int x, int y, bool isTileCoord) {
        //TODO: Use value of isTileCoord to determine whether or not x and y need to be converted to tile coord. Relies on TileUtil.

        _posX = x;
        _posY = y;
    }

    int TilePoint::getX() {
        return _posX;
    }

    int TilePoint::getY() {
        return _posY;
    }

    int *TilePoint::getPos() {
        int temp[2] = {_posX, _posY};
        return temp;
    }

    bool TilePoint::operator==(TilePoint const &rhs) {
        return ((_posX == rhs._posX) && (_posY == rhs._posY));
    }
}