#include "UI/UIManager.h"

UIManager::UIManager(sf::RenderWindow &window, StateManager &stateManager) : _window(window), _stateManager(stateManager) {
	_font.loadFromFile("Resources/Fonts/OpenSans-Bold.ttf");
	
	// Lives
	_lives_display.setString("Lives: 3/3");
	_lives_display.setFont(_font);
	_lives_display.setFillColor(sf::Color::White);
	_lives_display.setCharacterSize(30);
	_lives_display.setPosition(_window.getSize().x - 150, 5);
	
	// Score
	_score_display.setString("Score: 0");
	_score_display.setFont(_font);
	_score_display.setFillColor(sf::Color::White);
	_score_display.setCharacterSize(30);
	_score_display.setPosition(_window.getSize().x - 300, 5);
	
	// Coins
	_coins_display.setString("Coins: 0");
	_coins_display.setFont(_font);
	_coins_display.setFillColor(sf::Color::White);
	_coins_display.setCharacterSize(30);
	_coins_display.setPosition(_window.getSize().x - 450, 5);
}


void UIManager::update() {
	// Lives
	std::ostringstream lives_text;
	lives_text << "Lives: " << _stateManager.getLives() << "/3";
	_lives_display.setString(lives_text.str());
	
	// Points
	std::ostringstream points_text;
	points_text << "Points: " << _stateManager.getScore();
	_score_display.setString(points_text.str());
	
	// Coins
	std::ostringstream coins_text;
	coins_text << "Coins: " << _stateManager.getCoins();
	_coins_display.setString(coins_text.str());
}

void UIManager::render() {
	_window.draw(_lives_display);
	_window.draw(_score_display);
	_window.draw(_coins_display);
}
