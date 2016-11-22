#include "Monster/Monster.h"

#include <iostream>

using std::cout;
using std::endl;



namespace Monsters
{
    sf::Texture Monster::_spriteSheet = sf::Texture();

    Monster::Monster(/*TilePoint initialLoc, */float speed) : /*_location(initialLoc)*/ _frameClock(), _sprite(sf::seconds(0.1)) {
        _speed = speed;
        _health = 200;

        _walkForwardsAnimation.setSpriteSheet(_spriteSheet);
        _walkForwardsAnimation.addFrame(sf::IntRect(19, 88, 51, 51));
        _walkForwardsAnimation.addFrame(sf::IntRect(84, 91, 51, 51));
        _walkForwardsAnimation.addFrame(sf::IntRect(148, 87, 51, 51));
        _walkForwardsAnimation.addFrame(sf::IntRect(212, 81, 51, 51));
        _walkForwardsAnimation.addFrame(sf::IntRect(276, 88, 51, 51));

        _deathAnimation.setSpriteSheet(_spriteSheet);
        _deathAnimation.addFrame(sf::IntRect(18, 217, 51, 51));
        _deathAnimation.addFrame(sf::IntRect(84, 217, 51, 51));
        _deathAnimation.addFrame(sf::IntRect(148, 217, 51, 51));
        _deathAnimation.addFrame(sf::IntRect(212, 217, 51, 51));
        _deathAnimation.addFrame(sf::IntRect(276, 217, 51, 51));
        _deathAnimation.addFrame(sf::IntRect(330, 217, 51, 51));
        _deathAnimation.addFrame(sf::IntRect(384, 217, 51, 51));

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

    void Monster::kill()
    {
        cout << "KILL" << endl;
        _sprite.stop();
        _sprite.setAnimation(_deathAnimation);
        _sprite.setLooped(false);
        _sprite.play(_deathAnimation);
        _isDead = true;
    }

    bool Monster::isDead()
    {
        return _isDead;
    }

    int Monster::getHealth()
    {
        cout << "Monster health: " << _health << endl;
        return _health;
    }

    AnimatedSprite &Monster::getSprite() {
        return _sprite;
    }

    /*TilePoint Monster::getLocation() {
        return _location;
    }*/
}
