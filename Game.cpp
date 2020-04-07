/*
 * Game.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: nopath
 */

#include "Game.h"
#include "Player.h"
#include "Enemy.h"

sf::RenderWindow Game::window(sf::VideoMode(Game::WIDTH, Game::HEIGHT), "boxxxy", sf::Style::Titlebar | sf::Style::Close);

Game::Game() {
	// stub
	score = 0;
}

Game::~Game() {
	// stub
}

void Game::initialize() {
	window.setFramerateLimit(60);
	window.setPosition(sf::Vector2i( (sf::VideoMode::getDesktopMode().width - Game::WIDTH) / 2, (sf::VideoMode::getDesktopMode().height - Game::HEIGHT) / 2));

	font.loadFromFile("Resources/Fonts/LiberationSans-Regular.ttf");

	magazine.setFont(font);
	magazine.setPosition(0, window.getSize().y / 2 - magazine.getGlobalBounds().height / 2);

	scoreLabel.setFont(font);
	scoreLabel.setString(std::to_string(score));
	scoreLabel.setPosition(0, window.getSize().y / 2 + 100);

	PROJECTILE_TEXTURE.loadFromFile("Resources/Textures/bullet.png");
	ENEMY_TEXTURE.loadFromFile("Resources/Textures/enemyBox.png");
	PLAYER_TEXTURE.loadFromFile("Resources/Textures/box.png");
}

void Game::start() {

	Player player(PLAYER_TEXTURE); // @suppress("Ambiguous problem")
	std::vector<Enemy> enemies;
	int enemySpawnTimer = 0;
	int enemySpawnLimit = 100;
	int limitAdjustedAt = 0;

	while (window.isOpen()) {
		// logic
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
//
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.moveLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.moveRight();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player.moveUp();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.moveDown();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
			player.getEquippedWeapon().reload();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player.getEquippedWeapon().isBeingReloaded() == false) {
			player.getEquippedWeapon().fire(sf::Vector2f(sf::Mouse::getPosition(window)), player.getPlayerSprite(), PROJECTILE_TEXTURE);
		}

		///  PLAYER
		player.followMouseTo(sf::Vector2f(sf::Mouse::getPosition(window)));
		player.update();

			/// ENEMIES
		if (enemySpawnTimer < enemySpawnLimit)
			enemySpawnTimer++;

		if (enemySpawnTimer >= enemySpawnLimit) {
			enemies.push_back(Enemy(sf::Vector2f((rand() % int(window.getSize().x - 100)), (rand() % int(window.getSize().y - 100))), ENEMY_TEXTURE));
			enemySpawnTimer = 0;
		}

		for (size_t i = 0; i < enemies.size(); i++) {
			enemies.at(i).follow(player);
			enemies.at(i).update();
		}

		/// COLLISION
		for (size_t i = 0; i < player.getEquippedWeapon().activeBullets.size(); i++) {
			for (size_t k = 0; k < enemies.size(); k++) {
				if (player.getEquippedWeapon().activeBullets.at(i).getBullet().getGlobalBounds().intersects(enemies.at(k).getSprite().getGlobalBounds())) {
					player.getEquippedWeapon().activeBullets.erase(player.getEquippedWeapon().activeBullets.begin() + i);
					enemies.erase(enemies.begin() + k);
					score++;
					scoreLabel.setString(std::to_string(score));
					break;
				}
			}
		}


		/// SCALING MODIFIERS
		if (score % 10 == 0 && limitAdjustedAt != score && score < 200) {
			enemySpawnLimit -= enemySpawnLimit / 10;

			limitAdjustedAt = score;
		}

		///		TEXT
		magazine.setString(player.getEquippedWeapon().getMagazineReport());

		// draw
		window.clear();

		window.draw(magazine);
		window.draw(scoreLabel);

		for (Projectile p : player.getEquippedWeapon().activeBullets) {
			window.draw(p.getBullet());
		}

		window.draw(player.getPlayerSprite());

		for (Enemy e : enemies) {
			window.draw(e.getSprite());
		}

		// display
		window.display();
	}
}



