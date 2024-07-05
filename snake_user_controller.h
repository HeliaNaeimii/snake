#ifndef SNAKE_USER_CONTROLLER_H
#define SNAKE_USER_CONTROLLER_H

#include "keyboard.h"
#include "snake_controller.h"
#include <string>
class SnakeUserController:public SnakeController {
    private:
    KeyBoard* keyboard;
    void constructor();
    public:
    SnakeUserController(Snake*);
    SnakeUserController(Snake&);
    void run() override;
    std::string log() override;
};

#endif