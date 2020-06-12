#include "GameInterface.h"
#include "tools.h"
#include "Point.h"
#include <Windows.h>

void GameInterface::drawInterface() {
	system("title ̰����");
	setColor(5);
	Point* p = new Point(0, 0);
	/*
		�����������еĹ��
	*/
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	//������Ϸ����
	for (unsigned int i = 0; i <= WIN_HEIGHT; i++)
	{
		p->changePosition(0, i);
		p->printSquare();
		p->changePosition(WIN_WIDTH, i);
		p->printSquare();
	}
	for (unsigned int i = 1; i <= WIN_WIDTH - 1; i++) {
		p->changePosition(i, 0);
		p->printSquare();
		p->changePosition(i, WIN_HEIGHT);
		p->printSquare();
	}
}
