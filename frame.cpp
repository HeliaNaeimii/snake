#include "frame.h"
#include "pixel.h"
#include <vector>

void Frame::insert(Frame inp) {
    for (auto pixel : inp) {
        insert(pixel);
    }
}

void Frame::insert(Pixel inp) {
    int i = 0;
    for (auto pixel : *this) {
        if (inp.coordinates == pixel.coordinates) {
            this->erase(this->begin() + i);
            break;
        }
        i++;
    }
    this->push_back(inp);
}
