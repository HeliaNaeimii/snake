#include "cli.h"
#include <iostream>
#include <string>

const std::string ESC = "\x1B";   
const std::string CSI = ESC + "[";

void ClearScreen() {
    std::cout << CSI << "2J";
}

void MoveCursor(int x, int y) {
    std::cout << CSI << y << ";" << x << "H";
}

std::string SetTextColor(int color, std::string text) {
    return  "38;5;" + std::to_string(color) + "m" + text + CSI + "0m";
}


int Color::GREEN = 46;
int Color::YELLOW = 226;
int Color::RED = 196;
int Color::BLUE = 21;
