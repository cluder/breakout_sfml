/*
 * Player.h
 *
 *  Created on: 26.03.2018
 *      Author: core
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "SFML/Graphics.hpp"

#include "BaseEntity.h"

using namespace sf;

class Player : public BaseEntity {
public:
	Player(Shape &s);
	virtual ~Player();
private:

};

#endif /* PLAYER_H_ */
