/*
 * Projectile.h
 *
 *  Created on: Apr 5, 2020
 *      Author: nopath
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Game.h"

class Projectile
{
public:
	Projectile();
	Projectile(sf::Sprite&, sf::Vector2f&, sf::Texture&);
	~Projectile();

	sf::Vector2f speed;
	float maxSpeed;

	void setMaxSpeed(float);
	bool checkBounds();
	sf::Sprite getBullet();
	void update();

private:
	sf::Sprite bullet;

};

#endif /* PROJECTILE_H_ */
