#ifndef APPLICATION_H
#define APPLICATION_H

#include "coordinates.h"
#include "game.h"
#include "controller.h"
#include "logger.h"
#include "my_snake.h"
#include "random.h"
#include "ui.h"

class Application {
    private:
    bool running;
    Setting* setting;
    std::vector<Task*> tasks;
    Game* game;
    UI* ui;
    MySnake* mySnake;
    Random* random;
    Logger* logger;

    public:
    void mount(Task& task);
    void mount(Task* task);
    int loop();
    Application();
};

#endif