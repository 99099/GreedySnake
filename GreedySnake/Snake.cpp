#include "Snake.h"
#include "tools.h"
#include "GameInterface.h"
#include <conio.h>

void Snake::drawSnake() {
	setColor(2);
	for (int i = 0; i < this->snake.size(); ++i) {
		this->snake[i].printSquare();
	}
}

void Snake::clearSnake() {
	for (int i = 0; i < this->snake.size(); ++i) {
		this->snake[i].clear();
	}
}

void Snake::move() {
	clearSnake();
	int x = this->snake[0].getX();
	int y = this->snake[0].getY();
	switch (this->direction)
	{
	case UP:
		--y;
		this->snake.pop_back();
		if (y < 1)
		{
			y = WIN_HEIGHT - 1;
		}
		this->snake.emplace_front(x, y);
		break;
	case DOWN:
		++y;
		this->snake.pop_back();
		if (y > WIN_HEIGHT - 1) 
		{
			y = 1;
		}
		this->snake.emplace_front(x, y);
		break;
	case LEFT:
		--x;
		this->snake.pop_back();
		if (x < 1)
		{
			x = WIN_WIDTH - 1;
		}
		this->snake.emplace_front(x, y);
		break;
	case RIGHT:
		++x;
		this->snake.pop_back();
		if (x > WIN_WIDTH - 1)
		{
			x = 1;
		}
		this->snake.emplace_front(x, y);
		break;
	default:
		break;
	}
	drawSnake();
}

void Snake::getFood(Food *food) 
{
	if (*food->getPos() == this->snake[0])
	{
		food->setFood(this->snake);
		food->drawFood();
		int size = this->snake.size();
		if (this->snake[size - 1].getX() == this->snake[size - 2].getX()) 
		{
			int diff = this->snake[size - 1].getX() - this->snake[size - 2].getX();
			this->snake.emplace_back(this->snake[size - 1].getX() + diff, this->snake[size - 1].getY());
		}
		else if(this->snake[size - 1].getY() == this->snake[size - 2].getY()) 
		{
			int diff = this->snake[size - 1].getY() - this->snake[size - 2].getY();
			this->snake.emplace_back(this->snake[size - 1].getX(), this->snake[size - 1].getY() + diff);
		} 
		else
		{
			switch (this->direction)
			{
			case Direction::UP:
				this->snake.emplace_back(this->snake[size - 1].getX(), this->snake[size - 1].getY() + 1);
				break;
			case Direction::DOWN:
				this->snake.emplace_back(this->snake[size - 1].getX(), this->snake[size - 1].getY() - 1);
				break;
			case Direction::RIGHT:
				this->snake.emplace_back(this->snake[size - 1].getX() - 1, this->snake[size - 1].getY());
				break;
			case Direction::LEFT:
				this->snake.emplace_back(this->snake[size - 1].getX() + 1, this->snake[size - 1].getY());
				break;
			default:
				break;
			}
		}
		drawSnake();
	}
}

void Snake::changeDirection() {
	char ch;
	if (_kbhit()) {
		ch = _getch();
		if (ch == -32) 
		{
			ch = _getch();
			switch (ch)
			{
			case 72:
				if (this->direction != Direction::DOWN) {
					this->direction = Direction::UP;
				}
				break;
			case 80:
				if (this->direction != Direction::UP)
				{
					this->direction = Direction::DOWN;
				}
				break;
			case 75:
				if (this->direction != Direction::RIGHT) {
					this->direction = Direction::LEFT;
				}
				break;
			case 77:
				if (this->direction != Direction::LEFT) {
					this->direction = Direction::RIGHT;
				}
				break;
			default:
				break;
			}
		}
	}
}