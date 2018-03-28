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

	// game manager holds a list of pointers to drawables
	GameManager manager(window);
	manager.createEntities();

	while(window.isOpen()) {
		Event e;
		while(window.pollEvent(e)) {
			if (e.type == Event::Closed){
				window.close();
			}
		}

		manager.draw();

	}

	return 0;
}



