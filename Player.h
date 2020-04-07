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
#include "Weapon.h"

class Player {

	Weapon equippedWeapon;

public:
	Player();
	Player(sf::Texture&);
	virtual ~Player();

	sf::Sprite& getPlayerSprite();
	float getPlayerSpeed();

	Weapon& getEquippedWeapon();

	void followMouseTo(sf::Vector2f);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void equipWeapon(Weapon);

	void update();

private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	float playerSpeed;
};

#endif /* PLAYER_H_ */
