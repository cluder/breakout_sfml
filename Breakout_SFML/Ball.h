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

//	float getSpeed() {return speed;}
//	void setSpeed(float value) {speed = value;}

	CircleShape getShape() {return shape;};
	float getXVelocity() {return xVelocity;};
	float getYVelocity() {return yVelocity;};
	void setXVelocity(float value) { xVelocity = value;}
	void setYVelocity(float value) { yVelocity = value;}
private:
	CircleShape shape;

	// initial speed
//	float speed;
	// current x/y velocity
	float xVelocity;
	float yVelocity;
};


#endif /* BALL_H_ */

