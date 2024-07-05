#ifndef SNAKE_AI_CONTROLLER_H
#define SNAKE_AI_CONTROLLER_H

#include "keyboard.h"
#include "snake.h"
#include "snake_controller.h"
#include <string>
class SnakeAIController:public SnakeController {
    private:
    int state;
    void constructor();
    public:
    SnakeAIController(Snake*);
    SnakeAIController(Snake&);
    void run() override;
    std::string log() override;
};

#endif