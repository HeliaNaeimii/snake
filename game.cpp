#include "game.h"
#include "food.h"
#include "g_obj.h"
#include "logger.h"
#include "setting.h"
#include "snake.h"
#include <vector>

Game::Game(Setting& setting, Logger& logger): 
setting(&setting),
logger(&logger){
    snakes = std::vector<Snake*>();
    foods = std::vector<Food*>();
}


std::vector<Snake*>* Game::get_snakes() {
    return  &snakes;
}

std::vector<Food*>* Game::get_foods() {
    return &foods;
}

Setting& Game::get_setting() const{
    return *setting;
}

void Game::mount(Snake* snake){
    snakes.push_back(snake);
}

void Game::mount(Food* food){
    foods.push_back(food);
}

std::vector<GObj*> Game::getGObjects(){
    std::vector<GObj*>* result = new std::vector<GObj*>() ;
    for(auto food: foods){
        result->push_back(food);
    }
    for(auto snake: snakes){
        result->push_back(snake);
    }
    return *result ;
}