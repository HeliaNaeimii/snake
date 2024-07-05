#include "snake_user_controller.h"
#include "keyboard.h"
#include "snake.h"
#include "snake_controller.h"

SnakeUserController::SnakeUserController(Snake& snake):
SnakeController(snake){
    constructor();
}
SnakeUserController::SnakeUserController(Snake* snake): 
SnakeController(snake){
    constructor();
}
void SnakeUserController::constructor(){
    keyboard = new KeyBoard();
}
void SnakeUserController::run(){
    auto key = keyboard->lap();
    if(key==Left_key){
        snake->TurnLeft();
    }else if(key==Right_key){
        snake->TurnRight();
    }
}
std::string SnakeUserController::log(){
    return "Snake User Controller";
}