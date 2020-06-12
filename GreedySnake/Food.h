#pragma once
#include "Point.h"
#include <deque>
using namespace std;
class Food
{
public:
	Food() {}
	void setFood(deque<Point> queue);
	void drawFood();
	void clearFood();
	Point* getPos() {
		return pos;
	}
private:
	Point* pos;
};

