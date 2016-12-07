#include <fstream>

#include "Location/TileUtil.h"

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
    sf::Vector2f TileUtil::_baseLocation;
    sf::Vector2f TileUtil::_spawnLocation;
    json TileUtil::_monsterDirections;
    sf::VertexArray TileUtil::_vertexArr;
    string TileUtil::_mapName;
    sf::Texture TileUtil::_tileMap;
    std::vector<std::vector<bool>> TileUtil::_tilesOccupied;

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
        std::vector<std::vector<int>> tileTypes = map["tileList"];


        _spawnLocation.x = map["monsterSpawnLocation"][0];
        _spawnLocation.y = map["monsterSpawnLocation"][1];
        _baseLocation.x = map["baseLocation"][0];
        _baseLocation.y = map["baseLocation"][1];

        _mapName = map["name"];
        _tileWidth = map["tileWidth"];
        _tileHeight = map["tileHeight"];
        _monsterDirections = map["monsterDirections"];

        // Computing the pixel dimensions of each tile
        _pixelWidth -= _pixelWidth % _tileWidth;
        _pixelHeight -= _pixelHeight % _tileHeight;
        _tilePixelWidth = _pixelWidth / _tileWidth;
        _tilePixelHeight = _pixelHeight / _tileHeight;

        // Creating the vertex array
        // Loosely based on http://www.sfml-dev.org/tutorials/2.0/graphics-vertex-array.php#example-tile-map
        _vertexArr.setPrimitiveType(sf::Quads);
        _vertexArr.resize(_tileWidth * _tileHeight * 4);

        for (unsigned int row = 0; row < _tileHeight; row++) {
            // 4 actual indexes per tile
            for (unsigned int column = 0; column < _tileWidth; column++) {
                int vertexArrInd = (row * _tileWidth * 4) + (4 * column);
                int baseX = column * _tilePixelHeight;
                int baseY = row * _tilePixelWidth;
                int textureCornerX;

                switch (tileTypes[row][column]) {
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

                    _vertexArr[vertexArrInd + corner].texCoords = sf::Vector2f(textureCornerX + textureOffsetX,
                                                                               textureY);
                    //_vertexArr[vertexArrInd + corner].color = sf::Color::Green;
                }
            }
        }

        _tilesOccupied = std::vector<std::vector<bool>>(_tileHeight);
        for (int i = 0; i < _tileHeight; i++) {
            _tilesOccupied[i] = std::vector<bool>(_tileHeight);
            for (int j = 0; j < _tileWidth; j++) {
                _tilesOccupied[i][j] = tileTypes[i][j] > 1;
            }
        }

        cout << "loading default tile occupation values" << endl;
    }

    void TileUtil::render(sf::RenderWindow &window) {
        window.draw(_vertexArr, &_tileMap);
    }

    sf::Vector2f TileUtil::tileFromCoordinate(float locX,
                                              float locY) { // Should probably be vector2i, but this lets me pass it without converting
        sf::Vector2f temp;
        temp.x = locX / _tilePixelWidth;
        temp.y = locY / _tilePixelHeight;

        return temp;
    }

    sf::Vector2f TileUtil::tileFromCoordinate(const sf::Vector2f &coord) {
        return tileFromCoordinate(coord.x, coord.y);
    }


    sf::Vector2f TileUtil::coordinateFromTile(float x, float y) {
        sf::Vector2f temp;
        // Because we need to get the center of the tile, not the top left edge, as is default
        temp.x = (((x - 1) * _tilePixelWidth) + (_tilePixelWidth / 2));
        temp.y = (((y - 1) * _tilePixelHeight) + (_tilePixelHeight / 2));

        return temp;
    }

    sf::Vector2f TileUtil::coordinateFromTile(const sf::Vector2f &tile) {
        return coordinateFromTile(tile.x, tile.y);
    }

    sf::Vector2f TileUtil::getTargetPos(int posIndex) {
        sf::Vector2f temp(_monsterDirections[posIndex][0], _monsterDirections[posIndex][1]);
        return coordinateFromTile(temp);
    }

    sf::Vector2f TileUtil::getSpawnLocation() {
        return coordinateFromTile(_spawnLocation);
    }

    sf::Vector2f TileUtil::getBaseLocation() {
        return _baseLocation;
    }

    double TileUtil::getTileDistance() {
        return sqrt(2) * _tilePixelWidth;
    }

    bool TileUtil::tileIsOccupied(sf::Vector2f tileCoord) {
        return _tilesOccupied[tileCoord.y - 1][tileCoord.x - 1];
    }

    void TileUtil::setOccupied(int x, int y) {
        _tilesOccupied[y - 1][x - 1] = true;
    }
}