/*
 * GameManager.h
 *
 *  Created on: 26.03.2018
 *      Author: core
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <vector>

#include "SFML/Graphics.hpp"
#include "Player.h"

using namespace sf;

class GameManager {
public:
	GameManager(RenderWindow &w);

	void update();
	void draw();
	void add(BaseEntity *e);

	void createEntities();

	virtual ~GameManager();

private:
	RenderWindow &window;
	Player *pplayer;
	std::vector<BaseEntity*> entities;

	Player* createPlayer();
};

#endif /* GAMEMANAGER_H_ */
