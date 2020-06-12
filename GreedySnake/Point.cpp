#include "Point.h"
#include "tools.h"
#include <iostream>

void Point::printSquare() {
	setCursorPosition(this->x, this->y);
	std::cout << "¡ö";
}

void Point::printCircle() {
	setCursorPosition(this->x, this->y);
	std::cout << "¡ñ";
}

void Point::clear() {
	setCursorPosition(this->x, this->y);
	std::cout << "  ";
}

void Point::changePosition(const int x, const int y) {
	this->x = x;
	this->y = y;
}