#include "keyboard.h"
#include <string>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>



std::string Right_key = "\033[C" ;
std::string Left_key = "\033[D" ;
std::string Down_key = "\033[B" ;
std::string Up_key = "\033[A" ;
std::string Enter_key = "\n";


std::string KeyBoard::lap(){
    std::string key = "" ;
    char letter ;
    while (read(STDIN_FILENO, &letter, 1) > 0){
        key += letter;
    }
    return key;
}


KeyBoard::KeyBoard(){
    struct termios old__Settings, new__Settings;
    this->oldSettings = old__Settings;
    this->newSettings = new__Settings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

KeyBoard::~KeyBoard(){
    tcsetattr(STDIN_FILENO, TCSANOW, &this->oldSettings);
}
