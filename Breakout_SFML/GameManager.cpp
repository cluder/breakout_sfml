/*
 * GameManager.cpp
 *
 *  Created on: 26.03.2018
 *      Author: core
 */

#include "SFML/Graphics.hpp"

#include "GameManager.h"
#include "Player.h"

using namespace sf;

GameManager::GameManager(RenderWindow &w)
	: window(w), pplayer(NULL)
{

}

void GameManager::add(BaseEntity *e) {
	entities.push_back(e);
}

void GameManager::update () {

}

void GameManager::draw() {
	// clear screen
	window.clear();

	for (BaseEntity* p : this->entities) {
		window.draw(p->shape);
	}

	// update screen
	window.display();
}

void GameManager::createEntities() {

	pplayer = new Player(50, 10);
	pplayer->setColor(sf::Color::Yellow);
	pplayer->setPosition(window.getSize().x / 2, window.getSize().y - 30);

	add(pplayer);
}

GameManager::~GameManager() {
	delete(pplayer);
}

