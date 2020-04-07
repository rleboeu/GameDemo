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

	void start();
	void initialize();

	int getScore();
	void setScore(int);
	void incrementScore();

	static const unsigned int WIDTH = 1280;
	static const unsigned int HEIGHT = 720;

private:

	static sf::RenderWindow window;
	sf::Font font;
	sf::Text title;
	sf::Text magazine;
	int score;
	sf::Text scoreLabel;
};

#endif /* GAME_H_ */
