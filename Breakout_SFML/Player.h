/*
 * Player.h
 *
 *  Created on: 26.03.2018
 *      Author: core
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "SFML/Graphics.hpp"

#include "RectangleEntity.h"

using namespace sf;

class Player : public RectangleEntity {
public:
	Player(float w, float h) :
		RectangleEntity(w, h), speed(0), moveLeft(false), moveRight(false)
{ };
	void handleEvent(sf::Event event);
	void update(Int32 tpf);
	void setSpeed(float value) {speed = value;};
	virtual ~Player();
private:
	float speed;
	bool moveLeft;
bool moveRight;
};

#endif /* PLAYER_H_ */
