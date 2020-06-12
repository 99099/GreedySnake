#pragma once
#include "Point.h"
class Food
{
public:
	Food() {}
	void setFood();
	void drawFood();
	void clearFood();
	Point* getPos() {
		return pos;
	}
private:
	Point* pos;
};

