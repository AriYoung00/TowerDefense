//
// Created by ariel on 11/6/16.
//

#include "Tower/Tower.h"
#include <iostream>

using Location::TilePoint;

using std::cout;
using std::endl;


namespace Towers {
    Tower::Tower(TowerType type, TilePoint location) : _location(location) {
        _type = type;

        // Loading resources
        if (!_normalTexture.loadFromFile("Resources/Textures/Tower-lvl1.png"))
            //Will print name dynamically with other textures
            cout << "Tower normal texture " << "Tower-lvl1.png" << " not loaded" << endl;
        if (!_firingTexture.loadFromFile("Resources/Textures/Tower-lvl1-fire.png"))
            cout << "Tower firing texture " << "Resources/Textures/Tower-lvl1-fire.png" << " not loaded";
        if (!_fireSoundBuffer.loadFromFile("Resources/Sounds/TowerFireSound-1.wav"))
            cout << "Tower fire sound " << "TowerFireSound-1.wav" << " not loaded" << endl;
        _fireSound.setBuffer(_fireSoundBuffer);

        //So they can fire as soon as they're created.
        _lastFireTime = sf::seconds(0);

        _sprite.setTexture(_normalTexture);
        _sprite.setPosition(_location.getVector());

        _thing = true;
        _thing2 = 0.1f;

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
        //TODO: Actually write this. Relies on MonsterMan, TileUtil.
        if (true) {
            _sprite.setRotation(_thing2);
            //cout << "Setting rotation to " << _thing2 << endl;
            if (_thing2 >= 360)
                _thing2 = 0;
            else
                _thing2 += 1;
        }

        _thing = !_thing;
    }

    void Tower::startFire(sf::Time fireTime) {
        _lastFireTime = fireTime;
        _isFiring = true;
        _sprite.setTexture(_firingTexture);
        _fireSound.play();
    }

    void Tower::stopFire(sf::Time fireTime) {
        _lastFireTime = fireTime;
        _isFiring = false;
        _sprite.setTexture(_normalTexture);
    }

    void Tower::render() {
        //TODO: Actually write this. Relies on TileUtil.
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

    TilePoint Tower::getPos() const {
        return _location;
    }

    sf::Sprite &Tower::getSprite() {
        return _sprite;
    }

    sf::Time &Tower::getLastFireTime() {
        return _lastFireTime;
    }
}