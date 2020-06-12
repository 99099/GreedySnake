#pragma once
#include <deque>
#include "Point.h"
#include "Food.h"
using namespace std;
class Snake
{
public:
	enum Direction
	{
		UP, DOWN, LEFT, RIGHT
	};
	Snake() 
	{
		snake.emplace_back(6, 6);
		snake.emplace_back(5, 6);
		snake.emplace_back(4, 6);
		this->direction = Direction::RIGHT;
	}

	void drawSnake();
	void clearSnake();
	void move();
	void getFood(Food *food);
	void changeDirection();
	deque<Point> getSnake() {
		return this->snake;
	}
private:
	deque<Point> snake;
	Direction direction;
};

