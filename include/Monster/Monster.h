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
        int getHealth();
		bool isDead();
		AnimatedSprite &getSprite();
        sf::Texture _spriteSheet;

    private:
        void _getNextPos();

        void _explode();

        sf::Vector2f _speed;
        unsigned int _health;
        int _movementIndex;
        float _speedBase;
        bool _isDead = false;


        //only animation for now
        sf::Clock _frameClock;
        sf::Vector2f _targetPos;
        sf::Texture _explodeSheet;
        Animation _walkForwardsAnimation;
        Animation _deathAnimation;
        Animation _explodeAnimation;
        AnimatedSprite _sprite;

    };
}
#endif //TOWERDEFENSE_MONSTER_H
