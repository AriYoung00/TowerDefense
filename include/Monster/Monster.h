#ifndef TOWERDEFENSE_MONSTER_H
#define TOWERDEFENSE_MONSTER_H

#include "Location/TilePoint.h"
#include "lib/Animation.hpp"
#include "lib/AnimatedSprite.hpp"


using Location::TilePoint;

namespace Monsters {
	enum MonsterType {WHITE_MONSTER, BLUE_MONSTER, RED_MONSTER};
	
    class Monster {
    public:
        Monster(MonsterType type);

        void update();
        void takeDamage(int damage);
        void kill();
        TilePoint getLocation();
        int getHealth();
		bool isDead();
		AnimatedSprite &getSprite();
        sf::Texture _spriteSheet;

    private:
        float _speed;
        unsigned int _health;
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
