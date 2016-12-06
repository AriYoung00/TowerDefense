#include "Monster/Monster.h"

#include <iostream>
#include <Location/TileUtil.h>

using std::cout;
using std::endl;

using Location::TileUtil;



namespace Monsters
{
    sf::Texture _spriteSheet = sf::Texture();

    Monster::Monster(MonsterType type) : _frameClock(), _sprite(sf::seconds(0.1)) {
		switch (type) {
			case WHITE_MONSTER:
                _speedBase = 0.3;
				_health = 100;
				_spriteSheet.loadFromFile("Resources/Textures/WhiteMonsterSpriteSheet.png");
				break;
				
			case BLUE_MONSTER:
                _speedBase = 0.6, 0;
				_health = 50;
				_spriteSheet.loadFromFile("Resources/Textures/BlueMonsterSpriteSheet.png");
				break;
				
			case RED_MONSTER:
                _speedBase = 0.1;
				_health = 300;
				_spriteSheet.loadFromFile("Resources/Textures/RedMonsterSpriteSheet.png");
				break;
		}

		_walkForwardsAnimation.setSpriteSheet(_spriteSheet);
		_walkForwardsAnimation.addFrame(sf::IntRect(19, 88, 51, 51));
		_walkForwardsAnimation.addFrame(sf::IntRect(84, 91, 51, 51));
		_walkForwardsAnimation.addFrame(sf::IntRect(148, 87, 51, 51));
		_walkForwardsAnimation.addFrame(sf::IntRect(212, 81, 51, 51));
		_walkForwardsAnimation.addFrame(sf::IntRect(276, 88, 51, 51));

        _explodeSheet.loadFromFile("Resources/Textures/Explosion-Sprite-Sheet.png")
        _explodeAnimation.setSpriteSheet(_explodeSheet);
        _explodeAnimation.addFrame(sf::IntRect(0, 0, 115, 118));
        _explodeAnimation.addFrame(sf::IntRect(115, 0, 230, 118));
        _explodeAnimation.addFrame(sf::IntRect(230, 0, 345, 118));
        _explodeAnimation.addFrame(sf::IntRect(245, 0, 345, 118));
        _explodeAnimation.addFrame(sf::IntRect(360, 0, 465, 118));
        _explodeAnimation.addFrame(sf::IntRect(0, 0, 115, 118));
        _explodeAnimation.addFrame(sf::IntRect(480, 0, 589, 118));


		_deathAnimation.setSpriteSheet(_spriteSheet);
		_deathAnimation.addFrame(sf::IntRect(18, 217, 51, 51));
		_deathAnimation.addFrame(sf::IntRect(84, 217, 51, 51));
		_deathAnimation.addFrame(sf::IntRect(148, 217, 51, 51));
		_deathAnimation.addFrame(sf::IntRect(212, 217, 51, 51));
		_deathAnimation.addFrame(sf::IntRect(276, 217, 51, 51));
		_deathAnimation.addFrame(sf::IntRect(330, 217, 51, 51));
		_deathAnimation.addFrame(sf::IntRect(384, 217, 51, 51));

        _sprite.setOrigin(12.5, 16);
        _sprite.setScale(2.0, 2.0);
        _sprite.setAnimation(_walkForwardsAnimation);
        _sprite.setPosition(TileUtil::getSpawnLocation());

        _movementIndex = 0;
        _getNextPos();
    }

    void Monster::update() {
        //I'll be honest here, I have no idea what this does
        sf::Time frameTime = _frameClock.restart();
        //Only one axis of movement for now
		if (!_isDead) {
            _sprite.move(_speed);
		}

        if (_sprite.getPosition().x < _targetPos.x)
            _speed.x = _speedBase;
        else if (_sprite.getPosition().x > _targetPos.x)
            _speed.x = 0 - _speedBase;
        if (fabs(_sprite.getPosition().x - _targetPos.x) < _speedBase || _sprite.getPosition().x == _targetPos.x)
            _speed.x = 0;

        if (_sprite.getPosition().y < _targetPos.y)
            _speed.y = _speedBase;
        else if (_sprite.getPosition().y > _targetPos.y)
            _speed.y = 0 - _speedBase;
        if (fabs(_sprite.getPosition().y - _targetPos.y) < _speedBase || _sprite.getPosition().y == _targetPos.y)
            _speed.y = 0;

        if (_speed.x == 0 && _speed.y == 0)
            _getNextPos();

        if (_sprite.getPosition().x > TileUtil::getBaseLocation().x &&
            _sprite.getPosition().y > TileUtil::getBaseLocation().y)
            _explode();

        _sprite.update(frameTime);
    }

    void Monster::takeDamage(int damage) {
        _health -= damage;
    }

    void Monster::kill()
    {
        _sprite.stop();
        _sprite.setAnimation(_deathAnimation);
        _sprite.setLooped(false);
        _sprite.play();
        _isDead = true;
    }

    bool Monster::isDead()
    {
        return _isDead;
    }

    int Monster::getHealth()
    {
        return _health;
    }

    AnimatedSprite &Monster::getSprite() {
        return _sprite;
    }

    void Monster::_getNextPos() {
        _targetPos = TileUtil::getTargetPos(_movementIndex);
        _movementIndex++;
    }

    void Monster::_explode() {
        _sprite.stop();
        _sprite.setAnimation(_explodeAnimation);
        _sprite.setLooped(false);
        _sprite.play();
        _isDead = true;
    }
}
