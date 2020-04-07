#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>

#include "Game.h"
#include "Menu.h"

int main() {
	Game game;
	Menu menu;
	int value = menu.start();

	if (value > 0) {
		game.initialize();
		game.start();
	}


	return 0;
}
