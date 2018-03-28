/*
 * BaseEntity.cpp
 *
 *  Created on: 28.03.2018
 *      Author: core
 */

#include "BaseEntity.h"


BaseEntity::BaseEntity(Shape &s)
	: shape(s)
{

}

BaseEntity::~BaseEntity() {

}

// moves the shape
void BaseEntity::setPosition(float x, float y) {
	shape.setPosition(x, y);
}

Vector2f BaseEntity::getPosition() {
	return shape.getPosition();
}

void BaseEntity::draw(RenderTarget& target, RenderStates states) const {
	target.draw(shape);
}
