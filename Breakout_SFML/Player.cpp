/*
 * Player.cpp
 *
 *  Created on: 26.03.2018
 *      Author: core
 */

#include "Player.h"


Player::~Player() {

}

void Player::handleEvent(Event e) {

	if (e.key.code == Keyboard::Left) {
		if (e.type == Event::KeyPressed) {
			moveLeft = true;
		} else if (e.type == Event::KeyReleased){
			moveLeft = false;
		}
	}

	if (e.key.code == Keyboard::Right) {
		if (e.type == Event::KeyPressed) {
			moveRight = true;
		} else if (e.type == Event::KeyReleased){
			moveRight = false;
		}
	}
}

void Player::update(Int32 tpf) {
	if (tpf <= 0) {
		return;
	}
//	fprintf(stderr, "player update: left:%s right:%s tpf:%d  tpf/1000:%lf\n",
//			(moveLeft == true?"true": "false"),
//			(moveRight == true?"true": "false"), tpf, tpf/1000.0f);

	sf::Vector2f pos = getPosition();

	if (moveLeft == moveRight) {
		// player dosen't know where to go ...
		return;
	}

	float xVel = speed * (tpf/1000.0f);

	if (moveLeft) {
		xVel *= -1;
	}

//	fprintf(stderr, "player x vel:%f\n", xVel);

	setPosition(pos.x + xVel, pos.y);
}


