#ifndef FOOD_CONTROLLER_H
#define  FOOD_CONTROLLER_H

#include "controller.h"
#include "food.h"
#include "game.h"
#include "random.h"
#include "snake.h"
#include <string>
class FoodController:public Controller{
    private:
    void Eated(Snake* snake, Food* food);
    Random random;

    public:
    FoodController(Game&);
    void run() override;
    std::string log() override;
};

#endif