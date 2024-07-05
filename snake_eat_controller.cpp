#include "snake_eat_controller.h"
#include "controller.h"
#include "game.h"

SnakeEatController::SnakeEatController(Game& game):Controller(game){}

void SnakeEatController::run(){
    bool loop0break = false;
    for(auto attackSnake: *(game->get_snakes())){
        if(!attackSnake->isAlive()) continue;
        bool loop1break = false;
        for(auto deffendSnake: *(game->get_snakes())){
            if(attackSnake == deffendSnake)continue;
            if(!deffendSnake->isAlive()) continue;
            auto attackerHead = attackSnake->get_head();
            bool loop2break = false;
            for(auto deffendBody: deffendSnake->get_body()){
                if(attackerHead->get_coordinates() == deffendBody->get_coordinates()){
                    attacked(attackSnake, deffendSnake);
                    loop2break = true;
                    loop1break = true;
                }
                if (loop2break){
                    break;
                }
            }
            if(loop1break){
                break;
            }
        }
        if(loop0break){
            break;
        }
    }
}

void SnakeEatController::attacked(Snake* attacker, Snake* deffender){
    if(attacker->len() >= deffender->len()){
        attacker->Feed(
            deffender->len()
        );
        deffender->die();
    }
}

std::string SnakeEatController::log(){
    return "Eat Controller";
}