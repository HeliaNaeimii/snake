#include <string>
void ClearScreen();
std::string SetTextColor(int color);
void MoveCursor(int x, int y);
class Color{
    static int GREEN;
    static int YELLOW;
    static int BLUE;
    static int RED;
};