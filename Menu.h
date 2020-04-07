/*
 * Menu.h
 *
 *  Created on: Apr 6, 2020
 *      Author: nopath
 */

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics.hpp>
#include <vector>

class Menu {
public:
	Menu();
	virtual ~Menu();
	int start();
	bool isRunning;

	static const unsigned int WIDTH = 1280;
	static const unsigned int HEIGHT = 720;

private:
	int pick();
	sf::Font font;
	sf::Text title;

	std::vector<sf::Text> options;

};

#endif /* MENU_H_ */
