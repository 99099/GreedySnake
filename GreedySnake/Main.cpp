#include <Windows.h>
#include <iostream>
#include "GameInterface.h"
#include "Food.h"
#include "Snake.h"
int main()
{
    GameInterface::drawInterface();
    Food* food = new Food();
    Snake* snake = new Snake();
    food->setFood(snake->getSnake());
    food->drawFood();
    snake->drawSnake();
    while (true) {
        snake->changeDirection();
        snake->move();
        snake->getFood(food);
        Sleep(200);
    }
}
