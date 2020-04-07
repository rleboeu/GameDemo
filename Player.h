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
	std::vector<Projectile> getPlayerBullets();
	std::string getMagazineReport();
	int getCurrentMagazine();

	Weapon& getEquippedWeapon();

	bool playerReloading();

	void deleteBulletAt(int);

	void followMouseTo(sf::Vector2f);
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void setReloading(bool);

	void equipWeapon(Weapon);

	void shoot(sf::Vector2f, sf::Texture&);
	void reload();

	void update();



private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	std::vector<Projectile> playerBullets;

	int shootTimer;
	int timeBetweenShots;
	int magazineMax;
	int magazineCurrent;
	bool isReloading;

	float playerSpeed;


};

#endif /* PLAYER_H_ */
