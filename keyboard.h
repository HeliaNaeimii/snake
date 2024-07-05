#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>
#include <termios.h>


extern std::string Right_key  ;
extern std::string Left_key  ;
extern std::string Down_key  ;
extern std::string Up_key  ;
extern std::string Enter_key ;


class KeyBoard {
    public:
        std::string lap ();
        KeyBoard();
        ~KeyBoard();
        struct termios oldSettings;
        struct termios newSettings;

};

#endif