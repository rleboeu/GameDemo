/*
 * InterfaceDisplay.cpp
 *
 *  Created on: Apr 7, 2020
 *      Author: nopath
 */

#include "InterfaceDisplay.h"
#include "Game.h"

InterfaceDisplay::InterfaceDisplay() {
	score = 0;

	defaultFont.loadFromFile("Resources/Fonts/LiberationSans-Regular.ttf");

	scoreText.setFont(defaultFont);
	scoreText.setString(std::to_string(score));
	scoreText.setOrigin(scoreText.getGlobalBounds().width / 2, scoreText.getGlobalBounds().height / 2);
	scoreText.setPosition(Game::WIDTH / 2, scoreText.getGlobalBounds().height / 2);

	playerHealthText.setFont(defaultFont);
	playerHealthText.setString("---");
	playerHealthText.setOrigin(playerHealthText.getGlobalBounds().width / 2, playerHealthText.getGlobalBounds().height / 2);
	playerHealthText.setPosition(Game::WIDTH / 2, Game::HEIGHT / 2);

	playerMagazineReport.setFont(defaultFont);
	playerMagazineReport.setString("--/--");
	playerMagazineReport.setOrigin(playerMagazineReport.getGlobalBounds().width / 2, playerMagazineReport.getGlobalBounds().height / 2);
	playerMagazineReport.setPosition(Game::WIDTH / 4, Game::HEIGHT - playerMagazineReport.getGlobalBounds().height);
}

InterfaceDisplay::~InterfaceDisplay() {
	// TODO Auto-generated destructor stub
}

int InterfaceDisplay::getScore() {
	return score;
}

sf::Text& InterfaceDisplay::getScoreText() {
	return scoreText;
}

sf::Text& InterfaceDisplay::getPlayerHealthText() {
	return playerHealthText;
}

sf::Font& InterfaceDisplay::getDefaultFont() {
	return defaultFont;
}

sf::Text& InterfaceDisplay::getPlayerMagazineReportText() {
	return playerMagazineReport;
}

void InterfaceDisplay::setScore(int x) {
	score = x;
	scoreText.setString(std::to_string(score));
}

void InterfaceDisplay::incrementScore() {
	score++;
	scoreText.setString(std::to_string(score));
}

void InterfaceDisplay::decrementScore() {
	score--;
	scoreText.setString(std::to_string(score));
}

void InterfaceDisplay::updatePlayerHealthText(int x) {
	playerHealthText.setString(std::to_string(x));
}

void InterfaceDisplay::updatePlayerMagazineReport(std::string x) {
	playerMagazineReport.setString(x);
}
