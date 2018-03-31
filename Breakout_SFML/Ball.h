/*
 * Ball.h
 *
 *  Created on: 30.03.2018
 *      Author: core
 */

#ifndef BALL_H_
#define BALL_H_

#include "SFML/Graphics.hpp"

using namespace sf;

class Ball {
public:
	Ball(int radius, int pointCount, float speed);
	void draw(RenderTarget& target);
	void update (Int32 tpf);
	void setPosition(float x, float y);

	virtual ~Ball();

	CircleShape getShape() {return shape;};
	float getXVelocity() {return xVelocity;};
	float getYVelocity() {return yVelocity;};
	void setXVelocity(float value) { xVelocity = value;}
	void setYVelocity(float value) { yVelocity = value;}

	float getMaxVel() {return maxVel;}
private:
	CircleShape shape;

	// current x/y velocity
	float xVelocity;
	float yVelocity;

	float maxVel = 500;
};


#endif /* BALL_H_ */

