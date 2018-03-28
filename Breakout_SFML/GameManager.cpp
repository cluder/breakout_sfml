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

Player* GameManager::createPlayer() {
	RectangleShape s(Vector2f(100, 20));
	s.setFillColor(Color::Yellow);
	return new Player(s);
}

void GameManager::createEntities() {
	pplayer = createPlayer();
	pplayer->setPosition(window.getSize().x / 2, window.getSize().y - 30);

	add(pplayer);

}

GameManager::~GameManager() {

	free(pplayer);
}

