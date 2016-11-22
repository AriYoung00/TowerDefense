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

        void kill();

        AnimatedSprite &getSprite();

        TilePoint getLocation();

        int getHealth();

        bool isDead();

        static sf::Texture _spriteSheet;

    private:
        float _speed;
        int _health;
        bool _isDead = false;
        //TilePoint _location;


        //only animation for now
        sf::Clock _frameClock;
        Animation _walkForwardsAnimation;
        Animation _deathAnimation;
        AnimatedSprite _sprite;

    };
}
#endif //TOWERDEFENSE_MONSTER_H
