#include <fstream>

#include "Location/TileUtil.h"
#include "lib/json.hpp"

using std::cout;
using std::endl;

using json = nlohmann::json;
namespace Location {
    int TileUtil::_pixelWidth;
    int TileUtil::_pixelHeight;
    int TileUtil::_tileWidth;
    int TileUtil::_tileHeight;
    int TileUtil::_tilePixelWidth;
    int TileUtil::_tilePixelHeight;
    sf::VertexArray TileUtil::_vertexArr;
    string TileUtil::_mapName;
    sf::Texture TileUtil::_tileMap;

    void TileUtil::init(int screenWidth, int screenHeight) {
        _pixelWidth = screenWidth;
        _pixelHeight = screenHeight;

        _tileMap.loadFromFile("Resources/Textures/TileMap.png");
    }

    void TileUtil::loadMap(string mapLocation) {
        std::ifstream inFile("Resources/Maps/TestMap.json");
        json map;
        inFile >> map;
        // This json library uses vectors for arrays
        std::vector<std::vector<int>> tileList = map["tileList"];

        _mapName = map["name"];
        _tileWidth = map["tileWidth"];
        _tileHeight = map["tileHeight"];

        // Computing the pixel dimensions of each tile
        _pixelWidth -= _pixelWidth % _tileWidth;
        _pixelHeight -= _pixelHeight % _tileHeight;
        _tilePixelWidth = _pixelWidth / _tileWidth;
        _tilePixelHeight = _pixelHeight / _tileHeight;

        // Creating the vertex array
        // Loosely based on http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array.php#example-tile-map
        _vertexArr.setPrimitiveType(sf::Quads);
        _vertexArr.resize(_tileWidth * _tileHeight * 4);
        cout << "fuck you sfml " << _tileWidth << endl;

        for (unsigned int row = 0; row < _tileHeight; row++) {
            // 4 actual indexes per tile
            for (unsigned int column = 0; column < _tileWidth; column++) {
                int vertexArrInd = (row * _tileWidth * 4) + (4 * column);
                int baseX = column * _tilePixelHeight;
                int baseY = row * _tilePixelWidth;
                int textureCornerX;

                switch (tileList[row][column]) {
                    case 1:
                        textureCornerX = 0;
                        break;
                    case 2:
                        textureCornerX = 64;
                        break;
                    case 3:
                        textureCornerX = 128;
                        break;
                    case 4:
                        textureCornerX = 192;
                        break;
                    case 5:
                        textureCornerX = 256;
                        break;
                    default:
                        cout << "sumthin ain't right" << endl;
                        break;
                }

                _vertexArr[vertexArrInd].position = sf::Vector2f(baseX, baseY);
                _vertexArr[vertexArrInd].texCoords = sf::Vector2f(textureCornerX, 0);
                for (int corner = 1; corner < 4; corner++) {
                    int offsetX = (corner == 1) || (corner == 2) ? _tilePixelWidth : 0;
                    int offsetY = (corner == 2) || (corner == 3) ? _tilePixelHeight : 0;

                    _vertexArr[vertexArrInd + corner].position = sf::Vector2f(baseX + offsetX, baseY + offsetY);

                    int textureOffsetX = (corner == 1) || (corner == 2) ? 64 : 0;
                    int textureY = (corner == 2) || (corner == 3) ? 64 : 0;

                    cout << ", (" << textureCornerX + textureOffsetX << ", " << textureY << ")";
                    _vertexArr[vertexArrInd + corner].texCoords = sf::Vector2f(textureCornerX + textureOffsetX,
                                                                               textureY);
                    //_vertexArr[vertexArrInd + corner].color = sf::Color::Green;
                }

                cout << endl;
            }
        }

    }

    void TileUtil::render(sf::RenderWindow &window) {
        window.draw(_vertexArr, &_tileMap);
    }
}