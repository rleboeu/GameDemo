/*
 * InterfaceDisplay.h
 *
 *  Created on: Apr 7, 2020
 *      Author: nopath
 */

#ifndef INTERFACEDISPLAY_H_
#define INTERFACEDISPLAY_H_

#include <SFML/Graphics.hpp>

class InterfaceDisplay {
public:
	InterfaceDisplay();
	virtual ~InterfaceDisplay();

	int getScore();
	sf::Text& getScoreText();
	sf::Text& getPlayerHealthText();
	sf::Font& getDefaultFont();
	sf::Text& getPlayerMagazineReportText();

	void setScore(int);
	void incrementScore();
	void decrementScore();

	void updatePlayerHealthText(int);
	void updatePlayerMagazineReport(std::string);

private:
	sf::Font defaultFont;

	int score;
	sf::Text scoreText;

	sf::Text playerHealthText;
	sf::Text playerMagazineReport;
};

#endif /* INTERFACEDISPLAY_H_ */
