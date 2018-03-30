/*
 * BaseEntity.cpp
 *
 *  Created on: 28.03.2018
 *      Author: core
 */

#include "RectangleEntity.h"


RectangleEntity::~RectangleEntity() {

}

// moves the shape
void RectangleEntity::setPosition(float x, float y) {
	shape.setPosition(x, y);
}

void RectangleEntity::setColor(sf::Color c) {
	shape.setFillColor(c);
}

Vector2f RectangleEntity::getPosition() {
	return shape.getPosition();
}

void RectangleEntity::draw(RenderTarget& target) {
	target.draw(shape);
}
