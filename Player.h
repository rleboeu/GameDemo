/*
 * Player.h
 *
 *  Created on: Apr 6, 2020
 *      Author: nopath
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>

#include "Projectile.h"

class Player {
public:
	Player();
	virtual ~Player();

	sf::Sprite& getPlayerSprite();
	float getPlayerSpeed();
	std::vector<Projectile> getPlayerBullets();

	void followMouseTo(sf::Vector2f);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void shoot(sf::Vector2f);
	void update();



private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	std::vector<Projectile> playerBullets;

	int shootTimer;
	int timeBetweenShots;

	float playerSpeed;
};

#endif /* PLAYER_H_ */
