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
#include "Ball.h"
#include "RectangleEntity.h"

using namespace sf;

class GameManager {
public:
	GameManager(RenderWindow &w);

	void update(Int32 tpf);
	void draw();
	void handleEvent(Event &e);

	void handleCollision();

	void createEntities();

	virtual ~GameManager();

private:
	RenderWindow &window;
	Player *player;
	Ball *ball;
	std::vector<RectangleEntity*> entities;

	Player* createPlayer();
	void createBricks(int cols, int rows, float spacing, float brickHeight);
	void createBall(float radius, int pc);
};

#endif /* GAMEMANAGER_H_ */
