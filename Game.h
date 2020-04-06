/*
 * Game.h
 *
 *  Created on: Apr 6, 2020
 *      Author: nopath
 */

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>

class Game {
public:
	Game();
	virtual ~Game();

	static const unsigned int WIDTH = 1280;
	static const unsigned int HEIGHT = 720;

private:
	void start();
	void initialize();
	static sf::RenderWindow window;
	sf::Font font;
	sf::Text title;
};

#endif /* GAME_H_ */
