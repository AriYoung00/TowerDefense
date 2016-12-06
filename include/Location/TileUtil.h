#include <SFML/Graphics.hpp>
#include <lib/json.hpp>

using std::string;

using json = nlohmann::json;
namespace Location {
    class TileUtil {
    public:
        static void init(int screenWidth, int screenY);
        static void loadMap(string mapLocation);
        static void render(sf::RenderWindow & window);

        static sf::Vector2f tileFromCoordinate(float locX, float locY);

        static sf::Vector2f tileFromCoordinate(sf::Vector2f &coord);

        static sf::Vector2f coordinateFromTile(float x, float y);

        static sf::Vector2f coordinateFromTile(sf::Vector2f tile);

        static sf::Vector2f getTargetPos(int posIndex);

        static sf::Vector2f getSpawnLocation();

        static sf::Vector2f getBaseLocation();


    private:
        static int _pixelWidth;
        static int _pixelHeight;
        static int _tileWidth;
        static int _tileHeight;
        static int _tilePixelWidth;
        static int _tilePixelHeight;

        static sf::Vector2f _baseLocation;
        static sf::Vector2f _spawnLocation;
        static string _mapName;
        static sf::VertexArray _vertexArr;
        static sf::Texture _tileMap;
        static json _monsterDirections;
    };
}