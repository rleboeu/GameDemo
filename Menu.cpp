/*
 * Menu.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: nopath
 */

#include "Menu.h"

Menu::Menu() {
	isRunning = false;
}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

int Menu::start() {
	isRunning = true;
	sf::RenderWindow window(sf::VideoMode(Menu::WIDTH, Menu::HEIGHT), "boxxxy",  sf::Style::Titlebar | sf::Style::Close);

		font.loadFromFile("Resources/Fonts/LiberationSans-Regular.ttf");
		title.setFont(font);
		title.setString("boxxxy");
		title.setPosition(window.getSize().x / 2 - title.getGlobalBounds().width / 2, 0);

		sf::Text option1;
		option1.setFont(font);
		option1.setString("Play");
		option1.setOrigin(option1.getGlobalBounds().width / 2, option1.getGlobalBounds().height / 2);

		sf::Text option2;
		option2.setFont(font);
		option2.setString("Exit");
		option2.setOrigin(option2.getGlobalBounds().width / 2, option2.getGlobalBounds().height / 2);

		options.push_back(option1);
		options.push_back(option2);

		size_t currentSelection = 0;
		sf::RectangleShape selectIcon(sf::Vector2f(20, 20));
		selectIcon.setFillColor(sf::Color::Yellow);
		selectIcon.setOrigin(10, 10);

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					isRunning = false;
					return -1;
				}
			}

			// input parsing
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				if (currentSelection > 0) {
					currentSelection--;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				if (currentSelection < options.size()-1) {
					currentSelection++;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				if (currentSelection == 0) {
					window.close();
				}
				if (currentSelection == options.size()-1) {
					window.close();
					return -1;
				}
			}

			// object logic
			for (size_t i = 0; i < options.size(); i++) {
				options.at(i).setPosition(window.getSize().x / 2, 200 + (i + 1) * 50);
			}

			selectIcon.setPosition(window.getSize().x / 2 - selectIcon.getSize().x * 2, options.at(currentSelection).getPosition().y);

	/////////
			window.clear();
	/////////

			// draw objects
			window.draw(title);

			for (size_t i = 0; i < options.size(); i++) {
				window.draw(options.at(i));
			}

			window.draw(selectIcon);

			// display window
			window.display();
		}

		return 1;
}




