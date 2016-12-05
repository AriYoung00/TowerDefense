#include "UI/UIManager.h"

UIManager::UIManager(sf::RenderWindow &window) : _window(window) {
//	_window = window;
	_font.loadFromFile("Resources/Fonts/OpenSans-Bold.ttf");
	_lives_display.setString("Lives: 3/3");
	_lives_display.setFont(_font);
	_lives_display.setFillColor(sf::Color::White);
	_lives_display.setCharacterSize(30);
	_lives_display.setPosition(_window.getSize().x - 150, 5);
	_score_display.setString("Score: 0");
	_score_display.setFont(_font);
	_score_display.setFillColor(sf::Color::White);
	_score_display.setCharacterSize(30);
	_score_display.setPosition(_window.getSize().x - 300, 5);
}

void UIManager::removeLife() {
	_lives--;
	std::ostringstream text;
	text << "Lives: " << _lives << "/3";
	_lives_display.setString(text.str());
}

void UIManager::addPoints(int points) {
	_points += points;
	std::ostringstream text;
	text << "Points: " << _points;
	_score_display.setString(text.str());
}

void UIManager::update() {
	
}

void UIManager::render() {
	_window.draw(_lives_display);
	_window.draw(_score_display);
}
