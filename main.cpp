#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>

#include "Projectile.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "boxxxy", sf::Style::Default);
	window.setFramerateLimit(60);

	sf::Texture boxTexture;
	boxTexture.loadFromFile("Resources/Textures/box.png");

	sf::Sprite player;
	player.setTexture(boxTexture);
	player.setOrigin(player.getGlobalBounds().width / 2, player.getGlobalBounds().height / 2);
	player.setPosition((float)(window.getSize().x / 2), (float)(window.getSize().y / 2));
	player.scale(0.5, 0.5);

    float playerSpeed = 6.0f;
    sf::Vector2f playerCenter = player.getPosition();
    sf::Vector2f aimDir, aimDirNorm;
    sf::Vector2f mousePosWindow;
    int shootTimer = 10;

    float m_x = 0.f;
    float m_y = 0.f;

    std::vector<Projectile> playerBullets;

	while (window.isOpen()) {

		sf::Event event;
		while(window.pollEvent(event)) {
			 if (event.type == sf::Event::Closed)
				 window.close();

			 if (event.type == sf::Event::MouseMoved) {
			    m_x = (float)sf::Mouse::getPosition(window).x;
			    m_y = (float)sf::Mouse::getPosition(window).y;
			 }
		}

		// logic

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		    if (player.getPosition().x <= player.getGlobalBounds().width / 2 + playerSpeed)
		    	player.setPosition(player.getGlobalBounds().width / 2, player.getPosition().y);
		    else
		        player.move(-playerSpeed, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

			if (player.getPosition().x >= window.getSize().x - player.getGlobalBounds().width / 2 - playerSpeed)
					    	player.setPosition(window.getSize().x - player.getGlobalBounds().width / 2, player.getPosition().y);
			else
				player.move(playerSpeed, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

		    if (player.getPosition().y <= player.getGlobalBounds().height / 2 + playerSpeed)
		    	player.setPosition(player.getPosition().x, player.getGlobalBounds().height / 2);
		    else
		        player.move(0, -playerSpeed);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

			if (player.getPosition().y >= window.getSize().y - player.getGlobalBounds().height / 2 - playerSpeed)
					    	player.setPosition(player.getPosition().x, window.getSize().y - player.getGlobalBounds().height / 2);
		    else
		        player.move(0, playerSpeed);
		}

		if (shootTimer < 10)
			shootTimer++;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && shootTimer >= 10) {
			Projectile p(player, aimDirNorm);
			playerBullets.push_back(p);

			shootTimer = 0;
		}


		// ROTATE PLAYER SPRITE TO FACE THE MOUSE
		float r_x = player.getPosition().x;
		float r_y = player.getPosition().y;

		// angle between y = 0 and line from rect origin to mouse pos
		float theta = atan((m_y - r_y)/(m_x - r_x));

		theta *= (180/M_PI);    // setRotation() only takes degrees

		// angle of rotation
		float theta_rot = 0.f;

		if ((m_y < r_y && m_x > r_x) || (m_y > r_y && m_x > r_x))     // quadrant 1 or 4
		    theta_rot = theta;
		else
			theta_rot = theta + 180.f;

		player.setRotation(theta_rot);


		// CALCULATE THE NORMAL VECTOR FOR THE DIRECTION OF THE BULLET
		playerCenter = player.getPosition();
		mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
		aimDir = mousePosWindow - playerCenter;
		aimDirNorm = aimDir / (float)(std::sqrt(std::pow(aimDir.x, 2) + std::pow(aimDir.y, 2)));



		// DESTROY UNUSED BULLETS AND UPDATE BULLETS STILL TRAVELLING
		for (size_t i = 0; i < playerBullets.size(); i++) {
			if (playerBullets.at(i).checkBounds(window) == false) {
				playerBullets.erase(playerBullets.begin() + i);
			} else {
				playerBullets.at(i).update();
			}
		}

		// render
		window.clear();

		for (Projectile x : playerBullets) {
			window.draw(x.getBullet());
		}

		window.draw(player);

		// draw
		window.display();
	}

	return 0;
}
