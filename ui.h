#ifndef UI_H
#define UI_H
#include "page.h"
#include "task.h"
#include "game.h"

class UI: public Task{
    protected:
    Game* game;
    Page* page;
    void constructor();
    public:
    void run() override;
    UI(Game& game);
    UI(Game* game);
    Game& get_game() const;
    std::string log() override;
};

#endif