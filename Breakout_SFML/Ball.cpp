/*
 * Ball.cpp
 *
 *  Created on: 30.03.2018
 *      Author: core
 */

#include "Ball.h"


Ball::Ball(int radius, int pointCount, float speed) :
		//speed(speed),
		xVelocity(speed*0.8), yVelocity(speed*1.2), maxVel(500)
{
	shape = CircleShape(radius, pointCount);
}

void Ball::update(Int32 tpf) {

	// calc current movement per frame
	float xVel = xVelocity * (tpf / 1000.0f);
	float yVel = yVelocity * (tpf / 1000.0f);

	const sf::Vector2f pos = shape.getPosition();

	shape.setPosition(pos.x + xVel, pos.y + yVel);

}

void Ball::setPosition(float x, float y) {
	shape.setPosition(x, y);
}

void Ball::draw(RenderTarget& target) {
	target.draw(shape);
}

Ball::~Ball() {
}

