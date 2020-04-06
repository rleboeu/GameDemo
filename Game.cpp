/*
 * Game.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: nopath
 */

#include "Game.h"
#include "Player.h"

sf::RenderWindow Game::window(sf::VideoMode(Game::WIDTH, Game::HEIGHT), "boxxxy", sf::Style::Titlebar | sf::Style::Close);

Game::Game() {
	initialize();
	start();
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::initialize() {
	window.setFramerateLimit(60);
	window.setPosition(sf::Vector2i( (sf::VideoMode::getDesktopMode().width - Game::WIDTH) / 2, (sf::VideoMode::getDesktopMode().height - Game::HEIGHT) / 2));
	font.loadFromFile("Resources/Fonts/TypoDraftDemo.otf");
	title.setFont(font);
	title.setString("boxxxy");
	title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 0);
}

void Game::start() {

	Player player;

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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			player.shoot(sf::Vector2f(sf::Mouse::getPosition(window)));
		}

		// update
		window.clear();

		window.draw(title);

		player.followMouseTo(sf::Vector2f(sf::Mouse::getPosition(window)));
		player.update();

		// draw
		for (Projectile p : player.getPlayerBullets()) {
			window.draw(p.getBullet());
		}

		window.draw(player.getPlayerSprite());

		// display
		window.display();
	}
}
