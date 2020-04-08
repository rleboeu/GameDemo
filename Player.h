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

	// properties
	sf::Sprite& getPlayerSprite();
	float getPlayerSpeed();

	// weapons
	Weapon& getEquippedWeapon();
	void equipWeapon(Weapon);

	// movement
	void followMouseTo(sf::Vector2f);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	// health
	int getCurrentHealth();
	int getMaxHealth();
	bool getIsDead();
	void setMaxHealth(int);
	void setCurrentHealth(int);
	void isHit();
	void isHit(int);
	void isHealed();
	void isHealed(int);

	void update();

private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	float playerSpeed;

	int playerHealth;
	int playerMaxHealth;
	bool isDead;
};

#endif /* PLAYER_H_ */
