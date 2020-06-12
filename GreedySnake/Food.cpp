#include "Food.h"
#include "GameInterface.h"
#include "tools.h"
#include <cstdlib>

void Food::setFood(deque<Point> queue) {
	if (!this->pos)
	{
		this->pos = new Point();
	}
	int x, y;
	bool flag = false;
	while (!flag) {
		flag = true;
		x = rand() % (WIN_WIDTH - 1) + 1;
		y = rand() % (WIN_HEIGHT - 1) + 1;
		for (unsigned int i = 0; i < queue.size(); ++i)
		{
			Point p = queue[i];
			if (x == p.getX() && y == p.getY())
			{
				flag = false;
			}
		}
	}
	this->pos->changePosition(x, y);
}

void Food::drawFood() {
	setColor(1);
	this->pos->printCircle();
}

void Food::clearFood() {
	this->pos->clear();
}
