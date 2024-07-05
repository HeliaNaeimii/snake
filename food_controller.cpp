#include "food_controller.h"
#include "controller.h"
#include "food1.h"
#include "game.h"
#include "random.h"
#include "setting.h"
#include <string>

void FoodController::run(){
    auto foods = *(game->get_foods());
    auto snakes = *(game->get_snakes());
    for(auto food: foods) {
        if(!food->isEnable()) continue;
        for(auto snake: snakes){
            if(food->get_coordinates()==snake->get_head()->get_coordinates()){
                this->Eated(snake, food);
                break;
            }
        }
    }

    auto foods_ptr = game->get_foods();

    for (auto food_iter = foods.begin(); food_iter<foods.end(); food_iter++ ){
        auto food = *food_iter;
        if(!food->isEnable()){
            foods_ptr->erase(food_iter);
        }
    }

    if (foods_ptr->size() < 1){
        foods_ptr->push_back(random.randomFood());
    }
}

void FoodController::Eated(Snake* snake, Food* food){
    if(food->nitrogen()){
        snake->Nitrogen();
    }
    snake->Feed(
        food->len()
    );
    food->disable();
}


FoodController::FoodController(Game& game):
Controller(game),
random(game.get_setting()) {
    set_delay(250);
}

std::string FoodController::log(){
    return "Food Controller";
}