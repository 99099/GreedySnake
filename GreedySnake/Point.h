#pragma once
class Point
{
public:
	Point() {}
	Point(const int x, const int y) : x(x), y(y) {}
	void printSquare();
	void printCircle();
	void clear();
	void changePosition(const int x, const int y);
	bool operator== (const Point& point) {
		return this->x == point.x && this->y == point.y;
	}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
private:
	int x;
	int y;
};

