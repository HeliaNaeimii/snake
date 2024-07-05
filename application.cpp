#include "application.h"
#include "food_controller.h"
#include "game.h"
#include "my_snake.h"
#include "random.h"
#include "setting.h"
#include "sleep.h"
#include "now.h"
#include "iostream"
#include "snake_ai_controller.h"
#include "snake_eat_controller.h"
#include "snake_user_controller.h"
#include "task.h"

Application::Application() {
    running = true;
    std::cout << "Lets go eating no deligious snakes" << std::endl;
    int xSize, ySize, enemyNum;
    std::cout<<"Enter x size: ";
    std::cin >> xSize;
    std::cout<<"Enter y size: ";
    std::cin >> ySize;
    std::cout<<"Enter enemies num: ";
    std::cin >> enemyNum;


    setting = new Setting(xSize, ySize, enemyNum);
    logger = new Logger("./game.log");
    random = new Random(*setting);
    game = new Game(*setting, *logger);
    ui = new UI(game);
    mount(
        ui
    );
    mount(
        new FoodController(*game)
    );
    mount(
        new SnakeEatController(*game)
    );
    mySnake = new MySnake(*random->randomCoordinates(), 3);
    mount(
        mySnake
    );
    game->mount(
        mySnake
    );
    mount(
        new SnakeUserController(
            mySnake
        )
    );

    for(int i=0; i<setting->enemies; i++){
        Snake* enemy = new Snake(*random->randomCoordinates(),3);
        mount(
            enemy
        );
        game->mount(
            enemy
        );
        mount(
            new SnakeAIController(enemy)
        );
    }

}

int Application::loop(){
    while(running){
        for (auto task : tasks){
            if (Now()-task->get_lastRun()>task->get_delay()){
                logger->log(
                    std::to_string(Now()) +
                    " - " +
                    task->log()
                );
                task->set_lastRun(Now());
                task->run();
            }
        }
        sleep(50);
    }
    return 0;
}

void Application::mount(Task* task){
    tasks.push_back(task);
}
void Application::mount(Task& task){
    tasks.push_back(&task);
}

