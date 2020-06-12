#include "tools.h"
#include <Windows.h>

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void setCursorPosition(int x, int y) {
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void setColor(int colorId) {
	SetConsoleTextAttribute(handle, colorId);
}

void setBackgroundColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE |
		BACKGROUND_BLUE |
		BACKGROUND_GREEN |
		BACKGROUND_RED);
}