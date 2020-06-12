#include "Food.h"
#include "GameInterface.h"
#include "tools.h"
#include <cstdlib>

void Food::setFood() {
	if (!this->pos)
	{
		this->pos = new Point();
	}
	int x = rand() % WIN_WIDTH;
	int y = rand() % WIN_HEIGHT;
	this->pos->changePosition(x, y);
}

void Food::drawFood() {
	setColor(1);
	this->pos->printCircle();
}

void Food::clearFood() {
	this->pos->clear();
}
