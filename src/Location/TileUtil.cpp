#include <fstream>

#include "Location/TileUtil.h"
#include "lib/json.hpp"


using json = nlohmann::json;
namespace Location {
    void TileUtil::init(int screenWidth, int screenHeight) {
        _pixelWidth = screenWidth;
        _pixelHeight = screenHeight;
    }

    void TileUtil::loadMap(string mapName) {
        std::ifstream inFile("Resources/Maps/TestMap.json");
        json j;
        inFile >> j;

        _mapName = j["name"];
        _tileWidth = j["tileWidth"];
        _tileHeight = j["tileHeight"];

        // Computing the pixel dimensions of each tile
        _pixelWidth -= _pixelWidth % _tileWidth;
        _pixelHeight -= _pixelHeight % _tileHeight;
        _tilePixelWidth = _pixelWidth / _tileWidth;
        _tilePixelHeight = _pixelHeight / _tileHeight;

        // Creating the vertex array
        // Loosely based on http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array.php#example-tile-map
        _vertexArr.setPrimitiveType(sf::Quads);
        _vertexArr.resize(_tileWidth * _tileHeight * 4);

        for (unsigned int j = 1; j <= 10; j++) {
            for (unsigned int i = 1; i <= 10; i++) {
                // i is width, j is height
                int vertIndex = (i * j) - 1;
                int baseX = (i - 1) * _tilePixelWidth;
                int baseY = (j - 1) * _tilePixelHeight;

                // Top-right corner at baseX, baseY
                _vertexArr[vertIndex].position = sf::Vector2f(baseX, baseY);
                // Top-left corner at baseX + tilePixelWidth, baseY
                _vertexArr[vertIndex + 1].position = sf::Vector2f(baseX + _tilePixelWidth, baseY);
                // Bottom-left corner at baseX + tilePixelWidth, baseY + tilePixelHeight
                _vertexArr[vertIndex + 2].position = sf::Vector2f(baseX + _tilePixelWidth, baseY + _tilePixelHeight);
                // Bottom-right corner at baseX, baseY + tilePixelHeight
                _vertexArr[vertIndex + 3].position = sf::Vector2f(baseX, baseY + _tilePixelHeight);



            }
        }
    }
}