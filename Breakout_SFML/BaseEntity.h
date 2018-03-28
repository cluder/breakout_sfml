/*
 * BaseEntity.h
 *
 *  Created on: 28.03.2018
 *      Author: core
 */

#ifndef BASEENTITY_H_
#define BASEENTITY_H_

#include "SFML/Graphics.hpp"

using namespace sf;

class BaseEntity : public Drawable {
public:
	BaseEntity(Shape &s);
	virtual ~BaseEntity();

	// implements Drawable
	void draw(RenderTarget& target, RenderStates states) const;

	void setPosition(float x, float y);
	Vector2f getPosition();

	Shape &shape;
private:
};


#endif /* BASEENTITY_H_ */
