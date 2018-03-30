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
	: window(w), player(NULL), ball(NULL)
{

}

void GameManager::handleCollision() {
	sf::Vector2u wSize = window.getSize();

	// check ball vs player

	sf::FloatRect ballBounds = ball->getShape().getGlobalBounds();
	sf::FloatRect playerBounds = player->getShape().getGlobalBounds();

	fprintf(stderr, "player bounds x-x:%f-%f\n",
		playerBounds.left, playerBounds.left+playerBounds.width);

	if (ballBounds.intersects(playerBounds)) {
		ball->setYVelocity(-ball->getXVelocity());
		const sf::Vector2f pos = ball->getShape().getPosition();

		// move ball above player
		ball->setPosition(pos.x, playerBounds.top-ballBounds.height);
	}

	// ball vs outer walls
	if (ballBounds.left < 0) {
		// bounce to the right
		ball->setXVelocity(abs(ball->getXVelocity()));

		// reset position to edge of wall
		ball->setPosition(0, ballBounds.top);
	}

	if(ballBounds.left + ballBounds.width > wSize.x) {
		// bounce to the left
		ball->setXVelocity(-abs(ball->getXVelocity()));
		// reset position to edge of wall
		ball->setPosition(wSize.x - ballBounds.width, ballBounds.top);
	}

	if(ballBounds.top < 0) {
		// bounce down
		ball->setYVelocity(abs(ball->getYVelocity()));
		// reset position to edge of wall
		ball->setPosition(ballBounds.left, 0);
	}

}

void GameManager::update (Int32 tpf) {

	// move player / update bricks
	for (RectangleEntity *e: entities) {
		e->update(tpf);
	}

	handleCollision();

	// move ball
	ball->update(tpf);

}

void GameManager::handleEvent(Event &e) {
	if ((e.type == Event::KeyPressed && e.key.code == Keyboard::Escape) ||
		e.type == Event::Closed) {
		window.close();
		return;
	}

	if (e.type == Event::KeyPressed && e.key.code == Keyboard::Space) {
		// reset ball pos
		ball->setPosition(window.getSize().x/2, window.getSize().y/2);
		ball->setXVelocity(50);
		ball->setYVelocity(150);
	}

	if (e.type == Event::KeyPressed || e.type == Event::KeyReleased) {
		player->handleEvent(e);
	}
}

void GameManager::draw() {
	// clear screen
	window.clear();

	// draw all entities
	for (RectangleEntity* p : this->entities) {
		p->draw(window);
	}

	ball->draw(window);

	// update screen
	window.display();
}

void GameManager::createEntities() {
	// create player
	player = new Player(70, 10);
	player->setColor(sf::Color::Yellow);
	player->setPosition(window.getSize().x / 2, window.getSize().y - 30);
	player->setSpeed(600);

	// create bricks
	createBricks(7, 5, 10, 10);

	createBall(5, 10);

	entities.push_back(player);
}

void GameManager::createBall(float radius, int pc) {
	sf::Vector2u size = window.getSize();

	ball = new Ball(radius, pc, 100);
	ball->setPosition(size.x/3, size.y -250);

}

void GameManager::createBricks(int cols, int rows, float spacing, float brickHeight) {

	// screen size
	sf::Vector2u screen = window.getSize();

	// between each brick, there should be spacing (#cols +1)
	float sumSpacing = (cols + 1) * spacing;
	// calculate brick length
	float brickLength = (screen.x - sumSpacing) / cols;

	// 1. brick starting point
	int posX = spacing;
	int posY = 50;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			// increment by the brick len and a space
			RectangleEntity *e = new RectangleEntity(brickLength, brickHeight);
			e->setPosition(posX, posY);
			entities.push_back(e);

			posX += brickLength + spacing;
		}
		posX = spacing;
		posY += brickHeight + spacing;
	}

}

GameManager::~GameManager() {

	for (RectangleEntity *e: entities) {
		delete e;
	}
	delete ball;
}

