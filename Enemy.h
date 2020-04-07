/*
 * Enemy.h
 *
 *  Created on: Apr 6, 2020
 *      Author: nopath
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "Player.h"

class Enemy {
public:
	Enemy();
	Enemy(sf::Vector2f);
	virtual ~Enemy();

	sf::Sprite getSprite();

	void update();
	void follow(Player&);


private:
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	float maxSpeed;
	sf::Vector2f speed;

	void rotateAccordingTo(sf::Vector2f);
};

#endif /* ENEMY_H_ */
