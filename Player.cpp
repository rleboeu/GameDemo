/*
 * Player.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: nopath
 */

#include "Player.h"
#include "Game.h"


Player::Player() {
	playerTexture.loadFromFile("Resources/Textures/box.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
	playerSprite.setPosition((float)(Game::WIDTH / 2), (float)(Game::HEIGHT / 2));
	playerSprite.scale(0.25, 0.25);

	playerSpeed = 6.f;
	shootTimer = 0;
	timeBetweenShots = 10;
	magazineMax = 20;
	magazineCurrent = magazineMax;
	isReloading = false;
}

Player::~Player() {
	// Auto-generated destructor stub
}

sf::Sprite& Player::getPlayerSprite() {
	return playerSprite;
}

float Player::getPlayerSpeed() {
	return playerSpeed;
}

std::vector<Projectile> Player::getPlayerBullets() {
	return playerBullets;
}

void Player::deleteBulletAt(int i) {
	playerBullets.erase(playerBullets.begin() + i);
}

std::string Player::getMagazineReport() {
	return std::to_string(magazineCurrent) + " / " + std::to_string(magazineMax);
}

int Player::getCurrentMagazine() {
	return magazineCurrent;
}

bool Player::isPlayerReloading() {
	return isReloading;
}

void Player::followMouseTo(sf::Vector2f mousePos) {
	float r_x = playerSprite.getPosition().x;
	float r_y = playerSprite.getPosition().y;
	float m_x = mousePos.x;
	float m_y = mousePos.y;

	// angle between y = 0 and line from rect origin to mouse pos
	float theta = atan((m_y - r_y)/(m_x - r_x));

	theta *= (180/M_PI);    // setRotation() only takes degrees

	// angle of rotation
	float theta_rot = 0.f;

	if ((m_y < r_y && m_x > r_x) || (m_y > r_y && m_x > r_x))     // quadrant 1 or 4
		theta_rot = theta;
	else
		theta_rot = theta + 180.f;

	playerSprite.setRotation(theta_rot);
}

void Player::moveLeft() {
	if (playerSprite.getPosition().x <= playerSprite.getGlobalBounds().width / 2 + playerSpeed)
		playerSprite.setPosition(playerSprite.getGlobalBounds().width / 2, playerSprite.getPosition().y);
	else
		playerSprite.move(-playerSpeed, 0);
}

void Player::moveRight() {
	if (playerSprite.getPosition().x >= Game::WIDTH - playerSprite.getGlobalBounds().width / 2 - playerSpeed)
		playerSprite.setPosition(Game::WIDTH - playerSprite.getGlobalBounds().width / 2, playerSprite.getPosition().y);
	else
		playerSprite.move(playerSpeed, 0);
}

void Player::moveDown() {
	if (playerSprite.getPosition().y >= Game::HEIGHT - playerSprite.getGlobalBounds().height / 2 - playerSpeed)
		playerSprite.setPosition(playerSprite.getPosition().x, Game::HEIGHT - playerSprite.getGlobalBounds().height / 2);
	else
		playerSprite.move(0, playerSpeed);
}

void Player::moveUp() {
	if (playerSprite.getPosition().y <= playerSprite.getGlobalBounds().height / 2 + playerSpeed)
		playerSprite.setPosition(playerSprite.getPosition().x, playerSprite.getGlobalBounds().height / 2);
	else
		playerSprite.move(0, -playerSpeed);
}

void Player::shoot(sf::Vector2f mousePosWindow) {

	if (magazineCurrent > 0) {
		sf::Vector2f playerCenter = playerSprite.getPosition();
		sf::Vector2f aimDir = mousePosWindow - playerCenter;
		sf::Vector2f aimDirNorm = aimDir / (float)(std::sqrt(std::pow(aimDir.x, 2) + std::pow(aimDir.y, 2)));

		if (shootTimer < timeBetweenShots)
			shootTimer++;

		if (shootTimer >= timeBetweenShots) {
			Projectile p(playerSprite, aimDirNorm);
			playerBullets.push_back(p);
			magazineCurrent--;
			shootTimer = 0;
		}
	} else {
		isReloading = true;
	}

}

void Player::reload() {
	magazineCurrent = magazineMax;
}

void Player::update() {

	// DESTROY UNUSED BULLETS AND UPDATE BULLETS STILL TRAVELLING
	for (size_t i = 0; i < playerBullets.size(); i++) {
		if (playerBullets.at(i).checkBounds() == false) {
			playerBullets.erase(playerBullets.begin() + i);
		} else {
			playerBullets.at(i).update();
		}
	}

}













