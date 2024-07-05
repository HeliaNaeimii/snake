#include <cstdlib>
#include <ctime>
#include "snake_ai_controller.h"
#include "snake.h"
#include "snake_controller.h"

SnakeAIController::SnakeAIController(Snake& snake):SnakeController(snake){
    constructor();
}
SnakeAIController::SnakeAIController(Snake* snake):SnakeController(snake){
    constructor();
}
void SnakeAIController::constructor(){
    state = 0;
    std::srand(std::time(0));
}
void SnakeAIController::run(){
    if(state == 0){
        state = 1;
        return;
    }
    state = 0;

    float random = std::rand()%3;
    if(random>1){
        snake->TurnLeft();
    }else if(random>2){
        snake->TurnRight();
    }
}
std::string SnakeAIController::log(){
    return "Snake AI Controller";
}