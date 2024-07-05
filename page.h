#ifndef PAGE_H
#define PAGE_H

#include "frame.h"
#include "g_obj.h"
#include "game.h"
#include <string>
class Page {
    private:
    Game* game;
    protected:
    virtual Frame render_frame() const;
    public:
    virtual std::vector<std::string> render();
    Page(Game& game);
    Game& get_game() const;
};

#endif