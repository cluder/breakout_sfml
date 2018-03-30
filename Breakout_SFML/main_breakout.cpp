/*
 * main_breakout.cpp
 *
 *  Created on: 26.03.2018
 *      Author: core
 */

#include "SFML/Graphics.hpp"

#include "GameManager.h"
#include "Player.h"

using namespace sf;

int main(int argc, char **argv)
{
	RenderWindow window(VideoMode(500, 500), "Breakout");
	window.setVerticalSyncEnabled(true);

	// game manager holds a list of pointers to drawables
	GameManager manager(window);
	manager.createEntities();

	Clock clock;
	while(window.isOpen()) {
		Event e;
		while(window.pollEvent(e)) {
			manager.handleEvent(e);
		}

		sf::Time elapsed = clock.restart();
		sf::Int32 tpf = elapsed.asMilliseconds();

		manager.update(tpf);
		manager.draw();
	}

	return 0;
}



