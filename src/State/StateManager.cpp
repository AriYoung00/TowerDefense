#include "State/StateManager.h"

StateManager::StateManager() {
	_lives = 3;
	_score = 0;
	_coins = 200;
}

void StateManager::removeLife() {
	_lives--;
}

void StateManager::addScore(int number) {
	_score += number;
}

void StateManager::addCoins(int number) {
	_coins += number;
}

bool StateManager::removeCoins(int number) {
	if (_coins >= number) {
		_coins -= number;
		return true;
	} else {
		return false;
	}
}

int StateManager::getLives() {
	return _lives;
}

int StateManager::getScore() {
	return _score;
}

int StateManager::getCoins() {
	return _coins;
}
