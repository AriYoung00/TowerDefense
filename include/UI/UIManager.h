#ifndef _UIMANAGER_H_INCLUDED
#define _UIMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "State/StateManager.h"

class UIManager {
public:
	UIManager(sf::RenderWindow &window, StateManager &stateManager);
	void update();
	void render();
private:
	sf::RenderWindow &_window;
	StateManager &_stateManager;
	sf::Font _font;
	sf::Text _lives_display;
	sf::Text _score_display;
	sf::Text _coins_display;
};
#endif
