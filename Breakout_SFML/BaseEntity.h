/*
 * BaseEntity.h
 *
 *  Created on: 28.03.2018
 *      Author: core
 */

#ifndef BASEENTITY_H_
#define BASEENTITY_H_

#include <memory>
#include "SFML/Graphics.hpp"

using namespace sf;

// the base entity has a shape which it can draw
class BaseEntity {
public:
	BaseEntity(float w, float h)  {
		shape = RectangleShape(Vector2f(w, h));
	}

	virtual ~BaseEntity();

	// implements Drawable
	void draw(RenderTarget& target, RenderStates states);

	void setColor(sf::Color c);

	void setPosition(float x, float y);
	Vector2f getPosition();

	RectangleShape shape;
private:
};


#endif /* BASEENTITY_H_ */
