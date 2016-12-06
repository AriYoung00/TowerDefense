//
// Created by ariel on 11/6/16.
//

#include "Tower/Tower.h"

#include <iostream>

using Location::TilePoint;

using std::cout;
using std::endl;


namespace Towers {
    sf::Texture Tower::_normalTexture = sf::Texture();
    sf::Texture Tower::_firingTexture = sf::Texture();
    sf::SoundBuffer Tower::_fireSoundBuffer = sf::SoundBuffer();

    Tower::Tower(TowerType type, float x, float y) {
        _type = type;

        _fireSound.setBuffer(_fireSoundBuffer);

        //So they can fire as soon as they're created.
        _lastFireTime = sf::seconds(0);

        _sprite.setTexture(_normalTexture);
        _sprite.setScale(1.3, 1.3);
        _sprite.setOrigin(15, 55);
        _sprite.setPosition(x, y);

        if (_type == TowerType::SHORT_RANGE) {
            _health = 650;
        } else if (_type == TowerType::LONG_RANGE) {
            _health = 350;
        } else {
            _health = 400;
        }
    }

    Tower::~Tower() {
        //TODO: Actually write this.
    }

    void Tower::update() {
        float rotation;
		if (_target) {
			sf::Vector2f curPos = _sprite.getPosition();
			sf::Vector2f position = _target->getSprite().getPosition();

			const float PI = 3.14159265;

			float dx = curPos.x - position.x;
			float dy = curPos.y - position.y;

            rotation = ((atan2(dy, dx)) * 180 / PI) - 90;
		}

        _sprite.setRotation(rotation);
    }

    void Tower::startFire(sf::Time fireTime) {
		if (_target) {
            //_sprite.setRotation(90);
			_lastFireTime = fireTime;
			_isFiring = true;
			_sprite.setTexture(_firingTexture);
			_target->takeDamage(10);
			/* _fireSound.play(); */
		}
    }

    void Tower::stopFire(sf::Time fireTime) {
        _target = nullptr;
        _sprite.setRotation(0);
        _lastFireTime = fireTime;
        _isFiring = false;
        _sprite.setTexture(_normalTexture);
    }

    void Tower::setTarget(Monster *monster) {
        _target = monster;
    }

    void Tower::destroy() {
        //TODO: Actually write this.
        _shouldDestroy = true;
    }

    void Tower::takeDamage(int dmg) {
        _health -= dmg;
    }

    bool Tower::shouldDestroy() const {
        return _shouldDestroy;
    }

    bool Tower::isFiring() {
        return _isFiring;
    }

    void Tower::addHealth(int health) {
        _health += health;

        if (_health > 650)
            _health -= _health - 650;
    }

    int Tower::getHealth() const {
        return _health;
    }

    TowerType Tower::getType() const {
        return _type;
    }

    /*TilePoint Tower::getPos() const {
        return _location;
    }*/

    sf::Sprite &Tower::getSprite() {
        return _sprite;
    }

    sf::Time &Tower::getLastFireTime() {
        return _lastFireTime;
    }

    bool Tower::needsTarget() {
        return _target == nullptr;
    }
}
