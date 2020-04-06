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

class Projectile
{
public:
	Projectile();

	sf::Texture BulletTexture;
	static sf::Sprite Bullet;

	static void SetDirection(sf::Sprite);
	static void SetSpeed(float);
	bool isFired;
};

#endif /* PROJECTILE_H_ */
