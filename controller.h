#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game.h"
#include "task.h"
class Controller: public Task{
    protected:
    Game* game;

    public:
    Controller(Game&);
    void run() override;
};

#endif