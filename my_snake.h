#ifndef MY_SNAKE_H
#define MY_SNAKE_H

#include "coordinates.h"
#include "snake.h"
class MySnake: public Snake {
    public:
    MySnake(Coordinates coord, int num);
};

#endif