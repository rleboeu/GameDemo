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

	static const unsigned int WIDTH = 1280;
	static const unsigned int HEIGHT = 720;

	sf::Texture PROJECTILE_TEXTURE;
	sf::Texture PLAYER_TEXTURE;
	sf::Texture ENEMY_TEXTURE;


private:

	static sf::RenderWindow window;
};

#endif /* GAME_H_ */
