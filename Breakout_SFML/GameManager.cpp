/*
 * GameManager.cpp
 *
 *  Created on: 26.03.2018
 *      Author: core
 */

#include <algorithm>
#include "SFML/Graphics.hpp"

#include "GameManager.h"
#include "Player.h"

using namespace sf;


bool isDestroyed(RectangleEntity *e) {
	return e->getHealth() == 0;
}

GameManager::GameManager(RenderWindow &w)
	: window(w), player(NULL), ball(NULL)
{

}

void GameManager::handleBrickCollision(const sf::FloatRect& ballBounds) {
	// check collision with bricks
	for (RectangleEntity* b : entities) {
		FloatRect in;
		sf::FloatRect bb = b->getShape().getGlobalBounds();
		if (ballBounds.intersects(bb, in)) {
			if (abs((in.top + in.height) - (bb.top + bb.height)) < 0.001) {
				// hit bottom of brick - bounce down
				ball->setYVelocity(abs(ball->getYVelocity()));
				b->hit();
			}
			if (abs((in.top) - (bb.top)) < 0.001) {
				// hit top of brick - bounce up
				ball->setYVelocity(-abs(ball->getYVelocity()));
			}
			if (abs((in.left) - (bb.left)) < 0.001) {
				// hit left of brick - bounce left
				ball->setXVelocity(-abs(ball->getXVelocity()));
			}
			if (abs((in.left + in.width) - (bb.left + bb.width)) < 0.001) {
				// hit right of brick - bounce right
				ball->setXVelocity(abs(ball->getXVelocity()));
			}
		}
	}
	// remove destroyed bricks
	entities.erase(
			std::remove_if(entities.begin(), entities.end(), isDestroyed),
			entities.end());
}

void GameManager::handleCollision() {
	sf::Vector2u wSize = window.getSize();

	// check ball vs player

	sf::FloatRect ballBounds = ball->getShape().getGlobalBounds();
	sf::FloatRect playerBounds = player->getShape().getGlobalBounds();

	if (ballBounds.intersects(playerBounds)) {
		ball->setYVelocity(-abs(ball->getYVelocity()));
		const sf::Vector2f pos = ball->getShape().getPosition();

		// move ball above player
		ball->setPosition(pos.x, playerBounds.top-ballBounds.height);

		// alter ball velocity depending on where the ball hit the paddle
		float paddleCenter = playerBounds.left + playerBounds.width/2;
		float ballCenter = ballBounds.left + ballBounds.width/2;

		float diff = ballCenter - paddleCenter;

		float fact = 1 / (playerBounds.width/2) * diff;
		float velChange = 200*fact;

		float xVel = ball->getXVelocity();
		ball->setXVelocity(std::min(xVel+velChange, ball->getMaxVel()));
	}

	// check player vs outer walls
	if (playerBounds.left < 0) {
		player->setPosition(0, player->getPosition().y);
	}
	if (playerBounds.left + playerBounds.width > wSize.x) {
		player->setPosition(wSize.x-playerBounds.width, player->getPosition().y);
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

	// check collision with bricks
	handleBrickCollision(ballBounds);
}


void GameManager::handleEvent(Event &e) {
	if ((e.type == Event::KeyPressed && e.key.code == Keyboard::Escape) ||
		e.type == Event::Closed) {
		window.close();
		return;
	}

	if (e.type == Event::KeyPressed && e.key.code == Keyboard::Space) {
		// reset ball pos
		ball->setPosition(player->getPosition().x +20 , player->getPosition().y - 20);
	}

	if (e.type == Event::KeyPressed || e.type == Event::KeyReleased) {
		player->handleEvent(e);
	}
}

void GameManager::update (Int32 tpf) {

	// move player / update bricks
	for (RectangleEntity *e: entities) {
		e->update(tpf);
	}

	player->update(tpf);
	ball->update(tpf);

	handleCollision();

}
void GameManager::draw() {
	// clear screen
	window.clear();

	// draw all entities
	for (RectangleEntity* p : this->entities) {
		p->draw(window);
	}

	player->draw(window);
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

	createBall(5, 10, 250);
}

void GameManager::createBall(float radius, int pc, float speed) {
	sf::Vector2u size = window.getSize();

	ball = new Ball(radius, pc, speed);
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

