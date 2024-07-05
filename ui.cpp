#include "ui.h"
#include "game.h"
#include "page.h"
#include "task.h"
#include "cli.h"
#include <iostream>

UI::UI(Game& game):Task(1), game(&game) {
    constructor();
}
UI::UI(Game* game):Task(1), game(game) {
    constructor();
}
void UI::constructor(){
    page = new Page(*game);
    set_delay(100);
}
Game& UI::get_game() const {
    return  *game;
}
void UI::run(){
    ClearScreen();
    std::cout << std::endl;
    auto buffer = page->render();
    MoveCursor(0,0);
    for (auto line: buffer){
        std::cout << line << std::endl;
    }
}
std::string UI::log(){
    return "UI";
}