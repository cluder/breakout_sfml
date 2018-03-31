/*
 * BaseEntity.h
 *
 *  Created on: 28.03.2018
 *      Author: core
 */

#ifndef RECTANGLEENTITY_H_
#define RECTANGLEENTITY_H_

#include <memory>
#include "SFML/Graphics.hpp"

using namespace sf;

// the base entity has a shape which it can draw
class RectangleEntity {
public:
	RectangleEntity(float w, float h)  {
		shape = RectangleShape(Vector2f(w, h));
	}

	virtual ~RectangleEntity();

	void draw(RenderTarget& target);
	virtual void update(Int32 tpf);

	void setColor(sf::Color c);
	void setPosition(float x, float y);
	Vector2f getPosition();
	RectangleShape getShape() {return shape;}

	void hit();
	int getHealth() {return health;}

private:
	RectangleShape shape;
	bool destroyed = false;

	int health = 2;
};


#endif /* RECTANGLEENTITY_H_ */
