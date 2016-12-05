#include <SFML/Graphics.hpp>

using std::string;

namespace Location {
    class TileUtil {
    public:
        static void init(int screenWidth, int screenY);
        static void loadMap(string mapName);
        static void tileFromCoordinate(int locX, int locY);
        static void tileFromCoordinate(sf::Vector2f coord);

    private:
        static int _pixelWidth;
        static int _pixelHeight;
        static int _tileWidth;
        static int _tileHeight;
        static int _tilePixelWidth;
        static int _tilePixelHeight;

        static string _mapName;
        static sf::VertexArray _vertexArr;
    };
}