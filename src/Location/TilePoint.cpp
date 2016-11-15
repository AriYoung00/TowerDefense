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

    int TilePoint::getRealX() {
        //TODO: Replace placeholder function
        return 20 * _posX;
    }

    int TilePoint::getRealY() {
        //TODO: Replace placeholder function
        return 20 * _posY;
    }

    int *TilePoint::getPos() {
        int temp[2] = {_posX, _posY};
        return temp;
    }

    sf::Vector2f TilePoint::getVector() {
        return sf::Vector2f((float) (20 * _posX), (float) (20 * _posY));
    }

    bool TilePoint::operator==(TilePoint const &rhs) {
        return ((_posX == rhs._posX) && (_posY == rhs._posY));
    }
}