#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include "snake.h"
#include "task.h"
class SnakeController: public Task {
    protected:
    Snake* snake;
    public:
    SnakeController(Snake&);
    SnakeController(Snake*);
    Snake get_snake() const;
    void run() override;
};

#endif