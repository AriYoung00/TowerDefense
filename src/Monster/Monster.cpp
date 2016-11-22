#include "Monster/Monster.h"

#include <iostream>

using std::cout;
using std::endl;



namespace Monsters
{
    sf::Texture Monster::_spriteSheet = sf::Texture();

    Monster::Monster(/*TilePoint initialLoc, */float speed) : /*_location(initialLoc)*/ _frameClock() {
        _speed = speed;

        _walkForwardsAnimation.setSpriteSheet(_spriteSheet);
        _walkForwardsAnimation.addFrame(sf::IntRect(19, 88, 51, 51));
        _walkForwardsAnimation.addFrame(sf::IntRect(84, 91, 51, 51));
        _walkForwardsAnimation.addFrame(sf::IntRect(148, 87, 51, 51));
        _walkForwardsAnimation.addFrame(sf::IntRect(212, 81, 51, 51));
        _walkForwardsAnimation.addFrame(sf::IntRect(276, 88, 51, 51));

        _sprite.setAnimation(_walkForwardsAnimation);
        _sprite.setPosition(0, 240);
    }

    void Monster::update() {
        //I'll be honest here, I have no idea what this does
        sf::Time frameTime = _frameClock.restart();
        //Only one axis of movement for now
        _sprite.move(_speed, 0);
        //_location.fromVector(_sprite.getPosition());
        _sprite.update(frameTime);
    }

    void Monster::takeDamage(int damage) {
        _health -= damage;
    }

    AnimatedSprite &Monster::getSprite() {
        return _sprite;
    }

    /*TilePoint Monster::getLocation() {
        return _location;
    }*/
}