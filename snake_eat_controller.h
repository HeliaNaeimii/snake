#ifndef SNAKE_EAT_CONTROLLER_H
#define SNAKE_EAT_CONTROLLER_H

#include "controller.h"
#include "game.h"
#include "snake.h"
class SnakeEatController: public Controller{
    private:
    void attacked(Snake* attacker, Snake* deffender);
    public:
    SnakeEatController(Game& game);
    void run() override;
    std::string log() override;
};

#endif