#ifndef TOWERDEFENSE_MONSTER_H
#define TOWERDEFENSE_MONSTER_H

#include "Location/TilePoint.h"
#include "SFMLLib/Animation.hpp"
#include "SFMLLib/AnimatedSprite.hpp"

using Location::TilePoint;

namespace Monsters {
    class Monster {
    public:
        Monster(/*TilePoint initialLoc, */float speed);

        void update();

        void takeDamage(int damage);

        AnimatedSprite &getSprite();

        TilePoint getLocation();

        static sf::Texture _spriteSheet;

    private:
        float _speed;
        int _health;

        //TilePoint _location;


        //only animation for now
        sf::Clock _frameClock;
        Animation _walkForwardsAnimation;
        AnimatedSprite _sprite;

    };
}
#endif //TOWERDEFENSE_MONSTER_H