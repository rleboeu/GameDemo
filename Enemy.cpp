/*
 * Enemy.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: nopath
 */

#include "Enemy.h"

Enemy::Enemy() {
	if (enemyTexture.loadFromFile("Resources/Textures/enemyBox.png") == false) {
		std::cout << "Failed to load Resources/Textures/enemyBox.png" << std::endl;
	}

	enemySprite.setTexture(enemyTexture);
	enemySprite.scale(0.5, 0.5);
	enemySprite.setOrigin(enemySprite.getLocalBounds().width / 2, enemySprite.getLocalBounds().height / 2);
	maxSpeed = 0.;
}

Enemy::Enemy(sf::Vector2f pos) {
	if (enemyTexture.loadFromFile("Resources/Textures/enemyBox.png") == false) {
		std::cout << "Failed to load Resources/Textures/enemyBox.png" << std::endl;
	}

	enemySprite.setTexture(enemyTexture);
	enemySprite.scale(0.5, 0.5);
	enemySprite.setOrigin(enemySprite.getLocalBounds().width / 2, enemySprite.getLocalBounds().height / 2);
	enemySprite.setPosition(pos);
	maxSpeed = 1;
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

sf::Sprite Enemy::getSprite() {
	return enemySprite;
}

void Enemy::rotateAccordingTo(sf::Vector2f playerPos) {
	float r_x = enemySprite.getPosition().x;
	float r_y = enemySprite.getPosition().y;
	float m_x = playerPos.x;
	float m_y = playerPos.y;

	// angle between y = 0 and line from rect origin to mouse pos
	float theta = atan((m_y - r_y)/(m_x - r_x));

	theta *= (180/M_PI);    // setRotation() only takes degrees

	// angle of rotation
	float theta_rot = 0.f;

	if ((m_y < r_y && m_x > r_x) || (m_y > r_y && m_x > r_x))     // quadrant 1 or 4
		theta_rot = theta;
	else
		theta_rot = theta + 180.f;

	enemySprite.setRotation(theta_rot);
}

void Enemy::follow(Player& player) {
	sf::Vector2f enemyCenter = enemySprite.getPosition();
	sf::Vector2f aimDir = player.getPlayerSprite().getPosition() - enemyCenter;
	sf::Vector2f aimDirNorm = aimDir / (float)(std::sqrt(std::pow(aimDir.x, 2) + std::pow(aimDir.y, 2)));

	speed = aimDirNorm * maxSpeed;
	enemySprite.setRotation(player.getPlayerSprite().getRotation());

	rotateAccordingTo(player.getPlayerSprite().getPosition());
}

void Enemy::update() {
	enemySprite.move(speed);
}

