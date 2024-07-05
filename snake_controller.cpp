#include "snake_controller.h"
#include "snake.h"
SnakeController::SnakeController(Snake* snake): snake(snake){}
SnakeController::SnakeController(Snake& snake): snake(&snake){}
void SnakeController::run(){}