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

	equippedWeapon = new Weapon();
}

Player::Player(sf::Texture& texture) {
	playerSprite.setTexture(texture);
	playerSprite.setOrigin(playerSprite.getLocalBounds().width / 2, playerSprite.getLocalBounds().height / 2);
	playerSprite.setPosition((float)(Game::WIDTH / 2), (float)(Game::HEIGHT / 2));
	playerSprite.scale(0.25, 0.25);

	playerSpeed = 6.f;

	equippedWeapon = new Weapon();
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

Weapon& Player::getEquippedWeapon() {
	return equippedWeapon;
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

void Player::equipWeapon(Weapon weapon) {
	equippedWeapon = weapon;
}

void Player::update() {
	equippedWeapon.tickReload();
	equippedWeapon.removeTrespassingBullets();
}













