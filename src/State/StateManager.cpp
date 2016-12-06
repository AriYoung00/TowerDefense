#include "State/StateManager.h"

StateManager::StateManager() {
	_lives = 3;
	_score = 0;
	_coins = 0;
}

void StateManager::removeLife() {
	_lives--;
}

void StateManager::addScore(int number) {
	_score += number;
}

bool StateManager::removeCoins(int number) {
	if (number > _coins) {
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
