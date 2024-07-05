#include "page.h"
#include "frame.h"
#include "g_obj.h"
#include "game.h"
#include "now.h"
#include <string>
#include <vector>
#include <codecvt>
#include <locale>

Page::Page(Game& ui): game(&ui) {
    
}

std::vector<std::string> Page::render(){
    auto logger = get_game().logger;
    auto size = get_game().get_setting().size;
    std::vector<std::vector<char32_t>> matris (size.y+1, std::vector<char32_t>(size.x+1, U' '));

    for(auto pixel: render_frame()){
        logger->log(std::to_string(Now())+ " - " + "write pixel: ");
        matris[pixel.coordinates.y][pixel.coordinates.x] = pixel.ch;
    }
    std::vector<std::string> result;
    std::string LineExport;
    for(auto LineInput: matris){
        LineExport = "";
        for(auto UCH: LineInput){
            std::u32string u32str(1, UCH);
            std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
            std::string utf8str = converter.to_bytes(u32str);
            LineExport += utf8str;
        }
        result.push_back(LineExport);
    }
    return result;
}

Frame Page::render_frame() const{
    Frame* frame = new Frame();
    for(auto obj: get_game().getGObjects()){
        if(obj->isGOBJEnabled()){
            obj->set_setting(game->get_setting());
            auto childFrame = obj->render();
            frame->insert(childFrame);
        }
    }
    return *frame;
}

Game& Page::get_game() const {
    return *game;
}

