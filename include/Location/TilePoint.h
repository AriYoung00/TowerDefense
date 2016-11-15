//
// Created by ariel on 11/7/16.
//

#ifndef TOWERDEFENSE_TILEPOINT_H
#define TOWERDEFENSE_TILEPOINT_H

#include <SFML/Graphics.hpp>

namespace Location {
    class TilePoint {
    public:
        /**
         * Constructor for TilePoint class
         * @param x The x-coordinate for the TilePoint
         * @param y The y-coordinate for the TilePoint
         * @param isTileCoord Whether /p x and /p y refer to a tile coordinate or pixel coordinate. Tile coordinate by
         *  default. If pixel coordinate, is translated into tile coordinate.
         */
        TilePoint(float x, float y, bool isTileCoord = true);

        void fromVector(sf::Vector2f vector);

        /**
         * Getter for the x-coordinate held by the TilePoint object.
         * @return The x-coordinate
         */
        float getX();

        /**
         * Getter for the y-coordinate held by the TilePoint object.
         * @return The y-coordinate
         */
        float getY();

        /**
         * Get the pixel x-coordinate of the center of the Tile that this TilePoint refers to
         * @return The pixel x-coordinate of the center of the Tile
         */
        float getRealX();

        /**
         * Get the pixel y-coordinate of the center of the Tile that thsi TilePoint refers to
         * @return The pixel y-coordinate of the center of the Tile
         */
        float getRealY();

        /**
         * Returns an array holding both the x- and y-coordinate, in the format {x, y}
         * @return An array {x, y} of the coordinates held.
         */
        float *getPos(); ///Returns {posX, posY}

        /**
         * Get the sf::Vector position of the center of this tile
         * @return An sf::Vector referring to the center of this tile
         */
        sf::Vector2f getVector();

        /**
         * Overloaded comparison operator for TilePoint.
         * @param rhs The TilePoint on the righthand-side of the comparison
         * @return Whether or not _posX and _posY in both TilePoint objects are equal
         */
        bool operator==(TilePoint const &rhs);

    private:
        float _posX;
        float _posY;
    };
}

#endif //TOWERDEFENSE_TILEPOINT_H
