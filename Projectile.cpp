/*
 * Projectile.cpp
 *
 *  Created on: Apr 5, 2020
 *      Author: nopath
 */

#include "Projectile.h"

Projectile::Projectile() {
	//bulletTexture.loadFromFile("Resources/Textures/bullet.png");
	//bullet.setTexture(bulletTexture);

	maxSpeed = 0.f;
}

Projectile::Projectile(sf::Sprite& reference, sf::Vector2f& aimDirNorm) {
	//bulletTexture.loadFromFile("Resources/Textures/bullet.png");
	//bullet.setTexture(bulletTexture);
	bullet.setColor(sf::Color::Yellow);
	sf::Texture text;
	text.create(10, 3);
	bullet.setTexture(text);
	bullet.scale(2.0, 1.5);

	bullet.setOrigin(sf::Vector2f(bullet.getLocalBounds().width / 2, bullet.getLocalBounds().height / 2));
	bullet.setRotation(reference.getRotation());
	bullet.setPosition(reference.getPosition());

	maxSpeed = 30.f;

	speed = aimDirNorm * maxSpeed;
}

Projectile::~Projectile() {
	// stub
}

void Projectile::setMaxSpeed(float s) {
	speed /= maxSpeed;
	maxSpeed = s;
	speed *= maxSpeed;
}

bool Projectile::checkBounds() {
	if (bullet.getPosition().x <= 0 || bullet.getPosition().y <= 0) {
		return false;
	}

	if (bullet.getPosition().x >= Game::WIDTH || bullet.getPosition().y >= Game::HEIGHT) {
		return false;
	}

	return true;
}

sf::Sprite Projectile::getBullet() {
	return bullet;
}

void Projectile::update() {
	checkBounds();
	bullet.move(speed);
}




