#ifndef GAME_H
#define GAME_H
#include "food.h"
#include "g_obj.h"
#include "logger.h"
#include "snake.h"
#include "setting.h"
#include <vector>

class Game {
    private:
    Setting* setting;
    std::vector<Snake*> snakes;
    std::vector<Food*> foods;
    public:
    Logger* logger;
    Game(Setting& setting, Logger& logger);
    Setting& get_setting() const;
    std::vector<Snake*>* get_snakes() ;
    std::vector<Food*>* get_foods() ;
    void mount(Snake* snake);
    void mount(Food* food);
    std::vector<GObj*> getGObjects();
};

#endif