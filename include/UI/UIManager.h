#ifndef _UIMANAGER_H_INCLUDED
#define _UIMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class UIManager {
public:
	UIManager(sf::RenderWindow &window);
	void removeLife();
	void addPoints(int points);
	void update();
	void render();
private:
	sf::RenderWindow &_window;
	int _lives = 3;
	int _points = 0;
	sf::Font _font;
	sf::Text _lives_display;
	sf::Text _score_display;
};
#endif
